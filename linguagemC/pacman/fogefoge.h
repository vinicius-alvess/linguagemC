#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);
void fantasmas();
int paraondeofantasmavai(int *xatual, int *yatual, int *xdestino, int *ydestino);
int ehdirecao(char direcao);
