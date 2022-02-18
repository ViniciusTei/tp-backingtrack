#ifndef MAPA
#define MAPA

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../colors/colors.h"

#define TRUE 1
#define FALSE 0

typedef struct DadosMapa {
  char ch;
  int enable;
} DadosMapa;

typedef struct Mapa {
  DadosMapa **mapa;
  int altura;
  int largura;
  int xNess;
  int yNess;
} Mapa;


void iniciaMapa(Mapa *mapa, int A, int L);
void imprimeMapa(Mapa mapa);
int defineCharNaPosicao(Mapa *mapa, char ch, int x, int y);
char getPosicao(Mapa mapa, int x, int y);
void atribuiPosicaoNess(Mapa *mapa, int xNess, int yNess);
void mapaGrafico(Mapa mapa);

#endif