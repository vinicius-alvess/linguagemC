#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PONTOS 1000.00

int main()
{

    //imprime cabecalho do jogo
    printf("\n");
    printf("******************************************");
    printf("* Bem-vindo ao nosso jogo de adivinhacao *");
    printf("******************************************");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    int numerodetentativas = 5;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("\n\nQual nivel de dificuldade?\n\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        numerodetentativas = 20;
        break;
    case 2:
        numerodetentativas = 15;
        break;
    case 3:
        numerodetentativas = 6;
        break;
    default:
        printf("Invalido!!");
        break;
    }

    for (int i = 1; i <= numerodetentativas; i++)
    {

        printf("Tentativa %d\n", tentativas);
        printf("Qual e o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0)
        {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou)
        {
            break;
        }

        else if (maior)
        {
            printf("Seu chute foi maior que o numero secreto\n");
        }

        else
        {
            printf("Seu chute foi menor que o numero secreto\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo!\n");

    if (acertou)
    {
        printf("Voce ganhou!\n");
        printf("Voce acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }
    else
    {
        printf("Voce perdeu! Tente de novo!\n");
    }
}