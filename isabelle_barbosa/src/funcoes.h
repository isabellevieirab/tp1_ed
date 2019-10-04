#ifndef __TP1_ED___
#define __TP1_ED__

struct celula{
    int v;
    int opr;
    celula* prox;
};

class ListaEncadeada{
    public:
        celula* cabeca; 
        celula* ponta; 
        int tamanho;
        
        ListaEncadeada();
        ListaEncadeada(int v);

        virtual ~ListaEncadeada();
        void imprime();
        bool vazia();
        void insere(int v, int operacao);
        void apaga(int v);
        int verificaLista(int valor);
        celula acessa(int posicao);
};

int retornaOperacoes(ListaEncadeada *frascos, int valor);

#endif
