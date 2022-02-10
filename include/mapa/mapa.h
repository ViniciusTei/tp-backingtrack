#ifndef MAPA
#define MAPA

#include <stdio.h>
#include <stdlib.h>

typedef struct Mapa {
  char **mapa;
  int altura;
  int largura;
} Mapa;


void iniciaMapa(Mapa *mapa, int A, int L);
void imprimeMapa(Mapa mapa);
int defineCharNaPosicao(Mapa *mapa, char ch, int x, int y);
char getPosicao(Mapa mapa, int x, int y);

#endif