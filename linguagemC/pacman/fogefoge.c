#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

void fantasmas()
{
	
	MAPA copia;

	copiamapa(&copia, &m);

	for (int i = 0; i < m.linhas; i++)
	{
		for (int j = 0; j < m.colunas; j++)
		{
			if (copia.matriz[i][j] == FANTASMA)
			{
				if (ehvalida(&m, i, (j + 1)) && ehvazia(&m, i, (j + 1)))
				{
					andanomapa(&m, i, j, i, j + 1);
				}
			}
		}
	}
}

//////////////*arquivo mapa.c*////////////////
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "mapa.h"
void copiamapa(MAPA *destino, MAPA *origem)
{
	destino->linhas = origem->linhas;
	destino->colunas = origem->colunas;

	alocamapa(destino);
	for (int i = 0; i < origem->linhas; i++)
	{
		strcpy(destino->matriz[i], origem->matriz[i]);
	}
}

void lemapa(MAPA *m)
{
	FILE *f;
	f = fopen("mapa.txt", "r");
	if (f == 0)
	{
		printf("Erro na leitura do mapa");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
	alocamapa(m);

	for (int i = 0; i < m->linhas; i++)
	{
		fscanf(f, "%s", m->matriz[i]);
	}

	fclose(f);
}

void alocamapa(MAPA *m)
{
	m->matriz = malloc(sizeof(char *) * m->linhas);

	for (int i = 0; i < m->linhas; i++)
	{
		m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
	}
}

void liberamapa(MAPA *m)
{
	for (int i = 0; i < m->linhas; i++)
	{
		free(m->matriz[i]);
	}

	free(m->matriz);
}

void imprimemapa(MAPA *m)
{
	for (int i = 0; i < m->linhas; i++)
	{
		printf("%s\n", m->matriz[i]);
	}
}

void encontramapa(MAPA *m, POSICAO *p, char c)
{

	for (int i = 0; i < m->linhas; i++)
	{
		for (int j = 0; j < m->colunas; j++)
		{
			if (m->matriz[i][j] == c)
			{
				p->x = i;
				p->y = j;
				return;
			}
		}
	}
}

void andanomapa(MAPA *m, int xorigem, int yorigem, int xdestino, int ydestino)
{
	char personagem = m->matriz[xorigem][yorigem];

	m->matriz[xdestino][ydestino] = personagem;
	m->matriz[xorigem][yorigem] = VAZIO;
}

int ehvalida(MAPA *m, int proximox, int proximoy)
{
	return proximox < m->linhas && proximoy < m->colunas;
}

int ehvazia(MAPA *m, int proximox, int proximoy)
{
	return m->matriz[proximox][proximoy] == VAZIO;
}
//////*FIM do arquivo mapa.c*/////

//////////////*arquivo fogefoge.c*////////////////
// #include <stdio.h>
// #include <stdlib.h>
// #include "fogefoge.h"
// #include "mapa.h"
int acabou()
{
	return 0;
}

int ehdirecao(char direcao)
{
	return direcao == ESQUERDA || direcao == CIMA || direcao == BAIXO || direcao == DIREITA;
}

void move(char direcao)
{
	if (!ehdirecao(direcao))
		return;

	int proximox = heroi.x;
	int proximoy = heroi.y;

	switch (direcao)
	{
	case ESQUERDA:
		proximoy--;
		break;
	case CIMA:
		proximox--;
		break;
	case BAIXO:
		proximox++;
		break;
	case DIREITA:
		proximoy++;
		break;
	}

	if (!ehvalida(&m, proximox, proximoy))
		return;

	if (!ehvazia(&m, proximox, proximoy))
		return;

	andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
	heroi.x = proximox;
	heroi.y = proximoy;
}
/////*FIM do arquivo fogefoge.c*/////

int main()
{
	lemapa(&m);
	encontramapa(&m, &heroi, HEROI);

	do
	{
		imprimemapa(&m);

		char comando;
		scanf(" %c", &comando);

		move(comando);
		fantasmas();

	} while (!acabou());

	liberamapa(&m);
}