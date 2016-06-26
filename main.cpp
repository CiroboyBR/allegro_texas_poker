#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "Mesa.cpp"

using namespace std;

void loop();
void rodadas();

int main() {
  allegro_init();
  install_keyboard();

//Ajusta video para 16 bits de cores
  set_color_depth(32);

//Autodetecta a placa  de   video e usa resolucao de 640x480 em modo janela
  set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,640,480);

  iniciaNaipes();
  srand(time(NULL));

  //loop();
  rodadas();

  allegro_exit();
  return 0;
}
END_OF_MAIN();

void loopTeste() {//Somente utilizado para testes
Baralho B;

  Carta C;

  do {
    textprintf_ex(screen, font, 150, 20, Cor::verde(), 0,"Aperte espaco para um novo sorteio de cartas");
    readkey();

    if(key[KEY_SPACE] && B.qtdCartas() >=4) {
      B = Baralho();
      B.embaralha(30);

      //cartas comunitarias
      C = B.tiraCarta();
      C.desenha(0, 100);
      C = B.tiraCarta();
      C.desenha(30, 100);
      C = B.tiraCarta();
      C.desenha(60, 100);
      C = B.tiraCarta();
      C.desenha(90, 100);
      C = B.tiraCarta();
      C.desenha(120, 100);
      /*
      C = B.tiraCarta();
      C.desenha(120, 100);
      C = B.tiraCarta();
      C.desenha(160, 100);
      */

      //1 0carta da mão
      C = B.tiraCarta();
      C.desenha(40, 250);
      C = B.tiraCarta();
      C.desenha(70, 250);

      B.imprime();
      B.desalocaBMP();
    }

  } while( !key[KEY_ESC] && !B.vazio() );
}

void rodadas() {

  Mesa M = Mesa();
  Jogador J = Jogador("Ciro");

  M.addJogador(J, 0);
  J = Jogador("Joao");
  M.addJogador(J, 1);
  J = Jogador("Lara");
  M.addJogador(J, 2);
  J = Jogador("Fernanda");
  M.addJogador(J, 3);
  J = Jogador("Pablo");
  M.addJogador(J, 4);

  do {
    M.iniciaMao();

    M.flop();
    readkey();
    M.turn();
    readkey();
    M.river();
    readkey();
    clear_bitmap(screen);

  } while( !key[KEY_ESC] );
}
