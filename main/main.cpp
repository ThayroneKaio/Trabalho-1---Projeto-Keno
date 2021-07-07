#include "head.h"
#include "function.cpp"

//funcao que verifica se o arquivo existe

int leitura_de_arquivo()     
{
    ifstream apostas;
    string linha;
    
    apostas.open("teste.txt");
    
    if (apostas.is_open())
    {
        return 1;
    }
    else{
        return -1;
    }
    
}

//validacao

int validacao_do_arquivo_de_apostas(float Quantidade_inicial_de_credito, int Quantidade_de_Rodadas, vector <unsigned int> conjunto_de_numeros_apostados)
{
    int comparador, contador = 0;
    comparador = conjunto_de_numeros_apostados.size();

    // Verifica se a aposta tem mais de 15 numeros.

    if(comparador > 15)                               
    {
        cout << "Aposta Invalida, numero de numeros apostados superior a 15." << endl;
        return -1;
        
    }

    // Verifica se a formatação e diferente daquela proposta para o arquivo de apostas.
    
    if(Quantidade_inicial_de_credito == 0 || Quantidade_de_Rodadas == 0 || comparador == 0)
    {
        cout << "Aposta Invalida, formatacao de aposta invalida." << endl;
        return -1;       
    }

    // Verifica se ha numeros repetidos.

    for(int i = 0; i<comparador; i++)
    {
        for(int j = i+1; j<comparador; j++)
        {
            if(conjunto_de_numeros_apostados[i] == conjunto_de_numeros_apostados[j])
            {
                contador++;    
            }

        }
    }

    if(contador != 0)
    {
        cout << "Aposta invalida, apostas com numeros repetidos." << endl;
        return -1;
    }

    // ps. Caracteres estrenhos ja dao erro no proprio progama.   
}

// ordenacao crescente de vetores

int main(int argc, char *argv[])
{
    Dados_da_Aposta IC, NR, SPOT;
    int auxiliar;   // auxilia a extracao de dados para o vector conjunto de numeros de apostas

    // tabela de retorno para impressao

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
    
    cout << ">>> Lendo o arquivo de apostas [teste.txt], por favor aguarde..." << endl;
    cout << "----------------------------------------------------------------" << endl;
    
    // Verifica se o arquivo eh valido, e para o progama caso nao for.

    if (leitura_de_arquivo() != 1)
    {
        cout<< "Arquivo inexistente "<< endl;
    }
     
    ifstream apostas;
    apostas.open("teste.txt");
    

    //Extracao do arquivo.
    
    apostas  >> IC.Quantidade_inicial_de_credito;      
    apostas >> NR.Quantidade_de_Rodadas;
    while(!apostas.eof())
    {
        apostas >> auxiliar;
        SPOT.conjunto_de_numeros_apostados.push_back(auxiliar);
    }

    //Valida o arquivo apostas e para caso nao seja satisfeito.

    if(validacao_do_arquivo_de_apostas(IC.Quantidade_inicial_de_credito, NR.Quantidade_de_Rodadas, SPOT.conjunto_de_numeros_apostados) == -1)
    {
        return 0;
    }
    
    //interface do jogo

    cout << ">>> Aposta lida com sucesso! " << endl;
    cout << "    Voce apostara um total de " << IC.Quantidade_inicial_de_credito << " de creditos." << endl;
    cout << "    Jogara um total de " << NR.Quantidade_de_Rodadas << " rodadas apostando " << IC.Quantidade_inicial_de_credito/NR.Quantidade_de_Rodadas << " creditos por rodada." << endl;
    cout << endl;
    cout << "    Sua aposta tem " << SPOT.conjunto_de_numeros_apostados.size() << " numeros elses sao: [ ";
    
    for(int k = 0; k<SPOT.conjunto_de_numeros_apostados.size(); k++)
    {
        cout << SPOT.conjunto_de_numeros_apostados[k] << " ";;
    }
    cout << "]" << endl;
    cout << "    ----------+-----------" << endl;
    cout << "         Hits" << " | " << "Retorno" << endl;

    
    for(int k = 0; k < SPOT.conjunto_de_numeros_apostados.size()+1; k++){
        cout << "         " << k << "    | " << tabela_de_retorno[SPOT.conjunto_de_numeros_apostados.size()-1][k] << endl;
    }
    cout << "    ------------------------------------------------------------------------------------------------" << endl;

 
    // Iniciando o jogo

    std::vector <unsigned int> numeros_sorteados;
    Dados_da_Aposta HITS;   // numero de hits
    unsigned int valores;   // auxilia o vector numeros sorteados  
    int valor_de_retorno, tamanho;  //o valor de retorno da tabela e tamanho representa a size do vector conjunto de numeros apostados
    float valor_apostado, aux_valor_total, valor_total;  // variaveis para a alteracao dos creditos
    srand(time(NULL));
    
    tamanho = SPOT.conjunto_de_numeros_apostados.size();
    valor_apostado = IC.Quantidade_inicial_de_credito/NR.Quantidade_de_Rodadas;
    valor_total = IC.Quantidade_inicial_de_credito;
    
    // loop principal

    for(int i = 0; i < NR.Quantidade_de_Rodadas; i++)
    {
        

        valor_total = valor_total - valor_apostado;
        
        cout << "    Esta e a rodada #" << i+1 << " de " << NR.Quantidade_de_Rodadas << " sua aposta e " << valor_apostado << ". Boa Sorte!" << endl;
        
        // gera numeros aleatorios

        for(int j = 0; j<20; j++)
        {    
            valores = rand() % 80;
            numeros_sorteados.push_back(valores);
        }
        
        cout << "    Os numeros sorteados sao [";
        
        //imprime os numeros sorteados

        for(int k=0; k<20; k++)
        {
            cout << numeros_sorteados[k] << " ";
        }
        
        cout << "]" << endl;
        cout << endl;

        //chamada de funcao para o acertos de hit e valor de retorno seguindo a tabela de retorno
        
        HITS.Quantidade_de_Acertos = Quantidade_de_Hits(SPOT.conjunto_de_numeros_apostados, numeros_sorteados);
        valor_de_retorno = payoff_table(tamanho, HITS.Quantidade_de_Acertos);
    
        cout << "    Voce acertou " << HITS.Quantidade_de_Acertos << " nesta rodada, um total de "<< HITS.Quantidade_de_Acertos << " hit(s) em "<< tamanho <<  endl;

        //faz a alteracao dos creditos
        
        aux_valor_total = valor_apostado * valor_de_retorno;
        valor_total = valor_total + aux_valor_total; 
        
        cout << "    Sua taxa de retorno e " << valor_de_retorno << " assim voce sai com: " << aux_valor_total << endl;
        cout << "    Voce possui um total de: " << valor_total << " creditos." << endl;
        cout << "    ------------------------------------------------------------------------------------------------" << endl;    
        
        //apaga o vector por completo
        
        numeros_sorteados.clear();
    }

    cout << ">> Fim das Rodadas" << endl;
    cout << " ------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << "======= Sumario =======" << endl;
    cout << ">>> Voce gastou um total de " << IC.Quantidade_inicial_de_credito << " creditos" << endl;
    cout << ">>> Hooray! voce ganhou " << valor_total - IC.Quantidade_inicial_de_credito << " creditos" << endl;
    cout << ">>> Voce esta saindo do jogo com um total de " << valor_total << " creditos." << endl;
    cout << endl;

    return 0;
    
}
