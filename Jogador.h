#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

enum TIPO {GOLEIRO, DEFENSOR, MEIO_CAMPISTA, ATACANTE};

class Jogador
{
    public:
        Jogador(string nome, string apelido, double salario, int camisa, int fimContrato,
        float altura, string nacionalidade, int idade); // Construtor
        virtual ~Jogador(); // Destrutor
        string getNome() const; // Consulta Nome
        void setNome(string nome); // Altera o nome
        string getApelido() const; // Consulta o apelido (nome na camisa)
        void setApelido(string apelido); // Altera o apelido
        int getFimContrato() const; // Consulta o ano do fim de contrato 
        void setFimContrato(int fimContrato); // Altera o ano do fim de contrato 
        double getSalario() const; // Consulta Salário
        void setSalario(double salario);
        int getCamisa() const; // Consulta número da camisa do Jogador
        void setCamisa(int camisa); // Altera o número da camisa do Jogador
        int getIdade() const; // Consulta a idade do Jogador
        void setIdade(int idade); // Altera a idade do Jogador
        string getNacionalidade() const; // Consulta nacionalidade
        void setNacionalidade(string nacionalidade); // Altera a nacionalidade
        float getAltura() const; // Consulta idade do Jogador
        void setAltura(int altura); // Altera a idade do Jogador
        virtual int getPosicao() const = 0; // método abstrato da classe
        virtual void imprime() const; // Imprime informações do jogador

        static bool comparaNome (Jogador* j1, Jogador *j2); // Compara nome em ordem alfabética crescente
        static bool comparaCamisa (Jogador* j1, Jogador *j2); // Compara camisa em ordem crescente
        static bool comparaPosicao (Jogador* j1, Jogador *j2); // Ordem: goleiro, defensor, meio-campista, atacante
        static bool comparaSalario (Jogador* j1, Jogador *j2); // Compara em ordem decrescente
        static bool comparaApelido (Jogador* j1, Jogador *j2); // Compara em ordem alfabética crescente
        static bool comparaFimContrato (Jogador* j1, Jogador *j2); // Compara em ordem crescente
        static bool comparaIdade (Jogador* j1, Jogador *j2); // Compara em ordem decrescente

    private:
        string nome;
        string apelido;
        double salario;
        int camisa;
        int fimContrato;
        float altura;
        string nacionalidade;
        int idade;
};

#endif