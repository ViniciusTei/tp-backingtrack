#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Inimigos {
  U, T, S, B, G
} Inimigos;

typedef struct Personagem {
  int p;
  int k;
  char name;
} Personagem;


typedef struct ListaInimigos {
  Personagem inimigos[8];
  Personagem Ness;
  int primeiro, ultimo;
} ListaInimigos;


void iniciaListaInimigos(ListaInimigos *lista);
void imprimeListaInimigos(ListaInimigos lista);
