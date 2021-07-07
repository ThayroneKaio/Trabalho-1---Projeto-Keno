#ifndef head_h
#define head_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Dados_da_Aposta
{
    float Quantidade_inicial_de_credito;
    int Quantidade_de_Rodadas;
    std::vector <unsigned int> conjunto_de_numeros_apostados;
    int Quantidade_de_Acertos;
};


#endif