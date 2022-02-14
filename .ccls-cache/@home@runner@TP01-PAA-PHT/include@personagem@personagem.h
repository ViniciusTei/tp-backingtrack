#ifndef PERSONAGEM
#define PERSONAGEM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_INIMIGOS 5

enum Inimigos {
  U, T, S, B, G
};

typedef struct Personagem {
  int p;
  int k;
  char name;
} PersonagemData;


typedef struct ListaPersonagens {
  PersonagemData inimigos[8];
  int primeiroInimigo, ultimoInimigo;
  
  PersonagemData Ness;
} ListaPersonagens;


void iniciaListaInimigos(ListaPersonagens *lista);
void imprimeListaInimigos(ListaPersonagens lista);
void iniciaMonstro(ListaPersonagens *lista, int P, int K, int Monstro);
void iniciaMonstroData(ListaPersonagens *lista, int P, int K, char nome);
void iniciaNess(ListaPersonagens *lista, int P, int K);
void imprimeNessStatus(PersonagemData Ness);
char* retornaNomeInimigo(char inicial);

#endif
