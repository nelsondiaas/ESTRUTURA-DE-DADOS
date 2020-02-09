#include <bits/stdc++.h>

using namespace std;

class NoArvore{
    public:
        NoArvore *direita;
        NoArvore *esquerda;
        int valor;

        NoArvore(int valor){
            this->direita = NULL;
            this->esquerda = NULL;
            this->valor = valor;
        }
};

class Arvore{
    public:
        NoArvore *raiz;

        Arvore(){
            raiz = NULL;
        }

        void inserir(int valor){
            NoArvore *novoNo = new NoArvore(valor);
            NoArvore *auxNoArvore = raiz;  

            if (raiz == NULL){
                raiz = novoNo;
            } else {

                while(auxNoArvore != NULL && auxNoArvore->valor != valor){
                    if (auxNoArvore->valor > valor){
                        if (auxNoArvore->esquerda == NULL){
                            auxNoArvore->esquerda = novoNo;
                        } else {
                            auxNoArvore = auxNoArvore->esquerda;
                        }

                    } else {
                        if (auxNoArvore->direita == NULL){
                            auxNoArvore->direita = novoNo;
                        } else {
                            auxNoArvore = auxNoArvore->direita;
                        }
                    }
                }
                auxNoArvore = novoNo;
            }
        }

        void inOrdemMorris(){
            NoArvore *corrente = raiz;
            NoArvore *predecessor;
            while(corrente != NULL){
                if (corrente->esquerda == NULL){
                    cout << corrente->valor << " ";
                    corrente = corrente->direita;
                } else {
                    
                    predecessor = corrente->esquerda;
                    while(predecessor->direita != NULL && predecessor->direita != corrente){
                        predecessor = predecessor->direita;
                    }
                    if (predecessor->direita == NULL){
                        predecessor->direita = corrente;
                        corrente = corrente->esquerda;
                    } else {

                        /* Reverter as auterações feitas, para restaurar a arvore original */
                        /* ou seja corrijir o filho correto do predecessor */
                        predecessor->direita = NULL;
                        cout << corrente->valor << " ";
                        corrente = corrente->direita;
                    }
                }
            }
        }

        void preOrdemMorris(){
            NoArvore *corrente = raiz;
            
            while (corrente != NULL){
                if (corrente->esquerda == NULL){
                    cout << corrente->valor << " ";
                    corrente = corrente->direita;
                } else {
                    
                    NoArvore *predecessor = corrente->esquerda;
                    while(predecessor->direita != corrente && predecessor->direita != NULL){
                        predecessor = predecessor->direita;
                    }
                    if (predecessor->direita == NULL){
                        predecessor->direita = corrente;
                        cout << corrente->valor << " ";
                        corrente = corrente->esquerda;
                    } else {

                        predecessor->direita = NULL;
                        corrente = corrente->direita;
                    }
                }
            }
        }    
              
};

int main()
{
    Arvore *arvore = new Arvore();

    arvore->inserir(4);
    arvore->inserir(2);
    arvore->inserir(1);
    arvore->inserir(3);
    arvore->inserir(6);
    arvore->inserir(5);

    cout << "In-Ordem(ERD): ";
    arvore->inOrdemMorris();

    cout << "\nPre-Ordem(RED): ";
    arvore->preOrdemMorris();

}

/* C = Corrente, P = Predecessor */

/* 
   A ideia de Morris Traversal é baseada na Árvore Binária Com Rosca.
   Neste percurso, primeiro criamos links para o sucessor Inorder e 
   imprimimos os dados usando esses links, e finalmente revertemos as 
   alterações para restaurar a árvore original.
*/