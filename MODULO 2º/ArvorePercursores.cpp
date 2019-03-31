#include <bits/stdc++.h>
 
using namespace std;
 
class NoArvore{
    public:
        int valor;
        NoArvore *esquerda;
        NoArvore *direita;
        int verifica;
 
        NoArvore(int valor){
            this->valor = valor;
            this->esquerda = NULL;
            this->direita = NULL;
        }
};
 
class NoPilha{
    public:
        NoArvore *noArvore;
        NoPilha *anterior;
 
        NoPilha(NoArvore *node){
            this->noArvore = node;
            this->anterior = NULL;
        }
};

class Arvore{
    public:
        NoArvore *raiz = NULL;
        
        bool verificaRaiz(){
            if (this->raiz == NULL){
                return true;
            } else {
                return false;
            }
        }

        void inserir(NoArvore *noArvore, int valor){
            if (verificaRaiz()){
                raiz = new NoArvore(valor);
                return;
            } 

            if (valor < noArvore->valor){
                if (noArvore->esquerda == NULL){
                    noArvore->esquerda = new NoArvore(valor);
                } else {
                    this->inserir(noArvore->esquerda, valor);
                }

            } else {
                if (noArvore->direita == NULL){
                    noArvore->direita = new NoArvore(valor);
                } else {
                    this->inserir(noArvore->direita, valor);
                }
            }
        }    
};

class Pilha{
    public:
        NoPilha *topo = NULL;
        Arvore *arvore = new Arvore();

        bool vazia(){
            if (this->topo == NULL){
                return true;
            } else {
                return false;
            }
        }

        NoArvore *pop(){
            NoArvore *auxNoArvore;
            if (vazia()){
                return NULL;
            } else {
                auxNoArvore = topo->noArvore;
                topo = topo->anterior;
            }
            return auxNoArvore;
        }
 
        void push(NoPilha *node){
            if (vazia()){
                this->topo = node;
            } else {
                node->anterior = this->topo;
                this->topo = node;
            }
        }
        
         void inOrdem(){
            NoArvore *auxNoArvore = arvore->raiz;
            bool controle = false;

            while(controle == false){
                while(auxNoArvore != NULL){
                    this->push(new NoPilha(auxNoArvore));
                    auxNoArvore = auxNoArvore->esquerda;
                }
                auxNoArvore = this->pop();

                if (auxNoArvore == NULL){
                    controle = true;
                } else {
                    cout << auxNoArvore->valor << " ";
                    auxNoArvore = auxNoArvore->direita;
                }
            }
        }

        void preOrdem(){
            NoArvore *auxNoArvore = arvore->raiz;
            bool controle = false;

            while(controle == false){
                while(auxNoArvore != NULL){
                    cout << auxNoArvore->valor << " ";
                    this->push(new NoPilha(auxNoArvore));
                    auxNoArvore = auxNoArvore->esquerda;
                }
                auxNoArvore = this->pop();

                if (auxNoArvore == NULL){
                    controle = true;
                } else {
                    auxNoArvore = auxNoArvore->direita;
                }
            }
        }

        void posOrdem(){
            NoArvore *auxNoArvore = arvore->raiz;
            bool controle = false;

            while(controle == false){
                while(auxNoArvore != NULL){
                    auxNoArvore->verifica = 1;
                    this->push(new NoPilha(auxNoArvore));
                    auxNoArvore = auxNoArvore->esquerda;
                }
                auxNoArvore = this->pop();
                
                if (auxNoArvore == NULL){
                    controle = true;

                } else {

                    if (auxNoArvore->verifica == 1){
                        auxNoArvore->verifica = 2;
                        this->push(new NoPilha(auxNoArvore));
                        auxNoArvore = auxNoArvore->direita;
                        
                    } else {
                        cout << auxNoArvore->valor << " ";
                        auxNoArvore = NULL;
                    }
                }
            }
        }
        
};

int main()
{   
    
    Pilha *pilha = new Pilha();
    
    pilha->arvore->inserir(pilha->arvore->raiz, 8);
    pilha->arvore->inserir(pilha->arvore->raiz, 3);
    pilha->arvore->inserir(pilha->arvore->raiz, 1);
    pilha->arvore->inserir(pilha->arvore->raiz, 6);
    pilha->arvore->inserir(pilha->arvore->raiz, 4);
    pilha->arvore->inserir(pilha->arvore->raiz, 7);
    pilha->arvore->inserir(pilha->arvore->raiz, 10);
    pilha->arvore->inserir(pilha->arvore->raiz, 14);
    pilha->arvore->inserir(pilha->arvore->raiz, 13);
    
    cout << "Pre-Ordem(RED): ";
    pilha->preOrdem();

    cout << "\nIn-Ordem(ERD): ";
    pilha->inOrdem();
    
    cout << "\nPos-Ordem(EDR): ";
    pilha->posOrdem();

}


/*
Pre-Ordem: Raiz, Esquerda e Direita.
In-Ordem: Esquerda, Raiz e Direita.
Pos-Ordem: Esquerda, Direita e Raiz.
*/