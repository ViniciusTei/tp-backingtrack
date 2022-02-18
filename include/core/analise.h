#ifndef ANALISE
#define ANALISE

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "../colors/colors.h"

typedef struct Analise {
  int chamadasRecursivas;
  int nivelMaximoRecursao; // otaldo pico
  int auxNivelMaximoRecursao;
} Analise;

typedef struct Argumentos {
  int MODO_VISUALIZACAO;
  int MODO_ANALISE;
  char *nome_arquivo;
} Argumentos;

Analise variaveis_analise;
Argumentos argumentos;
double tempo_gasto;
time_t tempo_inicio, tempo_fim;

void iniciaArgumentosAnalise(Analise *analise, Argumentos *args, int argc, char **argv);
void imprimeAnalise();

#endif