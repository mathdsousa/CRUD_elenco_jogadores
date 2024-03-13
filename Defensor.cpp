#include "Defensor.h"

// Construtor
Defensor::Defensor(string nome, string apelido, double salario, int camisa, string posicaoDefesa, int fimContrato, float altura, string nacionalidade, int idade) :
Jogador (nome, apelido, salario, camisa, fimContrato, altura, nacionalidade, idade), posicaoDefesa(posicaoDefesa)
{
    
}

// Destrutor
Defensor::~Defensor()
{
    
}

// Indica a posição específica do defensor
string Defensor::getPosicaoDefesa() const
{
    return this->posicaoDefesa;
}

// Altera a posição específica do defensor
void Defensor::setPosicaoDefesa(string posicaoDefesa)
{
    this->posicaoDefesa = posicaoDefesa;
}

// Indicador de posição
int Defensor::getPosicao() const
{
    return 1; // Número 1 para indicar o defensor
}

// Imprime mais informações sobre o defensor
void Defensor::imprime() const
{
    Jogador::imprime();
    cout << "Posicao Especifica na Defesa: " << this->posicaoDefesa << endl;
}
