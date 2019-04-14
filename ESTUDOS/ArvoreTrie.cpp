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

        ArvoreTrie(){
            raiz = new NoTrie();
        }

        void insert(string key){
            NoTrie *auxNoTrie = raiz;
            NoTrie *novoNo = new NoTrie();
        
            for (int i=0; i < key.length(); i++){
                int index = key[i] - 'a';
                if (auxNoTrie->filho[index] == NULL){
                    auxNoTrie->filho[index] = novoNo;
                }
                auxNoTrie = auxNoTrie->filho[index];
            }
            auxNoTrie->fimDaPalavra = true;
        }    

        bool buscar(string key){
            NoTrie *auxNoTrie = raiz;
            
            for (int i=0; i < key.length(); i++){
                int index = key[i] - 'a';
                if (auxNoTrie->filho[index] == NULL){
                    return false;
                }
                auxNoTrie = auxNoTrie->filho[index];
            }
            return auxNoTrie != NULL && auxNoTrie->fimDaPalavra;
        }

        void verifica(bool buscar){
            if (buscar == 1){
                cout << "\nPresente na trie" << "\n";
            } else {
                cout << "\nNão presente na trie" << "\n";
            }
        }
};

int main()
{
    ArvoreTrie *arvoreTrie = new ArvoreTrie();

    arvoreTrie->insert("nelson");
    arvoreTrie->insert("felipe");
    arvoreTrie->insert("carlos");
    arvoreTrie->insert("geovane");
    arvoreTrie->insert("luan");

    arvoreTrie->verifica(arvoreTrie->buscar("nelsonnnn"));
    arvoreTrie->verifica(arvoreTrie->buscar("nel"));
    arvoreTrie->verifica(arvoreTrie->buscar("son"));
}



