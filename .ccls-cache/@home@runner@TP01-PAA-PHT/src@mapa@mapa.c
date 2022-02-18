#include "../../include/mapa/mapa.h"

void iniciaMapa(Mapa *mapa, int A, int L) {
  mapa->altura = A;
  mapa->largura = L;
  mapa->xNess = 0;
  mapa->yNess = 0;
  mapa->mapa = (DadosMapa**) malloc(sizeof(DadosMapa*)*A);

  for (int i = 0; i < A; i++) {
    mapa->mapa[i] = (DadosMapa*) malloc(sizeof(DadosMapa)*L);

    for (int j = 0; j < L; j++) {
      mapa->mapa[i][j].ch = '.';
      mapa->mapa[i][j].enable = TRUE;
    }
  }

}
void atribuiPosicaoNess(Mapa *mapa, int xNess, int yNess){
  mapa->xNess = xNess;
  mapa->yNess = yNess;
}

void imprimeMapa(Mapa mapa) {
  printf("\n");
  for (int i = 0; i < mapa.altura; i++) {
    for (int j = 0; j < mapa.largura; j++) {
      printf("%c ", mapa.mapa[i][j].ch);
    }
    printf("\n");
  }
}

void printPosicaoColorida(char ch) {
  switch(ch) {
    case '.':
      black();
      break;
    case 'X':
      cyan();
      break;
    case 'U':
      rosa();
      break;
    case 'T':
      purple();
      break;
    case 'B':
      yellow();
      break;
    case 'S':
      laranja();
      break;
    case 'G':
      red();
      break;
    case '@':
      cyan();
      break;
    default:
      green();
      break;
  }
}

void mapaGrafico(Mapa mapa) {
  printf("\n*******************************\n");
  printf("\n");
  for (int i = 0; i < mapa.altura; i++) {
    for (int j = 0; j < mapa.largura; j++) {
      if((mapa.xNess == i) && (mapa.yNess == j)){
        printPosicaoColorida('X');
        printf("@ ");
        reset();
      }else if(mapa.mapa[i][j].enable == FALSE){
        printPosicaoColorida('X');
        printf("X ");
        reset();
      }else{
        printPosicaoColorida(mapa.mapa[i][j].ch);
        printf("%c ", mapa.mapa[i][j].ch);
        reset();
      }


      reset();
    }
    printf("\n");
  }
  printf("\n*******************************\n");
}

int defineCharNaPosicao(Mapa *mapa, char ch, int x, int y) {
  if (x < 0 || y < 0) {
    return -1;
  }

  if (x > mapa->altura || y > mapa->largura) {
    return -1;
  }

  mapa->mapa[x][y].ch = ch;
  return 1;
}

char getPosicao(Mapa mapa, int x, int y) {
  if (x < 0 || y < 0) {
    return -1;
  }

  if (x > mapa.altura || y > mapa.largura) {
    return -1;
  }

  return mapa.mapa[x][y].ch;
}