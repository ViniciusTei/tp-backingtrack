#include "../../include/core/analise.h"

void iniciaArgumentosAnalise(Analise *analise, Argumentos *args, int argc, char **argv) {
  analise->auxNivelMaximoRecursao = 0;
  analise->chamadasRecursivas = 0;
  analise->nivelMaximoRecursao = 0;

  // verifica itens passados como argumentos para
  // iniciar os modos do programa
  // como default iniciamos com 0, caso algum argumento
  // tiver sido passado nos alteramos os valroes dos controles
  args->MODO_VISUALIZACAO = 0;
  args->MODO_ANALISE = 0;
  args->nome_arquivo = NULL;
  
  if (argc > 0) {
    for (int i = 0; i < argc; i++) {
      if (strcmp(argv[i], "--watch") == 0 || strcmp(argv[i], "--assistir") == 0) {
        args->MODO_VISUALIZACAO = 1;
      }

      if (strcmp(argv[i], "--debug") == 0 || strcmp(argv[i], "--analise") == 0) {
        args->MODO_ANALISE = 1;
      }

      if (strcmp(argv[i], "--file") == 0 || strcmp(argv[i], "--arquivo") == 0) {
        args->nome_arquivo = (char*) malloc(sizeof(argv[i+1]));
        strcpy(args->nome_arquivo, argv[i+1]);
      }
    }
  }

  if (args->nome_arquivo == NULL) {
    args->nome_arquivo = (char*) malloc(sizeof("entrada.txt"));
    strcpy(args->nome_arquivo , "entrada.txt");
  }
}

void imprimeAnalise() {
  sleep(1);
  yellow();
  printf("\n\nResultados da analise\n");
  printf("Chamadas recursivas: %d\n", variaveis_analise.chamadasRecursivas);
  printf("Nivel maximo da recursao: %d\n", variaveis_analise.nivelMaximoRecursao);
  printf("Tempo de execucao: %.2fs\n", tempo_gasto);
  reset();
}