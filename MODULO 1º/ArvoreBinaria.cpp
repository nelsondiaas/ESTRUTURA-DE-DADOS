#include <bits/stdc++.h>

using namespace std;

class No
{
    public:
        No *esquerda;
        No *direita;
        int valor;
    
        No(int v) {
            valor = v;
            esquerda = direita = nullptr;
        }
};

class Arvore
{
    public:
    No *raiz;
    
    Arvore() {
        raiz = nullptr;
    }
    
    bool vazia()
    {
        return raiz == nullptr;
    }
    
    void inserir(No *aux, int valor) 
    {
        if (vazia())
        {
            raiz = new No(valor);
            return;
        }
        
        if (!aux) {
            aux = new No(valor);
            return;
        }
    
        if (valor < aux->valor)
        {
            if (!aux->esquerda) 
                aux->esquerda = new No(valor);
            else
                inserir(aux->esquerda, valor);
        }
        else {
            if (!aux->direita) 
                aux->direita = new No(valor);
            else
                inserir(aux->direita, valor);
        }
    
    }
    
    void mostrar(No *aux) {
        if (aux) {
            cout << aux->valor << " ";
            mostrar(aux->esquerda);
            mostrar(aux->direita);
        }
    }
    
};

int main() 
{
    Arvore *arvore = new Arvore();
    arvore->inserir(arvore->raiz, 10);
    arvore->inserir(arvore->raiz, 7);
    arvore->inserir(arvore->raiz, 5);
    arvore->inserir(arvore->raiz, 9);
    
    arvore->mostrar(arvore->raiz);
    
}