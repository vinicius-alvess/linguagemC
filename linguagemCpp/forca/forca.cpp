#include <locale.h>
#include <iostream>
#include <cstring> // Tamanho da string
#include <string>
#include <vector>
#include <map>

using namespace std;

// Funcoes
bool letra_existe(char chute);
void abertura();

// Variaveis Globais
const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute)
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (chute == letra)
        {
            return true;
        }
    }
    return false;
}

void abertura()
{
    cout << "**************************************" << endl;
    cout << "          * Jogo da Forca! *          " << endl;
    cout << "**************************************" << endl;
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Habilita a acentuacao para o portugues

    abertura();

    bool acertou = false;
    bool enforcou = false;
    char chute;

    while (!acertou && !enforcou)
    {

        cout << "Chutes errados: ";
        for (char letra : chutes_errados)
        {
            cout << letra << " ";
        }
        cout << endl;

        for (char letra : PALAVRA_SECRETA)
        {
            if (chutou[letra])
            {
                cout << letra << " ";
            }
            else
            {
                cout << "_ ";
            }
        }

        cout << endl;

        cout << "Seu chute: ";
        cin >> chute;

        chutou[chute] = true; // modificando no map

        if (letra_existe(chute))
        {
            cout << "Você acertou! Seu chute está na palavra." << endl;
        }
        else
        {
            cout << "Você errou! Seu chute não está na palavra." << endl;
            chutes_errados.push_back(chute);
        }

        cout << endl;
    }
}