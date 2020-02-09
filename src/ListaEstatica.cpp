#include <bits/stdc++.h>
#define MAX 6
 
using namespace std;
 
class Lista{
    public:
        char lista[MAX];
        int frente;
        int tras;
       
        Lista(){
            frente = 0;
            tras = -1;
        }
       
        bool lista_vazia(){
            if (frente > tras){
                return true;
            }else{
                return false;
            }
        }
       
        bool lista_cheia(){
            if (tras == MAX-1){
                return true;
            }else{
                return false;
            }  
        }
       
        int lista_tamanho(){
            return (tras+1);
        }
       
        bool pushInicio(char elemento){
            if (lista_cheia()){
                return false;
            }else{  
                int i = tras+1;
                while(i>frente){
                    lista[i] = lista[i-1];
                    i--;          
                }
                lista[frente] = elemento;
                tras++;
                return true;
            }
        }
       
        bool pushFim(char elemento){
            if (lista_cheia()){
                return false;
            }else{  
                tras++;
                lista[tras] = elemento;
                return true;
            }
        }
       
        bool inserirPosicao(char elemento, int posicao){
            if (lista_cheia()){
                return false;
            }else{  
                int i = tras+1;
                while(i>posicao){
                    lista[i] = lista[i-1];
                    i--;          
                }
                lista[posicao] = elemento;
                tras++;
                return true;
            }
        }
       
        char popInicio(){
            if (lista_vazia()){
                return false;
            }else{
                char elemento = lista[frente];
                int i = frente;
                while(i<tras){
                    lista[i] = lista[i+1];
                    i++;      
                }
                tras--;
                return elemento;
            }      
        }
       
        char popFim(){
            if (lista_vazia()){
                return false;
            }else{
                int elemento = lista[tras];
                tras--;
                return elemento;
            }  
        }
       
        char popMeio(int posicao){
            if (lista_vazia()){
                return false;
            }else{
                if ((posicao > frente) && (posicao < tras)){
                    int elemento = lista[posicao];
                    int i = posicao;
                    while(i<tras){
                        lista[i] = lista[i+1];
                        i++;          
                    }
                    tras--;
                    return elemento;
                }else{
                    return false;
                }                                                  
            }
        }
       
        char buscaPosicao(int posicao){
            if(lista_vazia()){
                return false;
            }else{
                return lista[posicao];
            }  
        }
 
};
 
int main()
{
    Lista *referenciaLista = new Lista();
   
    referenciaLista->pushInicio('a');
    referenciaLista->pushInicio('b');
    referenciaLista->pushInicio('c');
    referenciaLista->pushInicio('d');
    referenciaLista->pushInicio('e');
    referenciaLista->pushInicio('z', 6);
   
    cout << referenciaLista->buscaPosicao(6);
   
}