#include <string>
#include <iostream>

using namespace std;

class pessoa{
   private:
      int codigo;
      string nome;
   
   public:
      pessoa();
      pessoa(int codigo, string nome);
      ~pessoa();
      int getcodigo();
      void setcodigo(int codigo);
      string getnome();
      void setnome(string nome);
      void imprimir();
};

pessoa::pessoa(){}

pessoa::pessoa(int codigo, string nome){
  this->codigo = codigo;
  this->nome = nome;
}

pessoa::~pessoa(){}

int pessoa::getcodigo(){
  return codigo;
}
void pessoa::setcodigo(int codigo){
   this->codigo = codigo;
}
string pessoa::getnome(){
   return nome;
}
void pessoa::setnome(string nome){
   this->nome = nome;
}
void pessoa::imprimir(){
  cout << "Codigo: " << codigo << " Nome: " << nome << endl;
}
