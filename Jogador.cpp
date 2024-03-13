#include "Jogador.h"

// Construtor
Jogador::Jogador(string nome, string apelido, double salario, int camisa, int fimContrato, float altura, string nacionalidade, int idade) :
nome(nome), apelido(apelido), salario(salario), camisa(camisa), fimContrato(fimContrato), altura(altura), nacionalidade(nacionalidade), idade(idade)
{

}

// Destrutor
Jogador::~Jogador()
{

}

// Consulta nome
string Jogador::getNome() const
{
    return this->nome;
}

// Altera nome
void Jogador::setNome(string nome)
{
    this->nome = nome;
}

// Consulta apelido
string Jogador::getApelido() const
{
    return this->apelido;
}

// Altera apelido
void Jogador::setApelido(string apelido)
{
    this->apelido = apelido;
}

// Consulta o ano do término de contrato
int Jogador::getFimContrato() const
{
    return this->fimContrato;
}

// Altera o ano do término de contrato
void Jogador::setFimContrato(int fimContrato)
{
    this->fimContrato = fimContrato;
}

// Consulta salário
double Jogador::getSalario() const
{
    return this->salario;
}

// Altera salário
void Jogador::setSalario(double salario)
{
    this->salario = salario;
}

// Consulta o número da camisa
int Jogador::getCamisa() const
{
    return this->camisa;
}

// Altera o número da camisa
void Jogador::setCamisa(int camisa)
{
    this->camisa = camisa;
}

// Consulta a idade do jogador
int Jogador::getIdade() const
{
    return this->idade;   
}

// Altera a idade do jogador
void Jogador::setIdade(int idade)
{
    this->idade = idade;
}

// Consulta a nacionalidade do jogador
string Jogador::getNacionalidade() const
{
    return this->nacionalidade;
}

// Altera a nacionalidade do jogador
void Jogador::setNacionalidade(string nacionalidade)
{
    this->nacionalidade = nacionalidade;
}

// Consulta a altura do jogador
float Jogador::getAltura() const
{
    return this->altura;   
}

// Altera a altura do jogador
void Jogador::setAltura(int altura)
{
    this->altura = altura;
}

// Imprime informações do Jogador
void Jogador::imprime() const
{
    string posicao;
    cout << "Nome: " << this->nome << endl;
    cout << "Numero da Camisa: " << this->camisa << endl;
    cout << "Apelido: " << this->apelido << endl;
    cout << "Salario Anual: R$ ";
    cout << fixed << setprecision(2) << this->salario << endl;
    cout << "Ano do termino de contrato: " << this->fimContrato << endl;
    cout << "Idade: " << this->idade << " anos" << endl;
    cout << "Nacionalidade: " << this->nacionalidade << endl;
    cout << "Altura: " << this->altura << " m" << endl;

    switch (this->getPosicao())
    {
        case GOLEIRO:
            posicao = "Goleiro";
            break;
        case DEFENSOR:
            posicao = "Defensor";
            break;
        case MEIO_CAMPISTA:
            posicao = "Meio-campista";
            break;
        case ATACANTE:
            posicao = "Atacante";
            break;
    }
    cout << "Posicao: " << posicao << endl;
}

// Compara em ordem alfabética crescente
bool Jogador::comparaNome(Jogador* j1, Jogador *j2)
{
    string nome1 = j1->nome;
    string nome2 = j2->nome;
    transform(nome1.begin(), nome1.end(), nome1.begin(), ::tolower);
    transform(nome2.begin(), nome2.end(), nome2.begin(), ::tolower);
    return nome1 < nome2;
}

bool Jogador::comparaCamisa(Jogador* j1, Jogador *j2)
{
    return j1->getCamisa() < j2->getCamisa();
}

bool Jogador::comparaPosicao(Jogador* j1, Jogador *j2)
{
    if(j1->getPosicao() == j2->getPosicao())
    {
        return comparaNome(j1,j2);
    }
    return j1->getPosicao() < j2->getPosicao();
}

bool Jogador::comparaSalario(Jogador* j1, Jogador *j2)
{
    if(j1->getSalario() == j2->getSalario())
    {
        return comparaNome(j1,j2);
    }
    return j1->getSalario() > j2->getSalario();
}

bool Jogador::comparaApelido(Jogador* j1, Jogador *j2)
{
    string apelido1 = j1->apelido;
    string apelido2 = j2->apelido;
    transform(apelido1.begin(), apelido1.end(), apelido1.begin(), ::tolower);
    transform(apelido2.begin(), apelido2.end(), apelido2.begin(), ::tolower);
    return apelido1 < apelido2;
}

bool Jogador::comparaFimContrato(Jogador* j1, Jogador *j2)
{
    if(j1->getFimContrato() == j2->getFimContrato())
    {
        return comparaNome(j1,j2);
    }
    return j1->getFimContrato() < j2->getFimContrato();
}

bool Jogador::comparaIdade(Jogador* j1, Jogador *j2)
{
    return j1->getIdade() > j2->getIdade();
}
