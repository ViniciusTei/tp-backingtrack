#include "../../include/movimenta/movimenta.h"
#include "../../include/core/lerArquivo.h"

int main(void) {
  ListaPersonagens personagens;
  Mapa mapa;
  Analise variaveis_analise;
  Posicao posicaoInicial;

  variaveis_analise.auxNivelMaximoRecursao = 0;
  variaveis_analise.chamadasRecursivas = 0;
  variaveis_analise.nivelMaximoRecursao = 0;

  int controle = lerArquivo("entrada.txt", &personagens, &mapa);
  
  if (controle != 1) {
    red();
    printf("\nErro na leitura\n");
    reset();
  } 

  movimenta(&mapa, &personagens, &variaveis_analise);

  sleep(2);
  yellow();
  printf("\n\nResultados da analise\n");
  printf("Chamadas recursivas: %d\n", variaveis_analise.chamadasRecursivas);
  printf("Nivel maximo da recursao: %d\n", variaveis_analise.nivelMaximoRecursao);
  reset();
  
  return 0;
}