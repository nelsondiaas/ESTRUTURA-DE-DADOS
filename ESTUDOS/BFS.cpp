#include <bits/stdc++.h>

using namespace std;

class NoFila{
    public:
        int dados;
        NoFila *proximo;

        NoFila(int valor){
            this->dados = valor;
            this->proximo = NULL;
        }
};

class FilaDinamica{
    public:
        NoFila *inicio;
        NoFila *fim;
        
        FilaDinamica(){
            inicio = NULL;
            fim = NULL;
        }
        
        void push(int valor){
            NoFila *novoNo = new NoFila(valor);
            if (inicio == NULL){
                inicio = novoNo;
                fim = novoNo;
            }else{
                fim->proximo = novoNo;
                fim = novoNo;
            }
        }

        void popInicio(){
            NoFila *aux;
            aux = inicio;
            inicio = aux->proximo;
            delete(aux);
        }

        void popFim(){
            NoFila *aux = inicio;
            NoFila *anterior = inicio;
            
            while(aux != NULL){
                anterior = aux;
                aux = aux->proximo;
                if (aux->proximo == NULL){
                    break;
                }
            }
            fim = anterior;
            fim->proximo = NULL;
            anterior = NULL;
            aux = NULL;
            delete(anterior, aux);
        }       
};

class Grafico{
    public:
        int vertices;
        list<int> *adjacentes;

        Grafico(int vertice){
            this->vertices = vertice;
            this->adjacentes = new list<int>[vertice];
        }

        void adicionarBorda(int vertice, int w){
            this->adjacentes[vertice].push_back(w);
        }

        void BFS(int vertice){
            bool *visitado = new bool[this->vertices];
            for (int i=0; i < this->vertices; i++){
                visitado[i] = false;
            }
            FilaDinamica *fila = new FilaDinamica();
            visitado[vertice] = true;
            fila->push(vertice);

            list<int>::iterator i; 

            while(fila->inicio != NULL){
                vertice = fila->inicio->dados;
                cout << vertice << " ";
                fila->popInicio();

                for (i = adjacentes[vertice].begin(); i != adjacentes[vertice].end(); ++i){
                    if (visitado[*i] != true){
                        visitado[*i] = true;
                        fila->push(*i);
                    }
                }
            }
        }

};


int main()
{
    Grafico *grafico = new Grafico(4);

    grafico->adicionarBorda(0, 1);
    grafico->adicionarBorda(0, 2);
    grafico->adicionarBorda(1, 2);
    grafico->adicionarBorda(2, 0);
    grafico->adicionarBorda(2, 3);
    grafico->adicionarBorda(3, 3);

    cout << "Apartir do vertice 2: ";
    grafico->BFS(2);

}


