#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

// #include "letra_existe.hpp"
// #include "nao_acertou.hpp"
// #include "nao_enforcou.hpp"
// #include "imprime_cabecalho.hpp"
// #include "imprime_erros.hpp"
// #include "imprime_palavra.hpp"
// #include "chuta.hpp"
// #include "adiciona_palavra.hpp"
// #include "le_arquivo.hpp"
// #include "sorteia_palavra.hpp"
// #include "salva_arquivo.hpp"

#include "letra_existe.cpp"
#include "nao_acertou.cpp"
#include "nao_enforcou.cpp"
#include "imprime_cabecalho.cpp"
#include "imprime_erros.cpp"
#include "imprime_palavra.cpp"
#include "chuta.cpp"
#include "adiciona_palavra.cpp"
#include "le_arquivo.cpp"
#include "sorteia_palavra.cpp"
#include "salva_arquivo.cpp"

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