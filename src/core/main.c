#include "../../include/core/lerArquivo.h"
#include "../../include/movimenta/movimenta.h"

int main(int argc, char **argv) {
  ListaPersonagens personagens;
  Mapa mapa;
  Posicao posicaoInicial;
  
  iniciaArgumentosAnalise(&variaveis_analise, &argumentos, argc, argv);

  int controle = lerArquivo(argumentos.nome_arquivo, &personagens, &mapa);
  
  if (controle != 1) {
    red();
    printf("\nErro na leitura\n");
    reset();
    return 0;
  }

  // calcula tempo de execucao do programa 
  time(&tempo_inicio);
  movimenta(&mapa, &personagens, &variaveis_analise);
  time(&tempo_fim);
  tempo_gasto = tempo_fim - tempo_inicio;

  if (argumentos.MODO_ANALISE == 1) {
    imprimeAnalise();
  }

  printf("\n");
  
  return 0;
}