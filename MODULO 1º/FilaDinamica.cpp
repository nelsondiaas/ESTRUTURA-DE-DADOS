#include <bits/stdc++.h>

using namespace std;

class No{
    public:
        char dados;
        No *proximo;

        No(char dados){
            this->dados = dados;
            this->proximo = NULL;
        }
};

class FilaDinamica{
    public:
        No *inicio;
        No *fim;
        int contador;
        
        FilaDinamica(){
            inicio = NULL;
            fim = NULL;
            contador = 0;
        }
        
        bool vazia(){
            if (inicio == NULL){
                return true;
            }else{
                return false;
            }
        }
        
        char primeiroElemento(){
            return inicio->dados;
        }
        
        int tamanhoFila(){
            No *aux = inicio;
            while(aux != NULL){
                contador++;
                aux = aux->proximo;
            }
            return contador;    
        }
        
        void push(No *novo){
            if (vazia()){
                inicio = novo;
                fim = novo;
            }else{
                fim->proximo = novo;
                fim = novo;
            }
        }

        char pop(){
            No *aux;
            if (vazia()){
                return '0';
            }else{
                aux = inicio;
                inicio = aux->proximo;
                delete(aux);
            }
        }        
};

int main()
{    
    FilaDinamica *referencia = new FilaDinamica();
    
    referencia->push(new No('A'));
    referencia->push(new No('B'));
    referencia->push(new No('C'));
    referencia->push(new No('D'));
    
    referencia->pop();
    
    
}