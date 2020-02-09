#include <bits/stdc++.h>
#define MAX 10

using namespace std;

void swap(int *lista, int i, int j){
    int aux;
    aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;
}

void bublleSort(int *lista){
    for(int i=0; i<MAX-1; i++){
        for(int j=i+1; j<MAX; j++){
            if(lista[i] > lista[j]){
                swap(lista, i, j);
            }
        }
    }
}

void imprimir(int *lista){
    cout << "Ordenação BubbleSort: ";
    for(int i=0; i<MAX; i++){
        cout << lista[i] << " ";
    }
}

int main()
{
    int lista[MAX] = {3, 5, 6, 7, 7, 2, 1, 32, 54, 99};

    bublleSort(lista);

    imprimir(lista);

}