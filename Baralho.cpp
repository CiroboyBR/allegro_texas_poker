#include "Carta.cpp"

class Baralho {

  private:
    int cartaTopo;
    Carta cartas[52];
  public:
    Baralho();
    Carta tiraCarta();
    bool vazio();
    void embaralha();
    void embaralha(int qtd);
    void imprime();
    void desalocaBMP();
    int qtdCartas();

};

Baralho::Baralho() {
  //Cartas de Ouro
  int num = 0;
  for(int i = 0; i < 13; i++)
    cartas[num++] = Carta(i + 2,   'O');

  //Cartas de Copas
  for(int i = 0; i < 13; i++)
    cartas[num++] = Carta(i + 2,   'C');

  //Cartas de Espadas
   for(int i = 0; i < 13; i++)
    cartas[num++] = Carta(i + 2,   'E');

  //Cartas de Paus
  for(int i = 0; i < 13; i++)
    cartas[num++] = Carta(i + 2,   'P');

  cartaTopo = 51;
}

Carta Baralho::tiraCarta() {
  if(!this->vazio()) {
    cartaTopo--;
    return cartas[cartaTopo + 1];
  } else
    return Carta(0, '0');
}

bool Baralho::vazio() {
  if(cartaTopo < 0)
    return true;
  else
    return false;
}

void Baralho::embaralha() {
  Carta cartasEmbaralhadas[52];
  bool copiadas[52]; // 0 a carta não foi copiada // 1 a carta já foi copiada do baralho principal para o baralho embaralhamento;
  int contador = 51; // conta as cartas que ja foram copiadas
  int numRand;

  for(int i = 0; i < 52; i++)
    copiadas[i] = false;//inicia todas as cartas como não copiadas

  while(contador > -1) { //enquanto ainda tiver carta no baralho original

    numRand = rand() % 52; //sorteia numero
    while(copiadas[numRand] == true)// enquanto o numero sorteado representar uma carta do baralho original que ja foi copiada para o baralho temporario, refaz o sorteio
      numRand = rand() % 52; //sorteia

    cartasEmbaralhadas[contador] = cartas[numRand];//o baralho temporario recebe a carta sorteada
    copiadas[numRand] = true;//marca a carta sorteada do vetor original como copiada
    contador--;//diminui o tamanho do baralho
  }
  //saiu do while pois todas as cartas do baralho original foram copiadas para o baralho temporário.

  for(int i = 0; i < 52; i++)//agora copia todas as cartas do baralho temporario para o baralho original
    cartas[i] = cartasEmbaralhadas[i];
}

void Baralho::embaralha(int qtd) {
  for(int i = 0; i < qtd; i++)
    embaralha();
}

void Baralho::imprime() {
  for(int i = 0; i <= cartaTopo; i++) {
    if(i % 13 == 0)
      cout << endl;
    cartas[i].imprime();
  }
  cout << endl << endl;
}

void Baralho::desalocaBMP() {
  for(int i = 0; i < 52; i++)
    cartas[i].destroyBMP();
}

int Baralho::qtdCartas() {
  return cartaTopo;
}
