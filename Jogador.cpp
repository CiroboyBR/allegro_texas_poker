#include <cstdio>
#include "Baralho.cpp"

using namespace std;

class Jogador {

  private:
    Carta cartas[2];
    string nome;
  public:
    Jogador();
    Jogador(string Nome);
    void setCarta(Carta C, int num);
    Carta getCarta(int num);
    string getNome();
};


Jogador::Jogador() {
 ;
}

Jogador::Jogador(string Nome) {
  nome = Nome;
}

void Jogador::setCarta(Carta C, int num) {
  if(num == 0 || num == 1)
    cartas[num] = C;
}

Carta Jogador::getCarta(int num) {
  if(num == 0 || num == 1)
    return cartas[num];
  else
    return Carta();
}

string Jogador::getNome(){
  return nome;
}
