#include <bits/stdc++.h>
#define MAXIMO_CARACTER 266

using namespace std;

class SuffixTrieNo{
    public:
        SuffixTrieNo *filho[MAXIMO_CARACTER];
        list<int> *indice;

        SuffixTrieNo(){
            this->indice = new list<int>;
            for (int i=0; i < MAXIMO_CARACTER; i++){
                this->filho[i] = NULL;
            }
        }

        void inserirSuffix(string text, int index){
            this->indice->push_back(index);

            if (text.length() > 0){
                char textIndex = text.at(0);

                if (this->filho[textIndex] == NULL){
                    this->filho[textIndex] = new SuffixTrieNo();
                }
                this->filho[textIndex]->inserirSuffix(text.substr(1), index + 1);
            }
        }

        list<int> *buscar(string text){
            if (text.length() == 0){
                return this->indice;
            }

            if (this->filho[text.at(0)] != NULL){
                return this->filho[text.at(0)]->buscar(text.substr(1));
            } else {
                return NULL;
            }
        }
};

class SuffixArvoreTrie{
    public:
        SuffixTrieNo *raiz = new SuffixTrieNo();

        SuffixArvoreTrie(string text){
            for (int i=0; i < text.length(); i++){
                this->raiz->inserirSuffix(text.substr(i), i);
            }
        }

        void buscarPadraoArvore(string padrao){
            list<int> *resultado = this->raiz->buscar(padrao);

            if (resultado == NULL){
                cout << "Padrão não encontrado" << "\n";
            } else {
                
                int tamanhoPadrao = padrao.length();
                for (int i: *resultado){
                    cout << "Padrão encontrado na posição: " << i - tamanhoPadrao <<"\n";
                }
            } 
        }
};

int main()
{
    string text = "jogosanimesseriess";
    
    SuffixArvoreTrie *suffixTriePadrao = new SuffixArvoreTrie(text);
    suffixTriePadrao->buscarPadraoArvore("ss");

}
