#include "monstro.h"

void iniciaListaInimigos(ListaInimigos *lista) {
  lista->primeiro = 0;
  lista->ultimo = lista->primeiro;
}

void imprimeListaInimigos(ListaInimigos lista) {
  for (int i = 0; i < lista.ultimo; i++) {
    printf("Inimigo %c -> P: %d | K: %d\n", lista.inimigos[i].name, lista.inimigos[i].p, lista.inimigos[i].k);
  }
}