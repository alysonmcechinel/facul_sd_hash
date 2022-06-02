#include "func_pessoa.h"
#include <list>
#include <fstream>

#define TAM 5   

using namespace std;

class hash{
   private:
      list<pessoa> plist[TAM];

   public:
      hash();
      ~hash();
      void insere(pessoa p);
      void remove(int cod);
      void consulta(int cod);
      void consultanome(string nome);
      void imprimirhash();
      int calc_hash(int cod);
      //void salvaArquivo();
};


hash::hash(){};

hash::~hash(){
   for(int i = 0; i < TAM; i++){
      plist[i].clear();
   }
}

int hash::calc_hash(int cod) {
	return cod % TAM;
}

void hash::insere(pessoa p){
    int classe = calc_hash(p.getcodigo());
    fstream arq;
    char buffer[10];
    itoa(classe, buffer, 10);
    string nome = "arq0";
    nome.append(buffer).append(".txt");
    arq.open(nome.c_str(), ios::out);
    arq << p.getcodigo() << p.getnome() << "\n";
    arq.close();
    
    plist[classe].push_back(p);
}



void hash::remove(int cod){
    int classe = calc_hash(cod);
    
    list<pessoa> *h = &plist[classe];
    
    if(h->empty()){
        cout << "Registro inexistente. Tabela hash vazia." << endl;
        return;    
    }
    
    list<pessoa>::iterator it;
    
    bool existeelemento = false;
    for(it = h->begin(); it != h->end(); it++){
        if(it->getcodigo() == cod){
           existeelemento = true;
           break;
        }
    }
    
    if(existeelemento){
       h->erase(it);
    }else{
       cout << "Registro inexistente. Não foi possível excluir o elemento." << endl;
    }
}

void hash::consulta(int cod){
    
    int classe = calc_hash(cod);
    list<pessoa> h = plist[classe];
    
    if(h.empty()){
        cout << "Registro inexistente. Tabela hash vazia." << endl;
        return;    
    }
    
    list<pessoa>::iterator it;
    
    bool existeelemento = false;
    for(it = h.begin(); it != h.end(); it++){
        if(it->getcodigo() == cod){
           existeelemento = true;
           break;
        }
    }
    
    if(existeelemento){
       
       it->imprimir();
    }else{
       cout << "Registro inexistente. O elemento nao esta na lista." << endl;
    }
}


void hash::consultanome(string nome){
    list<pessoa> h;
    list<pessoa>::iterator it;
    bool existeelemento = false;
    
	for(int classe = 0; classe < TAM; classe++){
        h = plist[classe];
        for(it = h.begin(); it != h.end(); it++){
            if(it->getnome() == nome){
               existeelemento = true;
               it->imprimir();
            }
        }
    }
    
    if(!existeelemento){
       cout << "Elemento nao encontrado" << endl;    
    }
}


void hash::imprimirhash(){
    list<pessoa> h;
    list<pessoa>::iterator it;
    
    for(int classe = 0; classe < TAM; classe++){
        h = plist[classe];
        for(it = h.begin(); it != h.end(); it++){
           it->imprimir();
        }
    }
}

/*void hash::salvaArquivo(){
	list<pessoa> h;
    list<pessoa>::iterator it;
	fstream arq[5];
	string nome;
	char buffer[10];
	
	for(int i = 0; i < TAM; i++){
		h = plist[i];
		itoa(i, buffer, 10);
		nome = "arq";
		nome.append(buffer).append(".txt");
		arq[i].open(nome.c_str(), ios::app| ios::out);
		for(it = h.begin(); it != h.end(); it++){
			arq[i] << it->getcodigo() << "\t" << it->getnome();
		}
		arq[i].close();
	}
}*/
