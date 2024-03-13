#include "MeioCampista.h"

// Construtor
MeioCampista::MeioCampista(string nome, string apelido, double salario, int camisa, string posicaoMeioCampo, int fimContrato, float altura, string nacionalidade, int idade) :
Jogador(nome, apelido, salario, camisa, fimContrato, altura, nacionalidade, idade), posicaoMeioCampo(posicaoMeioCampo)
{
    
}

// Destrutor
MeioCampista::~MeioCampista()
{
    
}

// Indica a posição específica do meio-campista
string MeioCampista::getPosicaoMeioCampo() const
{
    return this->posicaoMeioCampo;
}

// Altera a posição específica do meio-campista
void MeioCampista::setPosicaoMeioCampo(string posicaoMeioCampo)
{
    this->posicaoMeioCampo = posicaoMeioCampo;
}

//Indicador de posicao
int MeioCampista::getPosicao() const
{
    return 2; // Número 2 para indicar o meio-campista
}

// Imprime mais informações do meio-campista
void MeioCampista::imprime() const
{
    Jogador::imprime();
    cout << "Posicao Especifica no Meio-campo: " << this->posicaoMeioCampo << endl;
}
