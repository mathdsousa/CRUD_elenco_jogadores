#include "Atacante.h"
#include "MeioCampista.h"
#include "Defensor.h"
#include "Goleiro.h"
#include "Elenco.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int op; // Opção escolhida pelo usuário
    int numCamisa; // Número da camisa do jogador escolhido pelo usuário
    bool ok;

    Elenco elenco("data.dat"); // Construção de um objeto da classe elenco

    do
    {
        op = Elenco::opcao(); // Acionamento do método que contém o menu de intereção
        // Escolha de uma determinada ação a ser feita no objeto elenco
        switch(op)
        {
            case 1:
                elenco.imprimeOrdenado();
                break;
            case 2:
                cout << "Numero da Camisa: ";
                cin >> numCamisa;
                cout << endl;
                elenco.imprime(numCamisa);
                break;
            case 3:
                cout << "Numero da Camisa: ";
                cin >> numCamisa;
                cout << endl;
                ok = elenco.remove(numCamisa);
                break;
            case 4:
                cout << "Numero da Camisa: ";
                cin >> numCamisa;
                cout << endl;
                ok = elenco.atualiza(numCamisa);
                break;
            case 5: 
                ok = elenco.adiciona(GOLEIRO);
                break;
            case 6: 
                ok = elenco.adiciona(DEFENSOR);
                break;
            case 7: 
                ok = elenco.adiciona(MEIO_CAMPISTA);
                break;
            case 8: 
                ok = elenco.adiciona(ATACANTE);
                break;
            default:
                break;
        }
        cout << endl;
    } while (op != 0);
    
    return 0;
}

