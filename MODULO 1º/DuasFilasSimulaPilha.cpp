#include <bits/stdc++.h>

using namespace std;

class No{
    public:
        char nome;
        No *prox;

        No(char n){
            this->nome = n;
            this->prox = NULL;
        }
};

class Fila{
    public:
        No *inicio;
        No *fim;

        Fila(){
            inicio = NULL;
            fim = NULL;
        }

        void push(No *novo){
            if (inicio == NULL){
                inicio = novo;
                fim = novo;
            }else{
                fim->prox = novo;
                fim = novo;
            }
        }

        char pop(){
            char nome;
            if (inicio != NULL){
                nome = inicio->nome;
                inicio = inicio->prox;
            }
            return nome;
        }
};

class PilhaFeitaPorFilas{
    public:
        Fila *fila;

        PilhaFeitaPorFilas(){
            fila = new Fila();
        }

        void push(No *novo){

            Fila *auxiliar = new Fila();
            while (fila->inicio != NULL){            // tranfere todos os elementos para outra fila
                auxiliar->push(new No(fila->pop()));
            }
            fila->push(novo);                        // Insere novo elemento
            while (auxiliar->inicio != NULL){        // Retorna todos os elementos para a lista principal
            fila->push(new No(auxiliar->pop()));
            }
        }

        char pop(){
            return fila->pop();
        }
};


int main()
{
    PilhaFeitaPorFilas *pilha = new PilhaFeitaPorFilas();
    cout << "inserindo elementos na pilha" << "\n";
    cout << "Primeiro: A\n";
    pilha->push(new No('A'));
    cout << "Segundo: B\n";
    pilha->push(new No('B'));
    cout << "Terceiro: C\n";
    pilha->push(new No('C'));

    cout << "\nRemovendo elementos da pilha" << "\n";
    cout << "Primeiro: " << pilha->pop() << "\n";
    cout << "segundo : " << pilha->pop() << "\n";
    cout << "terceiro: " << pilha->pop() << "\n";

}