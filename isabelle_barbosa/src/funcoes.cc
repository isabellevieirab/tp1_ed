#include "funcoes.h"
#include <cstdio> 

ListaEncadeada::ListaEncadeada(){
    this->cabeca = nullptr;
    this->ponta = nullptr;
    this->tamanho = 0;
}

ListaEncadeada::ListaEncadeada(int v){
  
            this->cabeca = new celula;
            this->cabeca->v = v;
            this->ponta = cabeca;
            this->tamanho = 1;
}

ListaEncadeada::~ListaEncadeada(){
    delete this->cabeca;
}

void ListaEncadeada::imprime(){
    celula* c = cabeca;

    if(vazia()){
        printf("A lista NAO possui elementos!!\n");
    }else{
        int i = 0;
        while(i<this->tamanho){
            printf("%d\t%d\n",c->v,c->opr);
            c = c->prox;
            i++;
        }
        printf("\n");
    }
}

bool ListaEncadeada::vazia(){
    return (cabeca == nullptr);
}


void ListaEncadeada::insere(int v, int operacao){ 
    celula* new_celula = new celula;
    new_celula->v = v;
    new_celula->opr = operacao;
    if(vazia()){
        this->cabeca = new_celula;
        this->ponta = new_celula;
        this->tamanho=tamanho+1;
    }else{
        this->ponta->prox = new_celula;
        this->ponta = new_celula;
        tamanho++;
    }
}


void ListaEncadeada::apaga(int v){
    celula* anterior = cabeca;
    celula* atual = cabeca;
        while(atual != nullptr){
            if(atual->v == v){
                if(this->tamanho == 1){
                    ponta = nullptr;
                    cabeca = nullptr;
                    tamanho--;
                    break;
                }else{
                    if (atual == cabeca){
                        cabeca = cabeca->prox;
                        tamanho--;
                        break;
                    }else{
                        if (atual == ponta){
                            ponta = anterior;
                            anterior->prox = nullptr;
                            tamanho--;
                            break;
                        }
                    anterior->prox = atual->prox;
                    tamanho--;
                    break;
                    }
                }
            }else{
                anterior = atual;
                atual = atual->prox;
            }
        }
    delete atual;
}
        
int ListaEncadeada::verificaLista(int valor){
    int i;
    celula* aux = cabeca;
    for(i=0; i<this->tamanho; i++){
        if (aux->v ==valor){
            return aux->opr;
        }
        aux = aux->prox;
    }
    return -1;  
}

celula ListaEncadeada::acessa(int posicao){
    celula* aux = this->cabeca;
    int i;
    for(i=0; i<=posicao; i++){
        aux = aux->prox;
    }
    celula c;
    c.v = aux->v;
    c.opr = aux->opr;
    c.prox = nullptr;
    
    return c;
}

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