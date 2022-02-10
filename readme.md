# TP01 PAA

## TO-DO

- [x] criar estrutura de arquivos
- [x] criar estruturas de dados dos personagens
  - [x] iniciar personagens com seus respectivos nomes e valores de P e K
  - [x] fazer metodos de batalha
    - [x] encontrar um monstro na lista pelo nome
    - [x] regra da luta: verificar valores de P do Ness e do inimigo, caso P for maior Ness vence caso P for menor verifica se o K do Ness eh maior q 0, entao ele vence, se nao ele perde.
    - [x] atualizar os valores de Ness para cada acao anterior
- [x] criar estruturas de dados do mapa
- [ ] fazer algoritmo de movimentar (criar movimentar.c na pasta do mapa)
  - [ ] implementar algoritmo de backingtrack
  - [x] implementar regras de movimentacao de acordo com os caracteres especiais
- [ ] terminar de implemtar leitura de arquivo para inicializar as etruturas

Uma implementacao generica de backingtrack

```python
  def backtrack(v): # v é o nó sendo pesquisado
    if (promissor(v)):
      if (existe_solucao(v)):
        armazena_solucao(v)
      else:
        for filho in v:
          backtrack(filho)
  }
```

Nosso problema

- enquanto Ness estiver ganhando lutas e nao estiver ganhado do Gygas continua andando
- se Ness perde uma luta, volta (backingtrack) para a ultima casa valida
- deve seguir as regras de movimentacao de cada bloco
