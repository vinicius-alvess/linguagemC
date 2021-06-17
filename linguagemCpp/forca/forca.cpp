#include <locale.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Funcoes
void abertura();
bool letra_existe(char chute);
bool acertou();
bool enforcou();
void imprime_chutes_errados();
void imprime_letras_chutadas();
void analisa_chute();

// Variaveis Globais
const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

void abertura()
{
    cout << "**************************************" << endl;
    cout << "          * Jogo da Forca! *          " << endl;
    cout << "**************************************" << endl;
    cout << endl;
}

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

bool acertou()
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (!chutou[letra])
        {
            return false;
        }
    }
    return true;
}

bool enforcou()
{
    return chutes_errados.size() > 4;
}

void imprime_chutes_errados()
{
    cout << "Chutes errados: ";
    for (char letra : chutes_errados)
    {
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_letras_chutadas()
{
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
}

void analisa_chute()
{
    char chute;

    cout << "Seu chute: ";
    cin >> chute;

    chutou[chute] = true; // modificando no map

    if (letra_existe(chute))
    {
        cout << "Voc� acertou! Seu chute est� na palavra." << endl;
    }
    else
    {
        cout << "Voc� errou! Seu chute n�o est� na palavra." << endl;
        chutes_errados.push_back(chute);
    }

    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Habilita a acentuacao para o portugues

    abertura();

    while (!acertou() && !enforcou())
    {
        imprime_chutes_errados();

        imprime_letras_chutadas();

        analisa_chute();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;

    if (!acertou())
    {
        cout << "Voc� perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Voc� acertou a palavra secreta!" << endl;
    }
}