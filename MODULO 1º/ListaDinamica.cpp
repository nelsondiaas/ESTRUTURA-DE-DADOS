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
 
class ListaDinamica{
    public:
        No *inicio;
        No *fim;
        int contador;
 
        ListaDinamica(){
            inicio = NULL;
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
 
        int tamanhoLista(){
            No *aux = inicio;
            while(aux != NULL){
                contador++;
                aux = aux->proximo;
            }
            return contador;
        }
 
        void pushInicio(No *novo){
            if (vazia()){
                inicio = novo;
                fim = novo;
                contador++;
            }else{
                  novo->proximo = inicio;
                  inicio = novo;
                  contador++;
            }
        }
 
        void pushFim(No *novo){
            if (vazia()){
                inicio = novo;
                fim = novo;
                contador++;
            }else{  
                fim->proximo = novo;
                fim = novo;
                contador++;
            }
        }
 
        bool popInicio(){
            No *aux;
            if (vazia()){
                return false;
            }else{
                aux = inicio;
                inicio = inicio->proximo;
                delete(aux);
                contador--;
                return true;
            }
        }
     
        bool popFim(){
            No *aux = inicio;
            No *anterior = inicio;
            if (vazia()){
                return false;
            }else{
                while(aux->proximo != NULL){
                    anterior = aux;
                    aux = aux->proximo;
                }
                anterior->proximo = aux->proximo;
                delete(aux);
                contador--;
                return true;
            }
        }
};
 
int main()
{
    ListaDinamica *referencia = new ListaDinamica();
   
    referencia->pushFim(new No('A'));
    referencia->pushFim(new No('B'));
    referencia->pushFim(new No('C'));

    referencia->popFim();

}