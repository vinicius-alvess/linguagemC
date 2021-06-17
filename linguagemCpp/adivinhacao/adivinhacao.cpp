#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;

// Funcoes
void abertura();
void escolhe_nivel();
int sorteia_numero();
void calcula_pontos(int chute);
void adivinha();
void ganhou(int tentativas);
void perdeu();

// Variaveis Globais
const int NUMERO_SECRETO = sorteia_numero();
int numero_de_tentativas;
double pontos = 1000.00;

void abertura()
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
    cout << "**************************************" << endl;
}

void escolhe_nivel()
{
    cout << "Escolha o seu ní­vel de dificuldade:" << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

    char nivel;
    bool caracter_invalido;

    do
    {
        caracter_invalido = false;

        cin >> nivel;

        switch (nivel)
        {
        case 'F':
            numero_de_tentativas = 15;
            break;

        case 'M':
            numero_de_tentativas = 10;
            break;

        case 'D':
            numero_de_tentativas = 5;
            break;

        default:
            caracter_invalido = true;
            cout << "Caracter Invalido!" << endl;
            break;
        }
    } while (caracter_invalido);
}

int sorteia_numero()
{
    int numero_secreto;

    srand(time(NULL));
    numero_secreto = rand() % 100;

    return numero_secreto;
}

void calcula_pontos(int chute)
{
    double pontos_perdidos = std::abs(chute - NUMERO_SECRETO) / 2.0;
    pontos -= pontos_perdidos;
}

void adivinha()
{
    int chute;
    bool acertou = false;
    int tentativas = 0;

    while (!acertou && tentativas < numero_de_tentativas)
    {
        tentativas++;
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute?" << endl;
        cin >> chute;

        calcula_pontos(chute);

        cout << "O valor do seu chute é: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            ganhou(tentativas);
            acertou = true;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que número secreto!" << endl;
        }
    }

    if (!acertou)
    {
        perdeu();
    }
}

void ganhou(int tentativas)
{
    cout << "Parabens, voce ganhou!" << endl;
    cout << "Voce acertou em " << tentativas << " tentativas!" << endl;

    cout.precision(2);
    cout << fixed;

    cout << "Sua pontuação foi de " << pontos << " pontos." << endl;

    cout << "       ___________      " << endl;
    cout << "      '._==_==_=_.'     " << endl;
    cout << "      .-\\:      /-.    " << endl;
    cout << "     | (|:.     |) |    " << endl;
    cout << "      '-|:.     |-'     " << endl;
    cout << "        \\::.    /      " << endl;
    cout << "         '::. .'        " << endl;
    cout << "           ) (          " << endl;
    cout << "         _.' '._        " << endl;
    cout << "        '-------'       " << endl;
}

void perdeu()
{
    cout << "Voce perdeu!" << endl;
    cout << "    _______________         " << endl;
    cout << "   /               \\       " << endl;
    cout << "  /                 \\      " << endl;
    cout << "//                   \\/\\  " << endl;
    cout << "\\|   XXXX     XXXX   | /   " << endl;
    cout << " |   XXXX     XXXX   |/     " << endl;
    cout << " |   XXX       XXX   |      " << endl;
    cout << " |                   |      " << endl;
    cout << " \\__      XXX      __/     " << endl;
    cout << "   |\\     XXX     /|       " << endl;
    cout << "   | |           | |        " << endl;
    cout << "   | I I I I I I I |        " << endl;
    cout << "   |  I I I I I I  |        " << endl;
    cout << "   \\_             _/       " << endl;
    cout << "     \\_         _/         " << endl;
    cout << "       \\_______/           " << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Habilita a acentuacao para o portugues

    abertura();

    escolhe_nivel();

    adivinha();
}