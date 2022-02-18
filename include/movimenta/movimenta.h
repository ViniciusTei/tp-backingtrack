#ifndef  MOVIMENTA
#define MOVIMENTA

#include "../mapa/mapa.h"
#include "../luta/luta.h"
#include "../core/analise.h"

typedef struct Posicao {
  int x;
  int y;
} Posicao;

void encontraPosicaoInicial(Mapa *mapa, Posicao *posicaoEncontrada);
void movimenta(Mapa *mapa, ListaPersonagens *personagens, Analise *var_analise);
int verificaMovimentoValido(Mapa mapa, Posicao posicaoAtual, Posicao proximaPosicao);
int verificaSePosicaoTemInimigo(Mapa mapa, Posicao p);
int backingtrack(Mapa *mapa, ListaPersonagens *personagens, Posicao posicaoInicial, Posicao proximaPosicao, Analise *var_analise);
int fazMovimento(Mapa *mapa, ListaPersonagens *personagens, Posicao posicaoInicial, Posicao proximaPosicao);
void imprimePosicao(Posicao p);
void imprimeStatusAtualMovimento(Mapa *mapa, PersonagemData Ness);

#endif