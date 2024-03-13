#ifndef ATACANTE_H
#define ATACANTE_H

#include "Jogador.h"

class Atacante : public Jogador
{
    public:
        Atacante(string nome, string apelido, double salario, int camisa, string posicaoAtaque, int fimContrato,
        float altura, string nacionalidade, int idade); // Construtor
        virtual ~Atacante(); // Destrutor
        string getPosicaoAtaque() const; // Indica a posição especifica do atacante
        void setPosicaoAtaque(string posicaoDefesa); // Altera a posiçaõe especifica do atacante
        int getPosicao() const; // Indicador de posição
        void imprime() const; // Imprime informações do atacante
    private:
        string posicaoAtaque; // Informa a posição especifica do jogador nno ataque
};

#endif