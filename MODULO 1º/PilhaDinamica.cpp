#include <bits/stdc++.h>

using namespace std;

class No{
	public:
		char item;
		No *proximo;

		No(char item){
			this->item = item;
			this->proximo = NULL;
		}
};

class PilhaDinamica{
	public:
		No *topo;
		int pilha_tamanho;
		
		PilhaDinamica(){
		    topo = NULL;
			pilha_tamanho = 0;	
		}
		
		bool vazia(){
			if (topo == NULL){
				return true;
			}else{
				return false;
			}
		}
		
		int tamanhopilha(){
			No *aux = topo;
			while(aux != NULL){
				pilha_tamanho++;
				aux = aux->proximo;
			}
			return pilha_tamanho;
		}
		
		bool push(No *novo){
			if (vazia()){ 
				topo = novo;
				pilha_tamanho++;
			}else{	
                novo->proximo = topo;
				topo = novo;
				pilha_tamanho++;
                return true;
			}
		}
		
		char pop(){
			No *TEMP;
			
			if (vazia()){
				return false;
			}else{
				char elemento = topo->item;
				TEMP = topo;
				topo = topo->proximo;
				delete(TEMP);
				pilha_tamanho--;
				return elemento;
			}
		}
		
		char espiandoTopo(){
			if (vazia()){
                return '0';
            }else{
                return topo->item;
            } 
		}
};

bool verificando(string elemento){

	PilhaDinamica *referenciapilhaDinamica = new PilhaDinamica();

	int indice_elemento = 0;
	
	while(elemento[indice_elemento]){
       
        if ((elemento[indice_elemento] == '(') || (elemento[indice_elemento] == '[') || (elemento[indice_elemento] == '{')){
            referenciapilhaDinamica->push(new No(elemento[indice_elemento]));

        }else{
			if (elemento[indice_elemento] == ')'){
				if (referenciapilhaDinamica->espiandoTopo() != '('){
					return false;	
				}else{
                    referenciapilhaDinamica->pop();
                }
			}
			else if(elemento[indice_elemento] == '}'){
				if (referenciapilhaDinamica->espiandoTopo() != '{'){
					return false;
				}else{
                    referenciapilhaDinamica->pop();
                }	
			}
			else if(elemento[indice_elemento] == ']'){
				if (referenciapilhaDinamica->espiandoTopo() != '['){
					return false;
				}else{
                    referenciapilhaDinamica->pop();
                }	
			}  
    	}
 	indice_elemento++;
	}
	return referenciapilhaDinamica->vazia();
}

void resultado(string elemento){
	if (verificando(elemento) == true){
		cout << "\n" << elemento << " <- CORRETO!" <<"\n";
	}else{
		cout << "\n" << elemento << " <- ERRADO!" <<"\n";
	}
}

int main()
{	
	string a = ("{g}[(hj)]k");    
	resultado(a);

	string b = ("a + [b + (2*c*d + 2)]");   
	resultado(b);
	
	string c = ("a + b + (2*c*d + 2)]");
	resultado(c);
	
	string d = ("a +( b + 2*c*d + 2)]");
	resultado(d);
	
	string f = ("a +( b + 2*c*d + 2))");
	resultado(f);
	
	string g = ("a + [b + (2*c*d + 2])");
	resultado(g);
	
	string h = ("a + [b + (2*c*d + 2");
	resultado(h);
	
	string i = ("a + b + 2*c*d + 2])");
	resultado(i);
	
	string j = ("a + [b + [2*c*d + 2]]");
	resultado(j);
	
	string l = ("{[a + b] + ({2*c*d} + 2)}");
	resultado(l);
	
}