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

        int primeiroDaFila(){
            return this->inicio->dados;
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

class Grafo{
    public:
        int vertices; // número de vértices
        list<int> *adjacentes; // ponteiro para um array contendo as listas de adjacências

        Grafo(int vertice){ // Construtor
            this->vertices = vertice;
            this->adjacentes = new list<int>[vertice]; // cria as listas
        }

        void adicionarAresta(int vertice1, int vertice2){ // adiciona uma aresta no grafo
            this->adjacentes[vertice1].push_back(vertice2); // adiciona vértice v2 à lista de vértices adjacentes de v1
        }

        /*faz uma BFS a partir de um vértice*/
        void BFS(int vertice){
            bool visitado[this->vertices]; // vetor de visitados
            for (int i=0; i < this->vertices; i++){
                visitado[i] = false;
            }
            FilaDinamica *fila = new FilaDinamica();
            visitado[vertice] = true; // marca como visitado
            fila->push(vertice);

            list<int>::iterator interador; 

            while(fila->inicio != NULL){
                vertice = fila->primeiroDaFila();
                cout << "Visitando vertice: " << vertice << "...\n";
                fila->popInicio();

                for (interador = adjacentes[vertice].begin(); interador != adjacentes[vertice].end(); ++interador){
                    if (visitado[*interador] != true){
                        visitado[*interador] = true; // marca como visitado
                        fila->push(*interador); // insere na fila
                    }
                }
            }
        }

};


int main()
{
    Grafo *grafo = new Grafo(20);

    grafo->adicionarAresta(1, 2);
    grafo->adicionarAresta(1, 3);
    grafo->adicionarAresta(1, 3);
    grafo->adicionarAresta(1, 4);
    grafo->adicionarAresta(2, 5);
    grafo->adicionarAresta(3, 6);
    grafo->adicionarAresta(3, 7);
    grafo->adicionarAresta(4, 8);
    grafo->adicionarAresta(5, 9);
    grafo->adicionarAresta(6, 10);

    grafo->BFS(1);

}

/*
              GRAFO
              
                1
              / | \
             2  3  4
            /  / \  \
           5  6   7  8
          /   |
         9    10

    BFS:  
    Intuitivamente, você começa pelo vértice raiz e explora todos os vértices vizinhos. 
    Então, para cada um desses vértices mais próximos, exploramos os seus vértices vizinhos 
    inexplorados e assim por diante, até que ele encontre o alvo da busca.
*/


