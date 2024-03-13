#ifndef DEFENSOR_H
#define DEFENSOR_H

#include "Jogador.h"

class Defensor : public Jogador
{
    public:
        Defensor(string nome, string apelido, double salario, int camisa, string posicaoDefesa, int fimContrato,
        float altura, string nacionalidade, int idade); // Construtor
        virtual ~Defensor(); // Destrutor
        string getPosicaoDefesa() const; // Indica a posição especifica do defensor
        void setPosicaoDefesa(string posicaoDefesa); // Altera a posiçaõe especifica do defensor
        int getPosicao() const; // Indicador de posição
        void imprime() const; // Imprime informações do defensor
    private:
        string posicaoDefesa; // Informa a posição especifica do jogador na defesa
};
#endif