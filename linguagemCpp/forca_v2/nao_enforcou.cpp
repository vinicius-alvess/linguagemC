#include <iostream>
#include <string>
#include <vector>
#include "letra_existe.hpp"

extern std::vector<char> chutes_errados;

bool nao_enforcou()
{
    return chutes_errados.size() < 5;
}