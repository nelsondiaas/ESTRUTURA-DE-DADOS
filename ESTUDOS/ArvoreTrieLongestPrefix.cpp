#include <bits/stdc++.h>
#define TAMANHO_DO_ALFABETO 26

using namespace std;

class NoTrie{
    public:
        NoTrie *filho[TAMANHO_DO_ALFABETO];
        bool fimDaPalavra;
        
        NoTrie(){
            this->fimDaPalavra = false;
            for (int i=0; i < TAMANHO_DO_ALFABETO; i++){
                this->filho[i] = NULL;
            }
        }
};

class ArvoreTrie{
    public:
        NoTrie *raiz;
        int index;

        ArvoreTrie(){
            raiz = new NoTrie();
        }

        void insert(string key){
            NoTrie *auxNoTrie = raiz;
        
            for (int i=0; i < key.length(); i++){
                int index = key[i] - 'a';
                if (auxNoTrie->filho[index] == NULL){
                    auxNoTrie->filho[index] = new NoTrie();
                }
                auxNoTrie = auxNoTrie->filho[index];
            }
            auxNoTrie->fimDaPalavra = true;
        }    

        int contadorFilhos(NoTrie *auxNoTrie){
            int contador = 0;
            for (int i=0; i < TAMANHO_DO_ALFABETO; i++){
                if (auxNoTrie->filho[i] != NULL){
                    contador++;
                    index = i;
                }
            }
            return contador;
        }

        string percorrerTrie(){
            NoTrie *auxNoTrie = raiz;
            string prefix;

            while(contadorFilhos(auxNoTrie) == 1 && auxNoTrie->fimDaPalavra == false){
                auxNoTrie = auxNoTrie->filho[index];
                prefix.push_back('a' + index);
            }
            return prefix;
        }
};

int main()
{
    ArvoreTrie *arvoreTrie = new ArvoreTrie();

    arvoreTrie->insert("geeksforgeeks");
    arvoreTrie->insert("geeks");
    arvoreTrie->insert("geek");
    arvoreTrie->insert("geezer");

    cout << "O prefixo comum mais longo é: " << arvoreTrie->percorrerTrie();
   
}



