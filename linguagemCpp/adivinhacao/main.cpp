#include <stdio.h>
#include <iostream>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese"); // habilita a acentuacao para portugues

    // Mastra na tela std::cout << "Exemplo"
    std::cout << "**************************************" << std::endl;
    std::cout << "* Bem vindos ao jogo da adivinhação! *" << std::endl;
    std::cout << "**************************************" << std::endl;
}