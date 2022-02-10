#include "../../include/movimenta/movimenta.h"

int main(void) {
  ListaPersonagens personagens;
  Mapa mapa;
  char mapTest[7][10] = {
    {'U', '-', '+', '.', '.', '.', '+', '-', '-', '+'},
    {'|', '.', '@', '.', '.', '.', '|', '.', '.', '|'},
    {'+', '-', '+', '-', 'U', '-', '+', '.', '.', 'S'},
    {'|', '.', '|', '.', '.', '.', 'B', '.', '.', '|'},
    {'S', '.', '|', '.', '.', '.', 'G', 'S', '-', '+'},
    {'|', '.', '|', '.', '.', '.', '.', '.', '.', '|'},
    {'+', '-', 'T', '-', '-', '-', '-', '-', '-', '+'},
  };

  iniciaListaInimigos(&personagens);
  // U, T, S, B e G.
  //ReadFile("entrada.txt", &inimigos);
  // imprimeListaInimigos(inimigos);
  iniciaNess(&personagens, 20, 2);
  //imprimeNessStatus(personagens.Ness);
  iniciaMonstro(&personagens, 10, 5, 0);
  iniciaMonstro(&personagens, 25, 10, 1);
  iniciaMonstro(&personagens, 30, 15, 2);
  iniciaMonstro(&personagens, 40, 20, 3);
  iniciaMonstro(&personagens, 80, 0, 4);
  //imprimeListaInimigos(personagens);

  // luta(&personagens, 'T');
  // imprimeNessStatus(personagens.Ness);

  iniciaMapa(&mapa, 7, 10);

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 10; j++) {
      mapa.mapa[i][j] = mapTest[i][j];
    }
  }
  
  imprimeMapa(mapa);

  movimenta(&mapa, &personagens);
  
  return 0;
}