#include <stdio.h>
#include <string.h>

char palavra_secreta[20];
char chutes[26];
int tentativas = 0;

void abertura()
{
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

int chuta()
{
    char chute;
    printf("\nQual letra? ");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < tentativas; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca()
{
    int i;
    for (i = 0; i < strlen(palavra_secreta); i++)
    {

        int achou = jachutou(palavra_secreta[i]);

        if (achou)
        {
            printf("%c ", palavra_secreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhe_palavra()
{
    sprintf(palavra_secreta, "MELANCIA");
}

int main()
{
    int acertou = 0;
    int enforcou = 0;

    escolhe_palavra();
    abertura();

    do
    {
        desenhaforca();
        chuta();

    } while (!acertou && !enforcou);
}