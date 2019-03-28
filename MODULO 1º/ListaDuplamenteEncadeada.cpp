#include <bits/stdc++.h>

using namespace std;

class No{
    public:
        char item;
        No *proximo;
        No *anterior;
    
        No (char item){
            this->item = item;
            this->anterior = this->proximo = NULL;
    }
};
 
class ListaDupla{
    public:
        No *inicio;
        No *fim;
       
        ListaDupla(){
            fim = NULL;
            inicio = NULL;
        }
       
        void inserir(No *novo){
            if (!inicio){
                inicio = novo;
                fim = novo;
            }else{
                novo->anterior = fim;
                fim->proximo = novo;
                fim = fim->proximo;
            }
        }
       
        No* buscar(char letra){
            if (!inicio) return NULL;
           
            No *aux = inicio;
            while (aux != NULL){
                if (aux->item == letra)
                    return aux;
                aux = aux->proximo;
            }
            return NULL;
        }

        int remocao(char procurado){
            No *excluido = buscar(procurado);
            if (!excluido) return 0;
            if (excluido == inicio){
                inicio = inicio->proximo;
                delete(excluido);
            }else if (excluido == fim){
                fim = fim->anterior;
                fim->proximo = NULL;
                delete(excluido);
            }else{
                excluido->anterior->proximo = excluido->proximo;
                excluido->proximo->anterior = excluido->anterior;
                delete(excluido);
            }
            return 1;
        }
       
        void mostrar(){
            if (!inicio){
                cout << "Lista vazia.\n";
                return;
            }
            No *aux = inicio;
            while (aux != NULL){
                cout << aux->item << " ";
                aux = aux->proximo;
            }
        }
        void percorreInverso(){
            if (!inicio){
                cout << "Lista vazia.\n";
                return;
            }
            No *aux = fim;
            while (aux != NULL){
                cout << aux->item << " ";
                aux = aux->proximo;
            }
        }
};
 
int main(){
    int resp;
    char letra;
   
    ListaDupla *lp = new ListaDupla();
   
     lp->inserir(new No('A'));
     lp->inserir(new No('B'));
     lp->inserir(new No('C'));

     lp->remocao('B');
}