#include "head.h"

// Guardei algumas funcoes, mais haver com o jogo aqui.

//Tabela de Retorno.

int payoff_table(int spot, int hits)
{
    int valor_de_retorno;

    float tabela_de_retorno[15][16] = {                       
                                    {0, 3},  
                                    {0, 1, 9},
                                    {0, 1, 2, 16},
                                    {0, 0.5, 2, 6, 12},
                                    {0, 0.5, 1, 3, 15, 50},
                                    {0, 0.5, 1, 2, 3, 30, 75},
                                    {0, 0.5, 0.5, 1, 6, 12, 36, 100},
                                    {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
                                    {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
                                    {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
                                    {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
                                    {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
                                    {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
                                    {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
                                    {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};
    
    return valor_de_retorno = tabela_de_retorno[spot-1][hits];  
}


//Quantidade de Hits

int Quantidade_de_Hits(vector <unsigned int> conjunto_de_numeros_apostados, vector <unsigned int> numeros_sorteados){
    
    int size = conjunto_de_numeros_apostados.size();
    int hits = 0;
    std:: vector<unsigned int> valores_acertados;
    
    for(int i = 0; i<size ; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(conjunto_de_numeros_apostados[i] == numeros_sorteados[j])
            {
                hits++;   
            }

        }

    }
    
    return hits;

}




