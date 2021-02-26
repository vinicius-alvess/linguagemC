#include <stdio.h>
#include <string.h>

void abertura()
{
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

int chuta(char chutes[26], int tentativas)
{
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
}
 
int main()
{

    char palavra_secreta[20];
    sprintf(palavra_secreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do
    {
        // imprime a palavra secreta
        for (int i = 0; i < strlen(palavra_secreta); i++)
        {
            int achou = 0;

            // a letra ja foi chutada?
            for (int j = 0; j < tentativas; j++)
            {
                if (chutes[j] == palavra_secreta[i])
                {
                    achou = 1;
                    break;
                }
            }

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

        chuta(chutes, tentativas);
        tentativas++;

    } while (!acertou && !enforcou);
}