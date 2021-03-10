#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

/*arquivo mapa.c*/
// #include <stdio.h>
// #include <stdlib.h>
// #include "mapa.h"
void lemapa(MAPA* m) {
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
	alocamapa(m);
	
	for(int i = 0; i < m->linhas; i++) {
		fscanf(f, "%s", m->matriz[i]);
	}

	fclose(f);
}

void alocamapa(MAPA* m) {
	m->matriz = malloc(sizeof(char*) * m->linhas);

	for(int i = 0; i < m->linhas; i++) {
		m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
	}
}

void liberamapa(MAPA* m) {
	for(int i = 0; i < m->linhas; i++) {
		free(m->matriz[i]);
	}

	free(m->matriz);
}

void imprimemapa(MAPA* m) {
	for(int i = 0; i < m->linhas; i++) {
		printf("%s\n", m->matriz[i]);
	}
}

void encontramapa(MAPA* m, POSICAO* p, char c) {

	for(int i = 0; i < m->linhas; i++) {
		for(int j = 0; j < m->colunas; j++) {
			if(m->matriz[i][j] == c) {
				p->x = i;
				p->y = j;
				return;
			}
		}
	}

}
/*FIM do arquivo mapa.c*/

int acabou() {
	return 0;
}

void move(char direcao) {

	m.matriz[heroi.x][heroi.y] = '.';

	switch(direcao) {
		case 'a':
			m.matriz[heroi.x][heroi.y-1] = '@';
			heroi.y--;
			break;
		case 'w':
			m.matriz[heroi.x-1][heroi.y] = '@';
			heroi.x--;
			break;
		case 's':
			m.matriz[heroi.x+1][heroi.y] = '@';
			heroi.x++;
			break;
		case 'd':
			m.matriz[heroi.x][heroi.y+1] = '@';
			heroi.y++;
			break;
	}
	
}

int main() {
	
	lemapa(&m);
	encontramapa(&m, &heroi, '@');

	do {
		imprimemapa(&m);

		char comando;
		scanf(" %c", &comando);

		move(comando);

	} while (!acabou());

	liberamapa(&m);
}