#include <cstdio>
#include <allegro.h>
#include "Cor.cpp"
#include "Naipe.cpp"

using namespace std;

class Carta {

private:
  int valor;
  char naipe;
  BITMAP *img;
public:
  Carta();
  Carta(int Valor, char Naipe);
  int getValor();
  char getNaipe();
  void setValor(int Valor);
  void setNaipe(char Naipe);
  void imprime();
  void desenha(int W, int H);
  void destroyBMP();

};

Carta::Carta() {
  ;
}

Carta::Carta(int Valor, char Naipe) {
  valor = Valor;
  naipe = Naipe;

  img = create_bitmap(32, 64);
  if(naipe == 'P') {
    rectfill(img, 0, 0, 32, 64, Cor::verde());
    masked_blit(paus, img, 0, 0, 0, 32, 32, 32);
  } else if(naipe == 'E') {
    rectfill(img, 0, 0, 32, 64, Cor::cinza());
    masked_blit(espadas, img, 0, 0, 0, 32, 32, 32);
  } else if(naipe == 'O') {
    rectfill(img, 0, 0, 32, 64, Cor::ouro());
    masked_blit(ouro, img, 0, 0, 0, 32, 32, 32);
  } else if(naipe == 'C') {
    rectfill(img, 0, 0, 32, 64, Cor::azul());
    masked_blit(copas, img, 0, 0, 0, 32, 32, 32);
  }

  if(valor == 2)
    masked_blit(c2, img, 0, 0, 0, 0, 32, 32);
  else if(valor == 3)
    masked_blit(c3, img, 0, 0, 0, 0, 32, 32);
  else if(valor == 4)
    masked_blit(c4, img, 0, 0, 0, 0, 32, 32);
  else if(valor == 5)
    masked_blit(c5, img, 0, 0, 0, 0, 32, 32);
  else if(valor == 6)
    masked_blit(c6, img, 0, 0, 0, 0, 32, 32);
  else if(valor == 7)
    masked_blit(c7, img, 0, 0, 0, 0, 32, 32);
  else if(valor == 8)
    masked_blit(c8, img, 0, 0, 0, 0, 32, 32);
  else if(valor == 9)
    masked_blit(c9, img, 0, 0, 0, 0, 32, 32);
  else if(valor == 10)
    masked_blit(c10, img, 0, 0, 0, 0, 32, 32);
  else if( valor == 11)
    masked_blit(cj, img, 0, 0, 0, 0, 32, 32);
  else if( valor == 12)
    masked_blit(cq, img, 0, 0, 0, 0, 32, 32);
  else if( valor == 13)
    masked_blit(ck, img, 0, 0, 0, 0, 32, 32);
  else if( valor == 14)
    masked_blit(ca, img, 0, 0, 0, 0, 32, 32);
}

int Carta::getValor() {
  return valor;
}

char Carta::getNaipe() {
  return naipe;
}

void Carta::setValor(int Valor) {
  valor = Valor;
}

void Carta::setNaipe(char Naipe) {
  naipe = Naipe;
}

void Carta::imprime() {
  printf("%2d%c ", this->getValor(), this->getNaipe());
}

void Carta::desenha(int W, int H) {
  masked_blit(this->img, screen, 0, 0, W, H, 32, 64);
}

void Carta::destroyBMP() {
  destroy_bitmap(this->img);
}
