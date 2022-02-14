#include "../../include/core/lerArquivo.h"

void RemoveChar(char* str, char c) {
    char *pr= str, *pw = str;

    while(*pr)
    {
        *pw = *pr++;
        pw += (*pw != c);
    }

    *pw = '\0';
}

int lerArquivo(char* file_name, ListaPersonagens *personagens, Mapa *mapa) {
  FILE *file;
  char linha[100], *pLinha, *pChar;
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
      int altura, largura, indexAltura = 0, indexLargura = 0;

      fscanf(file, "%d %d", &altura, &largura);
      
      iniciaMapa(mapa, altura, largura);
    
      do {
        pLinha = fgets(linha, sizeof(linha), file);

        // remove qualquer string q nao seja do tamanho correto do mapa
        // deve estar aqui pq na leitura estava ocorrendo de aparecer
        // strings vazias que atrapalhavam a inicializacao do mapa
        if (strlen(pLinha) < largura) { 
          continue;
        }
        
        for(indexLargura = 0; indexLargura < largura; indexLargura++) {
          defineCharNaPosicao(mapa, pLinha[indexLargura], indexAltura, indexLargura);
        }
        
        indexAltura++;
      }while(indexAltura < altura);
      

      return 1;

    }
  return 0;
}