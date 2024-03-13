#ifndef ELENCO_H
#define ELENCO_H

#include "Jogador.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Elenco
{
    public:
        Elenco(string fileName); // Construtor
        ~Elenco(); // Destrutor
        bool adiciona(int posicao); // Um jogador no arquivo de elenco;
        void imprimeOrdenado(); // Imprime com base na posição, salário, nome, apelido, ano de contrato ou numero
        void imprime(int numeroCamisa); // Busca pelo numero e imprime os dados do jogador
        bool remove(int numeroCamisa); // Busca pelo numero e remove os dados do jogador
        bool atualiza(int numeroCamisa); // Busca pelo número e atualiza o apelido, o número da camisa, o salário ou ano de contrato
        static int opcao(); // Método para implementação de um menu inicial;
    private:
        void grava(); // Grava um objeto no arquivo
        void recupera(); // Recupera um objeto do arquivo
        int indice(int numeroCamisa); // Retorna a posição de certo objeto no vector

        string fileName;
        vector<Jogador*>jogadores;

};  

#endif