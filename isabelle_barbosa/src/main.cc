#include <cstdio> // em C substituir por #include <stdio.h>
#include "ListaEncadeada.h"
#include "retornaOperacoes.h"

int main() {
  int q;
  char e;
  ListaEncadeada *Frascos = new ListaEncadeada;
  while(scanf("%d %c", &q, &e) != EOF) {
    if(e == 'i'){
      Frascos->insere(q, 1);    
    }
    if (e == 'p'){
      printf("%d\n", retornaOperacoes(Frascos, q));
    }
    if(e == 'r'){
      Frascos->apaga(q);
    }
  }
  return 0;
}
