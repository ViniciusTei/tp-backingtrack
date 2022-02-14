#include "../../include/movimenta/movimenta.h"
#include "../../include/core/lerArquivo.h"

int main(void) {
  ListaPersonagens personagens;
  Mapa mapa;

  int controle = lerArquivo("entrada.txt", &personagens, &mapa);

  if (controle == 1) {
    imprimeNessStatus(personagens.Ness);
    imprimeListaInimigos(personagens);
    imprimeMapa(mapa);
  
  } else {
    red();
    printf("\nErro na leitura\n");
    reset();
  }  

  movimenta(&mapa, &personagens);
  
  return 0;
}