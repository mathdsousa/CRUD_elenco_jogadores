#include "Atacante.h"

// Construtor
Atacante::Atacante(string nome, string apelido, double salario, int camisa, string posicaoAtaque, int fimContrato, float altura, string nacionalidade, int idade) :
Jogador (nome, apelido, salario, camisa, fimContrato, altura, nacionalidade, idade), posicaoAtaque(posicaoAtaque)
{
    
}

// Destrutor
Atacante::~Atacante()
{
    
}

// Indica a posição específica do atacante
string Atacante::getPosicaoAtaque() const
{
    return this->posicaoAtaque;
}

// Altera a posição específica do atacante
void Atacante::setPosicaoAtaque(string posicaoAtaque)
{
    this->posicaoAtaque = posicaoAtaque;
}

// Indicador de posição
int Atacante::getPosicao() const
{
    return 3; // Número 3 para indicar o atacante
}

// Imprime mais informações sobre o atacante
void Atacante::imprime() const
{
    Jogador::imprime();
    cout << "Posicao Especifica no Ataque: " << this->posicaoAtaque << endl;
}
