#include <bits/stdc++.h>
#define MAX 15

using namespace std;

class Fila{
	public:
		int frente;
		int tras;
		char fila[MAX];
		
		Fila(){
			frente = 0;
			tras = -1;
		}
		
		bool filaVazia(){
			if (frente > tras){
				return true;
			}else{
				return false;
			}
		}
		
		bool filaCheia(){
			if (tras == MAX-1){
				return true;
			}else{
				return false;
			}
		}
		
		bool push(char valor){
			if (filaCheia()){
				return false;
			}else{
				tras++;
				fila[tras] = valor;
				return true;
			}
		}
		
		char pop(){
            if(filaVazia() == true){
                return '0';
            }else{    
				return fila[frente++];  
            }
        } 
		
		int filaTamanho(){
			return (tras - frente) + 1;
		}
		
		char espiarFila(){
			if (filaCheia()){
				return -1;
			}else{	
				int indice = 0;
				while(indice < filaTamanho()){
					cout << fila[indice];
				indice++;		
				}
			}
		}	
};

int main()
{
	
	Fila *referencia_fila = new Fila();
	
	referencia_fila->push('A');
	referencia_fila->push('B');
	referencia_fila->push('C');
	
	cout << referencia_fila->espiarFila() << "<- Fila" << "\n\n";
	
	cout << referencia_fila->filaTamanho() << " <- Tamanho da fila" << "\n";
	cout << referencia_fila->pop() << " <- Pop" << "\n\n";
	
	cout << referencia_fila->filaTamanho() << " <- Tamanho da fila" << "\n";
	cout << referencia_fila->pop() << " <- Pop" << "\n\n";
	
	cout << referencia_fila->filaTamanho() << " <- Tamanho da fila" << "\n";
	cout << referencia_fila->pop() << " <- Pop" << "\n\n";
	
	cout << referencia_fila->filaTamanho() << " <- Tamanho da fila" << "\n";
	cout << referencia_fila->pop() << " <- Pop" << "\n\n";
	
}