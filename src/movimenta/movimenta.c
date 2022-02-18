#include "../../include/movimenta/movimenta.h"


// Percorre todo o mapa ate encontrar o carctere que representa nosso personagem
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

void imprimeStatusAtualMovimento(Mapa *mapa, PersonagemData Ness) {
  mapaGrafico(*mapa);
  imprimeNessStatus(Ness);

  if (argumentos.MODO_VISUALIZACAO == 1) {
    sleep(1);
  }
}

// inicia nosso movimento pelo mapa
void movimenta(Mapa *mapa, ListaPersonagens *personagens, Analise *var_analise) {
  Posicao posicaoInicial;

  encontraPosicaoInicial(mapa, &posicaoInicial);
  atribuiPosicaoNess(mapa, posicaoInicial.x, posicaoInicial.y);

  //imprimeNessStatus(personagens->Ness);

  //imprimePosicao(posicaoInicial);
  //comecamos verificando as linhas

  int resultado = backingtrack(mapa, personagens, posicaoInicial, posicaoInicial, var_analise);
  
  if (resultado < 0) {
    cyan();
    printf("\nNess nao foi capaz de derrotar o grande Giygas\n\n");
    reset();
  }

}

int backingtrack(Mapa *mapa, ListaPersonagens *personagens, Posicao posicaoInicial, Posicao proximaPosicao, Analise *var_analise) {
  int resultado;
  // Auxiliares para quando voltar no tempo utilizando backtracking os status de personagens assim como mapa e posição devem estar guardados
  Mapa mapaAtual = *mapa;
  ListaPersonagens listaAtual = *personagens;
  // printf("\nINICIO");
  // printf("\nNess personagens %d",personagens->Ness.p);
  // printf("\nNess listaAtual %d",listaAtual.Ness.p);

  (*var_analise).chamadasRecursivas++;
  (*var_analise).auxNivelMaximoRecursao++;
  if ((*var_analise).nivelMaximoRecursao < (*var_analise).auxNivelMaximoRecursao) {
    (*var_analise).nivelMaximoRecursao = (*var_analise).auxNivelMaximoRecursao;
  }

  // tenta andar pra direita
  proximaPosicao.y += 1;
  // verifica se o movimento eh valido para direita
  resultado = fazMovimento(mapa, personagens, posicaoInicial, proximaPosicao);
  //confere resultado
  if (resultado == 1) {
    // printf("\n X: %d, Y: %d\n",proximaPosicao.x, proximaPosicao.y);
    if(mapa->mapa[posicaoInicial.x][posicaoInicial.y].ch != '+'){
      mapa->mapa[posicaoInicial.x][posicaoInicial.y].enable = FALSE;
    }
    imprimeStatusAtualMovimento(mapa, personagens->Ness);
    atribuiPosicaoNess(mapa, proximaPosicao.x, proximaPosicao.y);
    int res = backingtrack(mapa, personagens, proximaPosicao, proximaPosicao, var_analise);
    if(personagens->Ness.p != listaAtual.Ness.p){
      // printf("\nDireita");
      // printf("\nNess personagens %d",personagens->Ness.p);
      // printf("\nNess listaAtual %d",listaAtual.Ness.p);
      *personagens = listaAtual;
    }
    mapa->mapa[posicaoInicial.x][posicaoInicial.y].enable = TRUE;
    atribuiPosicaoNess(mapa, posicaoInicial.x, posicaoInicial.y);
    (*var_analise).auxNivelMaximoRecursao--;
    if (res == 0) return 0;
     //Atribui valores iniciais as estruturas para que a volta no tempo ocorra de uma boa maneira
    imprimeStatusAtualMovimento(mapa, personagens->Ness);
  }else if(resultado == 0){
    return 0;
  }
  proximaPosicao.y -= 1;
  //Proxima posição de teste
  proximaPosicao.x += 1;
  // verifica se o movimento eh valido para baixo
  resultado = fazMovimento(mapa, personagens, posicaoInicial, proximaPosicao);
  //confere resultado
  if (resultado == 1) {
    // printf("\n X: %d, Y: %d\n",proximaPosicao.x, proximaPosicao.y);
    if(mapa->mapa[posicaoInicial.x][posicaoInicial.y].ch != '+'){
      mapa->mapa[posicaoInicial.x][posicaoInicial.y].enable = FALSE;
    }
    atribuiPosicaoNess(mapa, proximaPosicao.x, proximaPosicao.y);
    imprimeStatusAtualMovimento(mapa, personagens->Ness);
    int res = backingtrack(mapa, personagens, proximaPosicao, proximaPosicao, var_analise);
    if(personagens->Ness.p != listaAtual.Ness.p){
      // printf("\nBaixo");
      // printf("\nNess personagens %d",personagens->Ness.p);
      // printf("\nNess listaAtual %d",listaAtual.Ness.p);
      *personagens = listaAtual;
    }
    mapa->mapa[posicaoInicial.x][posicaoInicial.y].enable = TRUE;
    atribuiPosicaoNess(mapa, posicaoInicial.x, posicaoInicial.y);
    (*var_analise).auxNivelMaximoRecursao--;
    if (res == 0) return 0;
     //Atribui valores iniciais as estruturas para que a volta no tempo ocorra de uma boa maneira
    imprimeStatusAtualMovimento(mapa, personagens->Ness);
  }else if(resultado == 0){
    return 0;
  }
 proximaPosicao.x -= 1;
  // Proxima posição de teste
  proximaPosicao.y -= 1;
  // verifica se o movimento eh valido para esquerda
  resultado = fazMovimento(mapa, personagens, posicaoInicial, proximaPosicao);
  //confere resultado
  if (resultado == 1) {
    // printf("\n X: %d, Y: %d\n",proximaPosicao.x, proximaPosicao.y);
    if(mapa->mapa[posicaoInicial.x][posicaoInicial.y].ch != '+'){
      mapa->mapa[posicaoInicial.x][posicaoInicial.y].enable = FALSE;
    }
    atribuiPosicaoNess(mapa, proximaPosicao.x, proximaPosicao.y);
    imprimeStatusAtualMovimento(mapa, personagens->Ness);
    int res = backingtrack(mapa, personagens, proximaPosicao, proximaPosicao, var_analise);
    if(personagens->Ness.p != listaAtual.Ness.p){
      // printf("\nEsquerda");
      // printf("\nNess personagens %d",personagens->Ness.p);
      // printf("\nNess listaAtual %d",listaAtual.Ness.p);
      *personagens = listaAtual;
      // printf("\nNess personagens %d",personagens->Ness.p);
    }
    mapa->mapa[posicaoInicial.x][posicaoInicial.y].enable = TRUE;
    atribuiPosicaoNess(mapa, posicaoInicial.x, posicaoInicial.y);
    (*var_analise).auxNivelMaximoRecursao--;
    if (res == 0) return 0;
     //Atribui valores iniciais as estruturas para que a volta no tempo ocorra de uma boa maneira
    imprimeStatusAtualMovimento(mapa, personagens->Ness);
  }else if(resultado == 0){
    return 0;
  }
  proximaPosicao.y += 1;
  // tenta andar pra cima
  proximaPosicao.x -= 1;
  // verifica se o movimento eh valido para cima
  resultado = fazMovimento(mapa, personagens, posicaoInicial, proximaPosicao);
  //confere resultado
  if (resultado == 1) {
    // printf("\n X: %d, Y: %d\n",proximaPosicao.x, proximaPosicao.y);
    if(mapa->mapa[posicaoInicial.x][posicaoInicial.y].ch != '+'){
      mapa->mapa[posicaoInicial.x][posicaoInicial.y].enable = FALSE;
    }
    atribuiPosicaoNess(mapa, proximaPosicao.x, proximaPosicao.y);
    imprimeStatusAtualMovimento(mapa, personagens->Ness);
    int res = backingtrack(mapa, personagens, proximaPosicao, proximaPosicao, var_analise);
    if(personagens->Ness.p != listaAtual.Ness.p){
      // printf("\nAcima");
      // printf("\nNess personagens %d",personagens->Ness.p);
      // printf("\nNess listaAtual %d",listaAtual.Ness.p);
      *personagens = listaAtual;
    }
    
    mapa->mapa[posicaoInicial.x][posicaoInicial.y].enable = TRUE;
    atribuiPosicaoNess(mapa, posicaoInicial.x, posicaoInicial.y);
    (*var_analise).auxNivelMaximoRecursao--;
    if (res == 0) return 0;
     //Atribui valores iniciais as estruturas para que a volta no tempo ocorra de uma boa maneira
    imprimeStatusAtualMovimento(mapa, personagens->Ness);
  }else if(resultado == 0){
    return 0;
  }
  return -1;
}


 /** 
  * int fazMovimento(Mapa *mapa, ListaPersonagens *personagens, Posicao posicaoInicial, Posicao proximaPosicao)
  * 
  *    Essa funcao faz toda a logica do movimento, comecando verificando se eh um
  *    movimento valido. So entao verificamos se temos um inimgo para lutar, e fazemos
  *    o retorno do resultado da acao de movimento.
  * 
  * Parameters   : mapa: Mapa info
  *                personagens: personagens info
  *                posicaoInicial: posicao da qual queremos partir
  *                proximaPosicao: posicao que queremos chegar
  * Return Value : 0: lutamos e perdemos ou ganhamos do giygas.
  *                1: lutamos e ganhamos ou apenas avanacamos 
  *               -1: caminho invalido 
  * 
  */
int fazMovimento(Mapa *mapa, ListaPersonagens *personagens, Posicao posicaoInicial, Posicao proximaPosicao) {
  if (verificaMovimentoValido(*mapa, posicaoInicial, proximaPosicao) > 0) {
    //imprimePosicao(proximaPosicao);
    //sleep(1);
    //mapaGrafico(*mapa);
    // se a posicao nao for um inimigo nos vamos para a proxima posicao valida
    if (verificaSePosicaoTemInimigo(*mapa, proximaPosicao) == FALSE) return 1;
    
    char inimigo = getPosicao(*mapa, proximaPosicao.x, proximaPosicao.y);
    int resultadoLuta = luta(personagens, inimigo);
    //sleep(1);
    //imprimeNessStatus(personagens->Ness);

    if (inimigo == 'G' && resultadoLuta == 1) {
      green();
      printf("\nParabens voce derrotou Giygas!");
      reset();
      return 0;
    }
    return resultadoLuta;
  } 
  
  // movimento invalido
  return -1;
}

void imprimePosicao(Posicao p) {
  yellow();
  printf("\nLinha: %d, Coluna %d; ", p.x, p.y);  
  reset();
}

int verificaSePosicaoTemInimigo(Mapa mapa, Posicao p) {
  char pos = getPosicao(mapa, p.x, p.y);
  
  if(pos == '.' || pos == '+' || pos == '|' || pos == '-'|| pos == '@') 
    return FALSE;

  return TRUE;
}

int verificaMovimentoValido(Mapa mapa, Posicao posicaoAtual, Posicao proximaPosicao) {
  
  // nao pode seguir para fora do mapa
  if(proximaPosicao.x >= mapa.altura || proximaPosicao.x < 0) return -1;
  if(proximaPosicao.y >= mapa.largura || proximaPosicao.y < 0) return -1;

  // nao pode voltar por um caminho que ja passou
  if(mapa.mapa[proximaPosicao.x][proximaPosicao.y].enable == FALSE) return -1;

  // nao pode seguir para uma posicao com um ponto
  if(getPosicao(mapa, proximaPosicao.x, proximaPosicao.y) == '.') return -1;

  // quando eoncontrar um - pode vir apenas de um y valido
  if(getPosicao(mapa, posicaoAtual.x, posicaoAtual.y) == '-') {
    return (posicaoAtual.y == proximaPosicao.y - 1) || (posicaoAtual.y == proximaPosicao.y + 1);
  }
  
  // quando econtra um | pode vir de apenas um x valido
  if(getPosicao(mapa, posicaoAtual.x, posicaoAtual.y) == '|') {
    return (posicaoAtual.x == proximaPosicao.x - 1) || (posicaoAtual.x == proximaPosicao.x + 1);
  } 

  // quando econtrar um + pode seguir para qualquer direcao
  return 1;
}