#include <cstdio>
#include "Jogador.cpp"

using namespace std;

#define QTDJOGADORES 5

class Mesa {
  private:
    Carta cartasComunitarias[5];
    Carta combinacao[7];
    Jogador jogadores[QTDJOGADORES];
    bool jogadoresAtivos[QTDJOGADORES];
    Baralho B;
    long long int pote;
  public:
    Mesa();
    void iniciaMao();
    void aposstas();
    void mostraCarta(int num);
    void flop();
    void turn();
    void river();
    void addJogador(Jogador J, int pos);
    void distribuiCartas();
    void imprimeJogadores();
    void ordenaCombinacao();
    Carta *checaRoyalFlush(Jogador J, int n);
    Carta *checaPar(Jogador J);
};

Mesa::Mesa() {
  for (int i = 0; i < QTDJOGADORES; i++) {
    jogadoresAtivos[i] = false;
    jogadores[i] = Jogador("Vazio");
  }

}

void Mesa::iniciaMao() {
  B.desalocaBMP();
  B = Baralho();
  B.embaralha(30);

  distribuiCartas();

  imprimeJogadores();
}

void Mesa::flop() {
  textout(screen, font, "Flop", 90, 90, Cor::vermelho());
  cartasComunitarias[0] = B.tiraCarta();
  cartasComunitarias[1] = B.tiraCarta();
  cartasComunitarias[2] = B.tiraCarta();

  cartasComunitarias[0].desenha(60, 100);
  cartasComunitarias[1].desenha(90, 100);
  cartasComunitarias[2].desenha(120, 100);
}

void Mesa::turn() {
  textout(screen, font, "Turn", 170, 90, Cor::vermelho());
  cartasComunitarias[3] = B.tiraCarta();

  cartasComunitarias[3].desenha(170, 100);
}

void Mesa::river() {
  textout(screen, font, "River", 220, 90, Cor::vermelho());
  cartasComunitarias[4] = B.tiraCarta();

  cartasComunitarias[4].desenha(220, 100);

  #ifdef WIN32
    system("cls");
  #endif // WIN32

  for(int i = 0; i < 7; i++)
    if(jogadoresAtivos[i] == true)
      checaRoyalFlush(jogadores[i], i);

}

void Mesa::addJogador(Jogador J, int pos) {
  if(jogadoresAtivos[pos] == false) {
    jogadoresAtivos[pos] = true;
    jogadores[pos] = J;
  } else
    printf("\nPosicao Ocupada!");
}

void Mesa::distribuiCartas() {
  for(int x = 0; x < 2; x++)
    for(int i = 0; i < QTDJOGADORES; i++)
      if(jogadoresAtivos[i] == true)
        jogadores[i].setCarta(B.tiraCarta(), x);

}

void Mesa::imprimeJogadores() {
  for(int x = 0; x < 2; x++)
    for(int i = 0; i < QTDJOGADORES; i++)
      if(jogadoresAtivos[i] == true) {
        jogadores[i].getCarta(x).desenha( (i * 80) + (x * 30) + 10, 250 );
        if(x == 0)
          textout(screen, font, jogadores[i].getNome().c_str(), i * 80 + 10, 240, Cor::azul());
      }

}

Carta *Mesa::checaRoyalFlush(Jogador J, int n) {

  combinacao[0] = J.getCarta(0);
  combinacao[1] = J.getCarta(1);

  for(int i = 2; i < 7; i++)
    combinacao[i] = cartasComunitarias[i - 2];

  ordenaCombinacao();

  printf("\nJogador %d: ", n);
  for(int i = 0; i < 7; i++) {
    combinacao[i].imprime();
  }

  return combinacao;
}


Carta *Mesa::checaPar(Jogador J) {

  combinacao[0] = J.getCarta(0);
  combinacao[1] = J.getCarta(1);

  for(int i = 2; i < 7; i++)
    combinacao[i] = cartasComunitarias[i - 2];
  ordenaCombinacao();
  printf("\nCombinacao: ");
  for(int i = 0; i < 7; i++) {
    combinacao[i].imprime();
  }

  return combinacao;
}

void Mesa::ordenaCombinacao() {
Carta tmp;

  for(int i = 0 ;i < 7; i++)
    for(int j = 0; j < 7; j++)
      if(i != j && combinacao[i].getValor() < combinacao[j].getValor()){
        tmp = combinacao[i];
        combinacao[i] = combinacao[j];
        combinacao[j] = tmp;
      }

}

