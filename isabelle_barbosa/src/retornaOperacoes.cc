#include "retornaOperacoes.h"
#include <cstdio> 


int retornaOperacoes(ListaEncadeada *Frascos, int valor){
    int x;
    celula c;
    x = Frascos->verificaLista(valor);
    if (x != -1){
        return x;
    }else{
        ListaEncadeada *Historico = new ListaEncadeada;
        int t_frascos = Frascos->tamanho;
        for(int i=0; i<t_frascos; i++){
            c = Frascos->acessa(i-1);
            Historico->insere(c.v, c.opr);
        }
        celula a, b; 
        while(true){
                int t_historico = Historico->tamanho;
                for(int j=0; j<t_historico; j++){
                    b = Historico->acessa(0-1);
                    Historico->apaga(b.v);
                        for (int i=0; i<t_frascos; i++){
                            a = Frascos->acessa(0-1);
                            Frascos->apaga(a.v);
                            Frascos->insere(a.v, a.opr);
                            int soma = b.v + a.v;
                            int sub = a.v - b.v;
                            int operacoes = b.opr + 1;
                            
                            if(soma == valor){
                                delete Historico;
                                return operacoes;
                            }
                            if(sub == valor){
                                delete Historico;
                                return operacoes;
                            }
                            if(soma > 0){
                                if(Historico->verificaLista(soma)==-1){
                                    Historico->insere(soma, operacoes);
                                }
                            }
                            if(sub > 0){
                                if(Historico->verificaLista(sub)==-1){
                                    Historico->insere(sub, operacoes);
                                }
                            }
                        }
                }
        }
    delete Historico;
    return -1;
    }
}
