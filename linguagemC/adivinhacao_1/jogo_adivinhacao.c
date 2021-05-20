#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PONTOS 1000.00

int numero_de_tentativas;
int chutes_dados = 1;
int acertou = 0;
double pontos = PONTOS;

void abertura()
{
    printf("\n");
    printf("******************************************");
    printf("* Bem-vindo ao nosso jogo de adivinhacao *");
    printf("******************************************");
}

int cria_numero_secreto()
{
    int segundos = time(0);
    srand(segundos);

    int numero_grande = rand();
    int numero_secreto = numero_grande % 100;

    return numero_secreto;
}

int escolhe_nivel()
{
    int nivel;

    printf("\n\nQual nivel de dificuldade?\n\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        numero_de_tentativas = 20;
        break;
    case 2:
        numero_de_tentativas = 10;
        break;
    case 3:
        numero_de_tentativas = 6;
        break;
    default:
        printf("Invalido!!");
        break;
    }
}

void adivinha(int numero_secreto)
{
    int chute;

    for (int i = 1; i <= numero_de_tentativas; i++)
    {

        printf("Tentativa %d\n", chutes_dados);
        printf("Qual e o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0)
        {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        acertou = (chute == numero_secreto);
        int maior = chute > numero_secreto;

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

        chutes_dados++;

        double pontosperdidos = abs(chute - numero_secreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    printf("\nFim de jogo!\n");
}

void main()
{
    abertura();

    escolhe_nivel();

    adivinha(cria_numero_secreto());

    if (acertou)
    {
        printf("\nParabens, voce ganhou!\n\n");
        printf("Voce acertou em %d tentativas!\n", chutes_dados);
        printf("Total de pontos: %.1f\n", pontos);

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    }
    else
    {
        printf("Voce perdeu!\n\n");
        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
}