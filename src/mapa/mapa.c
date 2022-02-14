#include "../../include/mapa/mapa.h"

void iniciaMapa(Mapa *mapa, int A, int L) {
  mapa->altura = A;
  mapa->largura = L;
  mapa->mapa = (char**) malloc(sizeof(char*)*A);

  for (int i = 0; i < A; i++) {
    mapa->mapa[i] = (char*) malloc(sizeof(char)*L);

    for (int j = 0; j < L; j++) {
      mapa->mapa[i][j] = '.';
    }
  }

}

void imprimeMapa(Mapa mapa) {
  printf("\n");
  for (int i = 0; i < mapa.altura; i++) {
    for (int j = 0; j < mapa.largura; j++) {
      printf("%c ", mapa.mapa[i][j]);
    }
    printf("\n");
  }
}

int defineCharNaPosicao(Mapa *mapa, char ch, int x, int y) {
  if (x < 0 || y < 0) {
    return -1;
  }

  if (x > mapa->altura || y > mapa->largura) {
    return -1;
  }

  mapa->mapa[x][y] = ch;
  return 1;
}

char getPosicao(Mapa mapa, int x, int y) {
  if (x < 0 || y < 0) {
    return -1;
  }

  if (x > mapa.altura || y > mapa.largura) {
    return -1;
  }

  return mapa.mapa[x][y];
}