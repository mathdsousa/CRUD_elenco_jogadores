#ifndef GOLEIRO_H
#define GOLEIRO_H

#include "Jogador.h"

class Goleiro : public Jogador
{
    public:
        Goleiro(string nome, string apelido, double salario, int camisa, int fimContrato,
        float altura, string nacionalidade, int idade); // Construtor
        virtual ~Goleiro(); // Destrutor
        int getPosicao() const; // Indicador de posição
};
#endif