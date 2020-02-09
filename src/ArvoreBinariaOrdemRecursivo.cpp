#include <bits/stdc++.h>
 
using namespace std;
 
class No{
    public:
        No *esquerda;
        No *direita;
        int valor;
 
        No(int valor){
            this->direita = NULL;
            this->esquerda = NULL;
            this->valor = valor;
        }
};
 
class ArvoreBinaria{
    public:
        No *raizArvore;

        ArvoreBinaria(){
            this->raizArvore = NULL;
        }

        bool vazio(){
            if (this->raizArvore == NULL){
                return true;
            } else {
                return false;
            }
        }
 
        void push(No *aux, int valor){
            if (vazio()){
                raizArvore = new No(valor);
                return;
            }

            if (valor < aux->valor){
                
                if (aux->esquerda == NULL){
                    aux->esquerda = new No(valor);
                } else {
                    this->push(aux->esquerda, valor);
                }

            } else {
                
                if (aux->direita == NULL){
                    aux->direita = new No(valor);
                } else {
                    this->push(aux->direita, valor);
                }
            }
        }

        void mostrarPreOrdem(No *aux) {
            if (aux != NULL) {
                cout << aux->valor << " ";
                this->mostrarPreOrdem(aux->esquerda);
                this->mostrarPreOrdem(aux->direita);
            }
        }

        void mostrarInOrdem(No *aux){
            if (aux != NULL){
                this->mostrarInOrdem(aux->esquerda);
                cout << aux->valor << " ";
                this->mostrarInOrdem(aux->direita);
            } 
        }

        void mostrarPosOrdem(No *aux){
            if (aux != NULL){
                this->mostrarPosOrdem(aux->esquerda);
                this->mostrarPosOrdem(aux->direita);
                cout << aux->valor << " ";
            }
        }
};
 
int main()
{
    ArvoreBinaria *arvoreBinaria = new ArvoreBinaria();
    
    arvoreBinaria->push(arvoreBinaria->raizArvore, 8);
    arvoreBinaria->push(arvoreBinaria->raizArvore, 3);
    arvoreBinaria->push(arvoreBinaria->raizArvore, 10);
    arvoreBinaria->push(arvoreBinaria->raizArvore, 1);
    arvoreBinaria->push(arvoreBinaria->raizArvore, 6);
    arvoreBinaria->push(arvoreBinaria->raizArvore, 4);
    arvoreBinaria->push(arvoreBinaria->raizArvore, 7);
    arvoreBinaria->push(arvoreBinaria->raizArvore, 14);
    arvoreBinaria->push(arvoreBinaria->raizArvore, 13);

    cout << "Pre ordem: ";
    arvoreBinaria->mostrarPreOrdem(arvoreBinaria->raizArvore);

    cout << "\nIn ordem: ";
    arvoreBinaria->mostrarInOrdem(arvoreBinaria->raizArvore);

    cout << "\nPós ordem: ";
    arvoreBinaria->mostrarPosOrdem(arvoreBinaria->raizArvore);

}
