#ifndef  MOVIMENTA
#define MOVIMENTA

#include "../mapa/mapa.h"
#include "../luta/luta.h"

typedef struct Posicao {
  int x;
  int y;
} Posicao;

void encontraPosicaoInicial(Mapa *mapa, Posicao *posicaoEncontrada);
void movimenta(Mapa *mapa, ListaPersonagens *personagens);
int verificaMovimentoValido(Mapa mapa, Posicao posicaoAtual, Posicao proximaPosicao);
char verificaSePosicaoTemInimigo(Mapa mapa, Posicao p);
int backingtrack(Mapa *mapa, ListaPersonagens *personagens, Posicao posicaoInicial);
int fazMovimento(Mapa *mapa, ListaPersonagens *personagens, Posicao posicaoInicial, Posicao proximaPosicao);

#endif