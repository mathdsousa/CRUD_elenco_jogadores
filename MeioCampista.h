#ifndef MEIOCAMPISTA_H
#define MEIOCAMPISTA_H

#include "Jogador.h"

class MeioCampista : public Jogador
{
    public:
        MeioCampista(string nome, string apelido, double salario, int camisa, string posicaoMeioCampo, int fimContrato,
        float altura, string nacionalidade, int idade); // Construtor
        virtual ~MeioCampista(); // Destrutor
        string getPosicaoMeioCampo() const; // Indica a posição especifica do meio-campista
        void setPosicaoMeioCampo(string posicaoMeioCampo); // Altera a posição especifica do meio-campista
        int getPosicao() const; // Indicador de posicao
        void imprime() const;
    private:
        string posicaoMeioCampo; // Informa a posição especifica do jogador no meio-campo
};

#endif