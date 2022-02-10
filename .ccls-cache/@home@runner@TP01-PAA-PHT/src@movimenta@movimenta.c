#include "../../include/movimenta/movimenta.h"

void encontraPosicaoInicial(Mapa *mapa, Posicao *posicaoEncontrada) {

  for(int i = 0; i < mapa->altura; i++) {
    for (int j = 0; j < mapa->largura; j++) {
      if (getPosicao(*mapa, i, j) == '@') {
        
        (*posicaoEncontrada).x = i;
        (*posicaoEncontrada).y = j;
        break;
      }
    }
  }

}

void movimenta(Mapa *mapa, ListaPersonagens *personagens) {
  Posicao posicaoInicial;

  encontraPosicaoInicial(mapa, &posicaoInicial);

  printf("linha: %d, coluna %d; ", posicaoInicial.x, posicaoInicial.y);
  imprimeNessStatus(personagens->Ness);

  //comecamos verificando as linhas

  backingtrack(mapa, personagens, posicaoInicial);
  
}

int backingtrack(Mapa *mapa, ListaPersonagens *personagens, Posicao posicaoInicial) {
  int resultado;
  Posicao proximaPosicao = posicaoInicial;

  // tenta andar pra direita
  proximaPosicao.y += 1;
  // verifica se o movimento eh valido para direita
  resultado = fazMovimento(mapa, personagens, posicaoInicial, proximaPosicao);
  //confere resultado
  if (resultado == 1) {
    // printf("\n X: %d, Y: %d\n",proximaPosicao.x, proximaPosicao.y);
    int res = backingtrack(mapa, personagens, proximaPosicao);

    if (res == 0) return 0;
  }else if(resultado == 0){
    return 0;
  }
  //volta o que foi andado
  proximaPosicao.y -= 1;
  //Proxima posição de teste
  proximaPosicao.x += 1;
  // verifica se o movimento eh valido para baixo
  resultado = fazMovimento(mapa, personagens, posicaoInicial, proximaPosicao);
  //confere resultado
  if (resultado == 1) {
    // printf("\n X: %d, Y: %d\n",proximaPosicao.x, proximaPosicao.y);
    int res = backingtrack(mapa, personagens, proximaPosicao);

    if (res == 0) return 0;
  }else if(resultado == 0){
    return 0;
  }
  //volta posição
  proximaPosicao.x -= 1;
  // Proxima posição de teste
  proximaPosicao.y -= 1;
  // verifica se o movimento eh valido para esquerda
  resultado = fazMovimento(mapa, personagens, posicaoInicial, proximaPosicao);
  //confere resultado
  if (resultado == 1) {
    // printf("\n X: %d, Y: %d\n",proximaPosicao.x, proximaPosicao.y);
    int res = backingtrack(mapa, personagens, proximaPosicao);

    if (res == 0) return 0;
  }else if(resultado == 0){
    return 0;
  }
  //Volta posição
  proximaPosicao.y += 1;
  // tenta andar pra cima
  proximaPosicao.x -= 1;
  // verifica se o movimento eh valido para cima
  resultado = fazMovimento(mapa, personagens, posicaoInicial, proximaPosicao);
  //confere resultado
  if (resultado == 1) {
    // printf("\n X: %d, Y: %d\n",proximaPosicao.x, proximaPosicao.y);
    int res = backingtrack(mapa, personagens, proximaPosicao);

    if (res == 0) return 0;
  }else if(resultado == 0){
    return 0;
  }
  return -1;
}

int fazMovimento(Mapa *mapa, ListaPersonagens *personagens, Posicao posicaoInicial, Posicao proximaPosicao) {
  int movimento = verificaMovimentoValido(*mapa, posicaoInicial, proximaPosicao);
  if (movimento > 0) {
    //pegamos o valor daquela posicao no mapa para sabermos se eh um inimgo
    char inimigo = verificaSePosicaoTemInimigo(*mapa, proximaPosicao);
    int resultadoLuta = luta(personagens, inimigo);

    // o metodo luta comeca verificando se eh um inimigo valido caso contrario
    // devemos mover para outra posicao valida
    if (resultadoLuta > 0) {
      printf("\nLinha: %d, Coluna %d; ", proximaPosicao.x, proximaPosicao.y);
      imprimeNessStatus(personagens->Ness);

      if (inimigo == 'G') {
        printf("\nParabens voce derrotou Giygas!");
        return 0;
      }

      return 1;
    } else if (resultadoLuta == 0) {
      //printf("\nEsse caminho deu ruim");
      printf("\nLinha: %d, Coluna %d; ", proximaPosicao.x, proximaPosicao.y);

      return -1;
    } else {
      printf("\nLinha: %d, Coluna %d; ", proximaPosicao.x, proximaPosicao.y);
      // vai para a proxima posicao valida
      //backingtrack(mapa, personagens, proximaPosicao);
      return 1;
    }
  } else {
    //printf("\nLinha: %d, Colunha %d; Nao foi possivel ir para esse caminho!", proximaPosicao.x, proximaPosicao.y);

    return -1;
  }
}

char verificaSePosicaoTemInimigo(Mapa mapa, Posicao p) {
  return mapa.mapa[p.x][p.y];
}

int verificaMovimentoValido(Mapa mapa, Posicao posicaoAtual, Posicao proximaPosicao) {
  // nao pode seguir para fora do mapa
  if(proximaPosicao.x > mapa.altura || proximaPosicao.x < 0) {
    //printf("\n Fora do mapa");
    return -1;
  }

  if(proximaPosicao.y > mapa.largura || proximaPosicao.y < 0) {
    //printf("\n Fora do mapa");
    return -1;
  }

  // nao pode seguir para uma posicao com um ponto
   if(mapa.mapa[proximaPosicao.x][proximaPosicao.y] == '.'){
     //printf("\n Erro x,y: %d,%d",proximaPosicao.x, proximaPosicao.y);
     //printf("\n Ponto");
     return -1;
   }
  // quando eoncontrar um - pode vir apenas de um y valido
  if(mapa.mapa[proximaPosicao.x][proximaPosicao.y] == '-') {
    //printf("\n Anda Y");
    //printf("\n X,Y : %d,%d",proximaPosicao.x, proximaPosicao.y);
    return (posicaoAtual.y == proximaPosicao.y - 1) || (posicaoAtual.y == proximaPosicao.y + 1);
  }
  // quando econtra um | pode vir de apenas um x valido
  if(mapa.mapa[proximaPosicao.x][proximaPosicao.y] == '|') {
    //printf("\n Anda X");
    //printf("\n X,Y : %d,%d",proximaPosicao.x, proximaPosicao.y);
    return (posicaoAtual.x == proximaPosicao.x - 1) || (posicaoAtual.x == proximaPosicao.x + 1);
  } 

  // quando econtrar um + pode seguir para qualquer direcao

  return 1;
}