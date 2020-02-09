#include <bits/stdc++.h>
#define MAX 10

using namespace std;

void swap(int *lista, int i, int j){
    int aux;
    aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;
}

int dividir(int *lista, int esquerda, int direita){
    int contador = esquerda;
    for(int i=esquerda+1; i<=direita; i++){
        if (lista[i] < lista[esquerda]){
             contador++;
            swap(lista, i, contador);
        }
    }
    swap(lista, esquerda, contador);
    return contador;
}

void quickSort(int *lista, int esquerda, int direita){
    int posicao;
    if (esquerda < direita){
        posicao = dividir(lista, esquerda, direita);
        quickSort(lista, esquerda, posicao-1);
        quickSort(lista, posicao+1, direita);          
    }
}

void imprimir(int *lista){
    cout << "Ordenação KickSort: ";
    for(int i=0; i<MAX; i++){
        cout << lista[i] << " ";
    }
}

int main()
{
    int lista[MAX] = {3, 5, 6, 7, 7, 2, 1, 32, 54, 99};

    quickSort(lista, 0, MAX-1);

    imprimir(lista);

}