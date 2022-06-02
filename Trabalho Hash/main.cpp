#include <cstdlib>
#include <iostream>
#include "func_hash.h"
#include <dirent.h>
#include <fstream>

using namespace std;

void listaMenuHash(){
    system("cls"); 
    cout << "Implementacao do Hash" << endl;
    cout<<"1 - Reiniciar"<<endl;
    cout<<"2 - Inserir"<<endl;
    cout<<"3 - Remover"<<endl;
    cout<<"4 - Consultar Especifico - pelo codigo"<<endl;
    cout<<"5 - Consultar Especifico - pelo nome"<<endl;
    cout<<"6 - Listar"<<endl;
    //cout<<"7 - Gravar arquivo(s)"<<endl;
    cout<<"0 - Sair"<<endl<<endl;
}


void executaHash(){
    hash *tabela = new hash();
    
    int opcao;
    
    pessoa p;
    int codigo;
    string nome;
    string nomeArq;
    string str = "arq0";
	char buffer[10];
	int indice;
	fstream arq;
    
    DIR *dir;
    struct dirent *lsdir;

	/*Mudar o diretório para a pasta que está o projeto!!!*/
    dir = opendir("C:\Users\Alyson\Documents\Facul\4Fase\Estrutura de Dados ll\\Trabalho Hash");
    
    //Percorrer todos os arquivos do diretório
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
    	nomeArq = lsdir->d_name;
		if (nomeArq.find(str) != string::npos) {
		    
		    indice = atoi(nomeArq.substr(4,1).c_str());
		    
			itoa(indice, buffer, 10);
		    string nomeArquivo = "arq0";
			nomeArquivo.append(buffer).append(".txt");
			
    		arq.open(nomeArquivo.c_str(), ios::app| ios::in);
       
		    while(!arq.eof() && arq.get()>0){
				arq>>codigo>>nome;
				p.setcodigo(codigo);
              	p.setnome(nome);
              	p.imprimir();
              
              	tabela-> insere(p);
			}
			arq.close();
		} 
    }
    closedir(dir);
	
    do{
        listaMenuHash();

        cout << "Informe a opcao: ";
        cin >> opcao;
        
		switch(opcao){
			case 0:
        		exit(0);
              	break;
        	case 1:
              	delete tabela;
              	tabela = new hash();
              	break;
              
           case 2:
              	cout << "Informe o codigo: ";
              	cin >> codigo;
              	cout << "Informe o nome: ";
              	cin >> nome;
              
              	p.setcodigo(codigo);
              	p.setnome(nome);
              
              	tabela-> insere(p);
              	break;
              
          	case 3:              
            	cout << "Informe o codigo: ";
              	cin >> codigo;
              
              	tabela-> remove(codigo);
              	break;
           	case 4:
              
              	cout << "Informe o codigo: ";
              	cin >> codigo;
              
              	tabela-> consulta(codigo);
              	break;
              
           	case 5:
              	cout << "Informe o nome: ";
              	cin >> nome;
              
              	tabela-> consultanome(nome);
              	break;
              
           	case 6:
              	tabela->imprimirhash();                 
              	break;
              
			/*case 7:
        		tabela->salvaArquivo();
        		break;*/
				              
           default:
              cout << "Opcao invalida" << endl;        
        }
        system("PAUSE");
    }while(opcao != 0);
}



int main()
{	
	executaHash();

	return EXIT_SUCCESS;
}
