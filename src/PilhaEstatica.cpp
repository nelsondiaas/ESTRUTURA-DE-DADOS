#include <bits/stdc++.h>
#define MAX 50

using namespace std;
 
class PilhaStatita{
    public:
        char pilha[MAX];
        int topo;
           
        Pilha(){
            topo = 0;
        }
       
        bool vazia(){
            if(topo == 0){
                return true;
            }else{
                return false;
            }
        }
       
        bool cheia(){
            if(topo == MAX){
                return true;
            }else{
                return false;
            }
        }
           
        bool push(char valor){
            if(cheia() == true){
                return false;
            }else{    
                pilha[topo] = valor;
                topo++;    
                return true;    
            }                
        }
           
        char pop(){
            if(vazia() == true){
                return -1;
            }else{    
                topo--;
                return pilha[topo];    
            }
        }

        char espiandoTopo(){
			if (vazia()){
                return '0';
            }else{
                return topo;
            }
		}   
};

bool verificando(string elemento){
	
	Pilha *referenciaPilhaEstatica = new Pilha();
	
	int indice_elemento = 0;
	
	while(elemento[indice_elemento]){
       
        if ((elemento[indice_elemento] == '(') || (elemento[indice_elemento] == '[') || (elemento[indice_elemento] == '{')){
            referenciaPilhaEstatica->push(elemento[indice_elemento]);

        }else{
			if (elemento[indice_elemento] == ')'){
				if (referenciaPilhaEstatica->pop() != '('){
					return false;	
				}
			}
			else if(elemento[indice_elemento] == '}'){
				if (referenciaPilhaEstatica->pop() != '{'){
					return false;
				}	
			}
			else if(elemento[indice_elemento] == ']'){
				if (referenciaPilhaEstatica->pop() != '['){
					return false;
				}	
			}  
    	}
 	indice_elemento++;
	}
	return referenciaPilhaEstatica->vazia();
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