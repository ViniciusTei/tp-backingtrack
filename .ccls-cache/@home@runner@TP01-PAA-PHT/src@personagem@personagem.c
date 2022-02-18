#include "../../include/personagem/personagem.h"
#include "../../include/colors/colors.h"

void iniciaListaInimigos(ListaPersonagens *lista) {
  lista->primeiroInimigo = 0;
  lista->ultimoInimigo = lista->primeiroInimigo;
}

void imprimeListaInimigos(ListaPersonagens lista) {
  for (int i = 0; i < lista.ultimoInimigo; i++) {
    printf("\nInimigo %s -> P: %d | K: %d\n", retornaNomeInimigo(lista.inimigos[i].name), lista.inimigos[i].p, lista.inimigos[i].k);
  }
}

char* retornaNomeInimigo(char inicial) {
  switch(inicial) {
    case 'U':
      return "Li’l UFO";
    case 'T':
      return "Territorial Oak";
    case 'S':
      return "Starman Junior";
    case 'B':
      return "Master Belch";
    case 'G':
      return "Giygas";
    default:
      return "";
  }
}

void iniciaNess(ListaPersonagens *lista, int P, int K) {
  lista->Ness.name = 'N';
  lista->Ness.p = P;
  lista->Ness.k = K;
}

 /** 
  * void imprimeNessStatus(PersonagemData Ness) 
  * 
  *    Essa funcao mostra os dados do personagem principal
  *    o valor de P e de K.
  * 
  * Parameters   : Ness: Personagem data 
  * 
  * Return Value : Nothing". 
  * 
  */
void imprimeNessStatus(PersonagemData Ness) {
  laranja();
  printf("\nNess Status -> P:%d, K:%d", Ness.p, Ness.k);
  reset();
}

void iniciaMonstro(ListaPersonagens *lista, int P, int K, int Monstro) {
  if (Monstro == U) {
    iniciaMonstroData(lista, P, K, 'U');
  }
  if (Monstro == T) {
    iniciaMonstroData(lista, P, K, 'T');
  }
  if (Monstro == S) {
    iniciaMonstroData(lista, P, K, 'S');
  }
  if (Monstro == B) {
    iniciaMonstroData(lista, P, K, 'B');
  }
  if (Monstro == G) {
    iniciaMonstroData(lista, P, K, 'G');
  }
}

void iniciaMonstroData(ListaPersonagens *lista, int P, int K, char nome) {
  lista->inimigos[lista->ultimoInimigo].name = nome;
  lista->inimigos[lista->ultimoInimigo].k = K;
  lista->inimigos[lista->ultimoInimigo].p = P;
  lista->ultimoInimigo++;
}