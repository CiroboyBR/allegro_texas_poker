
void iniciaNaipes();

BITMAP *paus, *copas, *espadas, *ouro;
BITMAP *c2, *c3, *c4, *c5, *c6, *c7, *c8, *c9, *c10, *cj, *cq, *ck, *ca;


void iniciaNaipes() {
  paus = load_bmp("img/paus.bmp", NULL);
  copas = load_bmp("img/copas.bmp", NULL);
  espadas = load_bmp("img/espadas.bmp", NULL);
  ouro = load_bmp("img/ouro.bmp", NULL);

  c2 = load_bmp("img/2.bmp", NULL);
  c3 = load_bmp("img/3.bmp", NULL);
  c4 = load_bmp("img/4.bmp", NULL);
  c5 = load_bmp("img/5.bmp", NULL);
  c6 = load_bmp("img/6.bmp", NULL);
  c7 = load_bmp("img/7.bmp", NULL);
  c8 = load_bmp("img/8.bmp", NULL);
  c9 = load_bmp("img/9.bmp", NULL);
  c10 = load_bmp("img/10.bmp", NULL);
  cj = load_bmp("img/J.bmp", NULL);
  cq = load_bmp("img/Q.bmp", NULL);
  ck = load_bmp("img/K.bmp", NULL);
  ca = load_bmp("img/A.bmp", NULL);
}
