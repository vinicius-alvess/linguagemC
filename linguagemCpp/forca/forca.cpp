#include <locale.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream> // manipular arquivos
#include <ctime>
#include <cstdlib>

using namespace std;

// Funcoes
void abertura();
bool letra_existe(char chute);
bool acertou();
bool enforcou();
void imprime_chutes_errados();
void imprime_letras_chutadas();
void analisa_chute();
vector<string> le_arquivo();
void sorteia_palavra();

// Variaveis Globais
string palavra_secreta;
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
    for (char letra : palavra_secreta)
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
    for (char letra : palavra_secreta)
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
    for (char letra : palavra_secreta)
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

vector<string> le_arquivo()
{
    ifstream arquivo;

    arquivo.open("palavras.txt"); // abre arquivo

    if (arquivo.is_open()) // se abrir
    {

        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        if (quantidade_palavras == 0)
        {
            cout << "N�o existe nenhuma palavra no banco de palavras!" << endl;
            exit(0);
        }

        vector<string> palavras_do_arquivo;

        for (int i = 0; i < quantidade_palavras; i++)
        {
            string palavra_lida;
            arquivo >> palavra_lida;

            palavras_do_arquivo.push_back(palavra_lida);
        }

        arquivo.close();
        return palavras_do_arquivo;
    }
    else // caso nao abra
    {
        cout << "N�o foi poss�vel acessar o banco de palavras." << endl;
        exit(0);
    }
}

void sorteia_palavra()
{
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Habilita a acentuacao para o portugues

    abertura();

    le_arquivo();

    sorteia_palavra();

    while (!acertou() && !enforcou())
    {
        imprime_chutes_errados();

        imprime_letras_chutadas();

        analisa_chute();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (!acertou())
    {
        cout << "Voc� perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Voc� acertou a palavra secreta!" << endl;
    }
}