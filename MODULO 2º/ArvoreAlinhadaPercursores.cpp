#include <bits/stdc++.h>
 
using namespace std;
 
class NoArvore{
    public:
        NoArvore *direita;
        NoArvore *esquerda;
        int sucessor;
        int valor;
        
        NoArvore(int valor){
            this->valor = valor;
            this->direita = NULL;
            this->esquerda = NULL;
            this->sucessor = 0;
        }
};
 
class Arvore{
    public:
        NoArvore *raiz;
 
        Arvore(){
            this->raiz = NULL;
        }
 
        bool vazio(){
            if (raiz == NULL){
                return true;
            } else {
                return false;
            }
        }

        void inserir(int valor){
            if (vazio()){
                raiz = new NoArvore(valor);
            } else {
                NoArvore *novoNo = new NoArvore(valor);
                NoArvore *auxNoarvore = raiz;
                NoArvore *anterior;
                
                while(auxNoarvore != NULL){
                    anterior = auxNoarvore;
                    if (auxNoarvore->valor > valor){         /* Move para o lado onde o nó sera adicionado no caso a esquerda */
                        auxNoarvore = auxNoarvore->esquerda; /* caso o valor do pai seja maior que o valor a adicionar */

                    } else if (auxNoarvore->sucessor == 0){ /* Move para o lado onde o nó sera adicionado no caso a direita */
                        auxNoarvore = auxNoarvore->direita; /* se o valor a adicionar for maior, e a raiz for um decendente = 0 */
                    } else {
                        break;
                    }
                } 
                if (anterior->valor > valor){
                    anterior->esquerda = novoNo;
                    novoNo->sucessor = 1;
                    novoNo->direita = anterior;

                } else if (anterior->sucessor == 1){
                    novoNo->sucessor = 1;
                    anterior->sucessor = 0;
                    novoNo->direita = anterior->direita;
                    anterior->direita = novoNo;

                } else {
                    anterior->direita = novoNo;
                }
            }
        }

        void inOrdem(){
            NoArvore *auxNoArvore = raiz; 
            NoArvore *anterior = raiz;

            while(auxNoArvore->esquerda != NULL){
                auxNoArvore = auxNoArvore->esquerda;
            }
            while(auxNoArvore != NULL){
                cout << auxNoArvore->valor << " ";
                anterior = auxNoArvore;
                auxNoArvore = auxNoArvore->direita;

                if (auxNoArvore != NULL && anterior->sucessor == 0){
                    while(auxNoArvore->esquerda != NULL){
                        auxNoArvore = auxNoArvore->esquerda;
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
    arvore->inserir(6);
    arvore->inserir(1);
    arvore->inserir(3);
    arvore->inserir(5);
    
    cout << "\nIn-Ordem(ERD): ";
    arvore->inOrdem();
    
}