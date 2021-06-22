// O c�digo n�o compila com f6
// Compila usando:
// cd "c:\GitHub\linguagem_C\linguagemCpp\forca_v2"
// g++ *.cpp -o forca.exe
// & .\"forca.exe"

// Como compilar varios arquivos separadamente
// cd "c:\GitHub\linguagem_C\linguagemCpp\forca_v2"
// g++ -c *.cpp
// g++ *.o -o forca.exe
// & .\"forca.exe"

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "letra_existe.hpp"
#include "nao_acertou.hpp"
#include "nao_enforcou.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "adiciona_palavra.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "salva_arquivo.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

int main()
{
    imprime_cabecalho();

    le_arquivo();
    sorteia_palavra();

    while (nao_acertou() && nao_enforcou())
    {
        imprime_erros();

        imprime_palavra();

        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if (nao_acertou())
    {
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if (resposta == 'S')
        {
            adiciona_palavra();
        }
    }

    cin.get();
}