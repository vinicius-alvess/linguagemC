#define HEROI '@'
#define VAZIO '.'
#define FANTASMA 'F'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa
{
	char **matriz;
	int linhas;
	int colunas;
};

typedef struct mapa MAPA;

struct posicao
{
	int x;
	int y;
};

typedef struct posicao POSICAO;

void alocamapa(MAPA *m);
void lemapa(MAPA *m);
void liberamapa(MAPA *m);
void imprimemapa(MAPA *m);
void encontramapa(MAPA *m, POSICAO *p, char c);

int ehvalida(MAPA *m, int proximox, int proximoy);
int ehvazia(MAPA *m, int proximox, int proximoy);
void andanomapa(MAPA *m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA *destino, MAPA *origem);