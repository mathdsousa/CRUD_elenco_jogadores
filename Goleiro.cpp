#include "Goleiro.h"

// Construtor
Goleiro::Goleiro(string nome, string apelido, double salario, int camisa, int fimContrato, float altura, string nacionalidade, int idade) :
Jogador(nome, apelido, salario, camisa, fimContrato, altura, nacionalidade, idade)
{
    
}

// Destrutor
Goleiro::~Goleiro()
{
    
}

// Indicador de posição
int Goleiro::getPosicao() const
{
    return 0; // Número 0 para indica o goleiro
}
