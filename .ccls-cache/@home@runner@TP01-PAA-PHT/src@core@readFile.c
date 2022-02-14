#include "../../include/core/readFile.h"

void RemoveChar(char* str, char c) {
    char *pr= str, *pw = str;

    while(*pr)
    {
        *pw = *pr++;
        pw += (*pw != c);
    }

    *pw = '\0';
}

int ReadFile(char* file_name, ListaPersonagens *personagens, Mapa *mapa) {
  FILE *file;
  char *linha, *pLinha, *pChar;
  int P, K;
  file = fopen(file_name, "r");
  
  int fileCurrentLine = 0;

  if(file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    else
    {
      // ler dados do ness
      fscanf(file, "%d %d", &P, &K);
      iniciaNess(personagens, P, K);

      //ler dados dos inimigos
      for (int i = 0; i < NUM_INIMIGOS; i++) {
        
        fscanf(file, "%d %d", &P, &K);
        iniciaMonstro(personagens, P, K, i);
      }

      //ler os dados do mapa
      int altura, largura, indexAltura, indexLargura;

      fscanf(file, "%d %d", &altura, &largura);
      
      iniciaMapa(mapa, altura, largura);
      
      linha = fgets(linha, sizeof(linha), file);

      while(linha != NULL) {
        for(indexLargura = 0; indexLargura < strlen(linha); indexLargura++) {
          defineCharNaPosicao(mapa, linha[indexLargura], indexAltura, indexLargura);
        }

        //pega proxima linha
        linha = fgets(linha, sizeof(linha), file);
        indexAltura++;
      }
      

      return 1;

    }
  return 0;
}