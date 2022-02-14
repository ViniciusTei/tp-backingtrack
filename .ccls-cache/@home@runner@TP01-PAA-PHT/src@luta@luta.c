#include "../../include/luta/luta.h"

int luta(ListaPersonagens *lista, char Inimigo) {
  int inimigoIndex = encontraInimigoPeloNome(lista, Inimigo);

  if (inimigoIndex < 0) {
    // printf("\nInimigo nao foi encontrado para a luta :(");

    return -1;
  }

  red();
  printf("\nNess luta com %s", retornaNomeInimigo(lista->inimigos[inimigoIndex].name));
  reset();
  // verifica se o valor de p do ness eh suficiente para ganhar
  if (lista->Ness.p > lista->inimigos[inimigoIndex].p) {
    // printf("Batalha vencida!\n");

    // atualiza os valores de Ness
    lista->Ness.p += lista->inimigos[inimigoIndex].k;
    return 1;
  }

  //verifica se o ness tem K para usar
  if (lista->Ness.k > 0) {
    // printf("Ness usou PK Flash para vencer a batalha!\n");
    
    lista->Ness.p += lista->inimigos[inimigoIndex].k;
    lista->Ness.k--;
    return 1;
  }

  // printf("Voce perdeu!");

  return 0;
}

int encontraInimigoPeloNome(ListaPersonagens *lista, char inimigo) {
  int indexEncontrado = -1;
  for (int i = 0; i < lista->ultimoInimigo; i++) {
    if (lista->inimigos[i].name == inimigo) {
      indexEncontrado = i;
    }
  }
  
  return indexEncontrado;
}
