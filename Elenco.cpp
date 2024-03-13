#include "Elenco.h"
#include "Goleiro.h"
#include "Defensor.h"
#include "MeioCampista.h"
#include "Atacante.h"

// Construtor
Elenco::Elenco(string fileName) : fileName(fileName)
{
    this->recupera();
}

// Destrutor
Elenco::~Elenco()
{

}

// Adiciona um jogador no elenco
bool Elenco::adiciona(int posicao)
{
    string nome, apelido, posicaoEspecifica, nacionalidade;
    double salario;
    float altura;
    int numCamisa, fimContrato, idade;
    Jogador* j;
    cout << "Numero da Camisa: ";
    cin >> numCamisa; 

    int pos = indice(numCamisa);
    bool camisaUsada = pos < this->jogadores.size() ? true : false; // Verifica se a camisa já está sendo usada

    if(camisaUsada == false)
    {
        // Capitação dos atributos do jogador 
        cin.ignore();
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Apelido: ";
        getline(cin, apelido);
        cout << "Salario anual: ";
        cin >> salario;
        cout << "Ano do termino de contrato: ";
        cin >> fimContrato;
        cout << "Altura: ";
        cin >> altura;
        cin.ignore();
        cout << "Nacionalidade: ";
        getline(cin, nacionalidade);
        cout << "Idade: ";
        cin >> idade;
        cin.ignore();

        switch (posicao)
        {
            case GOLEIRO:
                j = new Goleiro(nome, apelido, salario, numCamisa, fimContrato, altura, nacionalidade, idade);
                break;
            case DEFENSOR:
                cout << "Posicao especifica na defesa: ";
                getline(cin, posicaoEspecifica);
                j = new Defensor(nome, apelido, salario, numCamisa, posicaoEspecifica, fimContrato, altura, nacionalidade, idade);
                break;

            case MEIO_CAMPISTA:
                cout << "Posicao especifica no meio-campo: ";
                getline(cin, posicaoEspecifica);
                j = new MeioCampista(nome, apelido, salario, numCamisa, posicaoEspecifica, fimContrato, altura, nacionalidade, idade);
                break;

            case ATACANTE:
                cout << "Posicao especifica no ataque: ";
                getline(cin, posicaoEspecifica);
                j = new Atacante(nome, apelido, salario, numCamisa, posicaoEspecifica, fimContrato, altura, nacionalidade, idade);
                break;
        }
        jogadores.push_back(j);
        grava();
        cout << endl;
        cout << "Jogador adicionado com sucesso!" << endl;
        return true;
    }
    else
    {
        cout << "Essa camisa ja esta sendo usada! Tente novamente." << endl;
        return false;
    }
}

// Imprime os jogadores de forma ordenada
void Elenco::imprimeOrdenado()
{
    // Cria um cópia do vector de jogadores
    vector<Jogador*>copia = jogadores;

    // Menu para o usuário escolher a forma de ordenação
    char escolha;
    cout << "[N] Ordenado pelo nome (crescente)" << endl;
    cout << "[C] Ordenado pelo numero da camisa (crescente)" << endl;
    cout << "[A] Ordenado pelo apelido (crescente)" << endl;
    cout << "[P] Ordenado pela posicao (Goleiro, Defensor, Meio-Campista, Atacante)" << endl;
    cout << "[S] Ordenado pelo salario (decrescente)" << endl;
    cout << "[F] Ordenado pelo ano de fim de contrato (crescente)" << endl;
    cout << "[I] Ordenado pela idade (decrescente)" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    escolha = toupper(escolha);
    cout << endl;

    // Ordenação com base na escolha
    switch(escolha)
    {
        case 'N':
            sort(copia.begin(), copia.end(), Jogador::comparaNome);
            break;
        case 'C':
            sort(copia.begin(), copia.end(), Jogador::comparaCamisa);
            break;
        case 'A':
            sort(copia.begin(), copia.end(), Jogador::comparaApelido);
            break;
        case 'P':
            sort(copia.begin(), copia.end(), Jogador::comparaPosicao);
            break;
        case 'S':
            sort(copia.begin(), copia.end(), Jogador::comparaSalario);
            break;
        case 'F':
            sort(copia.begin(), copia.end(), Jogador::comparaFimContrato);
            break;
        case 'I':
            sort(copia.begin(), copia.end(), Jogador::comparaIdade);
            break;
        default:
            break;
    }

    // Impressão do vector de cópia já ordenado
    for(long unsigned int i = 0; i < copia.size(); i++)
    {
        copia[i]->imprime();
        cout << endl;
    }
}

// Imprime com base na busca pela camisa do jogador
void Elenco::imprime(int numeroCamisa)
{
    int pos = indice(numeroCamisa);

    if(pos != -1)
    {
        this->jogadores[pos]->imprime();
    }
    else
    {
        cout << "Numero de camisa nao encontrado!" << endl;
    }
}

// Remove com base na busca pela camisa do jogador
bool Elenco::remove(int numeroCamisa)
{
    bool ok = false;
    int pos = indice(numeroCamisa);

    if(pos != -1)
    {
        string nome = this->jogadores[pos]->getApelido();
        this->jogadores.erase(this->jogadores.begin() + pos);
        grava();
        ok = true;
        cout << nome <<" foi removido com sucesso!" << endl;
    }
    else
    {
        cout << "Numero de camisa nao encontrado!" << endl;
    }

    return ok;
}

// Atualiza os atributos de um jogador
bool Elenco::atualiza(int numeroCamisa)
{
    Defensor* d;
    MeioCampista *m;
    Atacante* a;
    bool ok = false;
    int escolha = 1;
    // Menu para o usuário escolher qual atributo será atualizado
    int pos = indice(numeroCamisa);
    if(pos != -1)
    {
        cout << numeroCamisa << " - " << this->jogadores[pos]->getApelido() << endl << endl;
        cout << "1. Atualiza apelido" << endl;
        cout << "2. Atualiza numero" << endl;
        cout << "3. Atualiza salario" << endl;
        cout << "4. Atualiza contrato" << endl;
        cout << "5. Atualiza posicao especifica (Defensor, Meio-campista ou Atacante)" << endl;
        cout << "6. Atualiza nome" << endl;
        cout << "7. Atualiza altura" << endl;
        cout << "8. Atualiza nacionalidade" << endl;
        cout << "9. Atualiza idade" << endl;
        cout << "Escolha: ";
        cin >> escolha;
        cin.ignore();
        cout << endl;
        // Implementação da atualização dos atributos
        // OBS: tive que usar if e else-if, pois eu precisava declarar novas variáveis em cada caso,
        // o switch não permite isso, pois causa um desvio de fluxo
        if(pos != -1)
        {
            if(escolha == 1)
            {
                string apelido;
                cout << "Apelido: ";
                getline(cin, apelido);
                jogadores[pos]->setApelido(apelido);
                grava();
                ok = true;
            }
            else if (escolha == 2)
            {
                long unsigned int tam = this->jogadores.size();
                long unsigned int pos = 0;
                int numero;
                cout << "Numero da camisa: ";
                cin >> numero;
                while(pos < tam && this->jogadores[pos]->getCamisa() != numeroCamisa)
                {
                    pos++;
                }
                if(pos < tam)
                {
                    cout << "Essa camisa ja esta sendo usada" << endl;
                }
                else
                {
                    jogadores[pos]->setCamisa(numero);
                    grava();
                    ok = true;
                }
            }
            else if(escolha == 3)
            {
                double salario;
                cout << "Salario: ";
                cin >> salario;
                jogadores[pos]->setSalario(salario);
                grava();
                ok = true;
            }
            else if(escolha == 4)
            {
                int ano;
                cout << "Ano do fim de contrato: ";
                cin >> ano;
                jogadores[pos]->setFimContrato(ano);
                grava();
                ok = true;
            }
            else if(escolha == 5)
            {
                string novaposicao;
                switch (jogadores[pos]->getPosicao())
                {
                    case DEFENSOR:
                        d = dynamic_cast<Defensor*>(this->jogadores[pos]);
                        cout << "Posicao de defesa: ";
                        getline(cin, novaposicao);
                        d->setPosicaoDefesa(novaposicao);
                        this->jogadores[pos] = d;
                        break;
                    case MEIO_CAMPISTA:
                        m = dynamic_cast<MeioCampista*>(this->jogadores[pos]);
                        cout << "Posicao de meio-campo: ";
                        getline(cin, novaposicao);
                        m->setPosicaoMeioCampo(novaposicao);
                        this->jogadores[pos] = m;
                        break;
                    case ATACANTE:
                        a = dynamic_cast<Atacante*>(this->jogadores[pos]);
                        cout << "Posicao de ataque: ";
                        getline(cin, novaposicao);
                        a->setPosicaoAtaque(novaposicao);
                        a->imprime();
                        this->jogadores[pos] = a;
                        break;    
                    default:
                        break;
                }
                grava();
                ok = true;
            }
            else if(escolha == 6)
            {
                string nome;
                cout << "Nome: ";
                getline(cin, nome);
                jogadores[pos]->setNome(nome);
                grava();
                ok = true;
            }
            else if(escolha == 7)
            {
                float altura;
                cout << "Altura: ";
                cin >> altura;
                jogadores[pos]->setAltura(altura);
                grava();
                ok = true;
            }
            else if(escolha == 8)
            {
                string nacionalidade;
                cout << "Nacionalidade: ";
                getline(cin, nacionalidade);
                jogadores[pos]->setNacionalidade(nacionalidade);
                grava();
                ok = true;
            }
            else if(escolha == 9)
            {
                int idade;
                cout << "Idade: ";
                cin >> idade;
                jogadores[pos]->setIdade(idade);
                grava();
                ok = true;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Numero de camisa nao encontrado!" << endl;
    }
    if(ok == true)
    {
        cout << "Informacao atualizada!" << endl;
    }
    return ok;
}

// Menu de opções para o usuário
int Elenco::opcao()
{
    int escolha;
    
    cout << "1. Imprime as informacoes dos jogadores do elenco de forma ordenada" << endl;
    cout << "2. Imprime as informacoes de um jogador pelo numero da camisa" << endl;
    cout << "3. Remove um jogador do elenco" << endl;
    cout << "4. Atualiza informacoes de um jogador" << endl;
    cout << "5. Adiciona um goleiro ao elenco" << endl;
    cout << "6. Adiciona um defensor ao elenco" << endl;
    cout << "7. Adiciona um meio-campista ao elenco" << endl;
    cout << "8. Adiciona um atacante ao elenco" << endl;
    cout << "0. Fim" << endl;
    cout << "Opcao: ";
    cin >> escolha;

    cout << endl;

    return escolha;
}

// Grava no arquivo
void Elenco::grava()
{
    string nome, apelido, posicaoEspecifica, nacionalidade;
    int numCamisa, fimContrato, posicao, tam, idade;
    float altura;
    double salario;
    Goleiro* g1;
    Defensor* d1;
    MeioCampista* m1;
    Atacante* a1;

    ofstream saida(fileName, ios::binary);

    for(long unsigned int i = 0; i < this->jogadores.size(); i++)
    {
        // Escrevendo a posição do Jogador
        posicao = this->jogadores[i]->getPosicao();
        saida.write(reinterpret_cast<char*>(&posicao), sizeof(posicao));

        // Escrevendo o número da camisa do jogador
        numCamisa = this->jogadores[i]->getCamisa();
        saida.write(reinterpret_cast<char*>(&numCamisa), sizeof(numCamisa));

        // Escrevendo o nome
        nome = this->jogadores[i]->getNome();
        tam = nome.size();
        saida.write(reinterpret_cast<char*>(&tam), sizeof(tam)); // Escrevendo o tamanho da string 
        saida.write(reinterpret_cast<char*>(&nome[0]), tam); // Escrevendo os caracteres da string

        // Escrevendo o apelido do jogador
        apelido = this->jogadores[i]->getApelido();
        tam = apelido.size();
        saida.write(reinterpret_cast<char*>(&tam), sizeof(tam)); // Escrevendo o tamanho da string
        saida.write(reinterpret_cast<char*>(&apelido[0]), tam); // Escrevendo os caracteres da string

        // Escrevendo o salário do jogador
        salario = this->jogadores[i]->getSalario();
        saida.write(reinterpret_cast<char*>(&salario), sizeof(salario));

        // Escrevendo o ano do fim de contrato do jogador
        fimContrato = this->jogadores[i]->getFimContrato();
        saida.write(reinterpret_cast<char*>(&fimContrato), sizeof(fimContrato));

        // Escrevendo a altura do jogador
        altura = this->jogadores[i]->getAltura();
        saida.write(reinterpret_cast<char*>(&altura), sizeof(altura));
        
        // Escrevendo a nacionalidade do jogador
        nacionalidade = this->jogadores[i]->getNacionalidade();
        tam = nacionalidade.size();
        saida.write(reinterpret_cast<char*>(&tam), sizeof(tam)); // Escrevendo o tamanho da string
        saida.write(reinterpret_cast<char*>(&nacionalidade[0]), tam); // Escrevendo os caracteres da string
        
        // Escrevendo a idade do jogador
        idade = this->jogadores[i]->getIdade();
        saida.write(reinterpret_cast<char*>(&idade), sizeof(idade));

        // Escrevendo atributos espcíficos da classe Defensor, Meio-Campista ou Atacante
        switch (posicao)
        {
            case DEFENSOR:
                // Escrevendo a posição específica do jogador de defesa
                d1 = dynamic_cast<Defensor*>(this->jogadores[i]);
                posicaoEspecifica = d1->getPosicaoDefesa();
                tam = posicaoEspecifica.size();
                saida.write(reinterpret_cast<char*>(&tam), sizeof(tam)); // Escrevendo o tamanho da string
                saida.write(reinterpret_cast<char*>(&posicaoEspecifica[0]), tam); // Escrevendo os caracteres da string
                break;

            case MEIO_CAMPISTA:
                // Escrevendo a posição específica do jogador de meio-campista
                m1 = dynamic_cast<MeioCampista*>(this->jogadores[i]);
                posicaoEspecifica = m1->getPosicaoMeioCampo();
                tam = posicaoEspecifica.size();
                saida.write(reinterpret_cast<char*>(&tam), sizeof(tam)); // Escrevendo o tamanho da string
                saida.write(reinterpret_cast<char*>(&posicaoEspecifica[0]), tam); // Escrevendo os caracteres da string
                break;

            case ATACANTE:
                // Escrevendo a posição específica do jogador de atacante
                a1 = dynamic_cast<Atacante*>(this->jogadores[i]);
                posicaoEspecifica = a1->getPosicaoAtaque();
                tam = posicaoEspecifica.size();
                saida.write(reinterpret_cast<char*>(&tam), sizeof(tam)); // Escrevendo o tamanho da string
                saida.write(reinterpret_cast<char*>(&posicaoEspecifica[0]), tam); // Escrevendo os caracteres da string
                break;
                
            default:
                break;
        }
    }
    saida.close();
}

// Lê os dados do arquivo
void Elenco::recupera()
{
    string nome, apelido, posicaoEspecifica, nacionalidade;
    int numCamisa, fimContrato, posicao, tam, idade;
    double salario;
    float altura;

    ifstream entrada(fileName, ios::binary);

    if(entrada.is_open())
    {
        jogadores.clear();

        // Lendo a posicao do jogador
        entrada.read(reinterpret_cast<char*>(&posicao), sizeof(posicao));
        
        while(entrada.good())
        {
            // Lendo o número da camisa
            entrada.read(reinterpret_cast<char*>(&numCamisa), sizeof(numCamisa));

            // Lendo o nome
            entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam)); // Lendo o tamanho da string
            nome.resize(tam);
            entrada.read(reinterpret_cast<char*>(&nome[0]), tam); // Lendo os caracteres da string

            // Lendo o apelido
            entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam)); // Lendo o tamanho da string
            apelido.resize(tam);
            entrada.read(reinterpret_cast<char*>(&apelido[0]), tam); // Lendo os caracteres da string
            
            // Lendo o salario do jogador
            entrada.read(reinterpret_cast<char*>(&salario), sizeof(salario));

            // Lendo o ano de fim de contrato do jogador
            entrada.read(reinterpret_cast<char*>(&fimContrato), sizeof(fimContrato));

            // Lendo a altura de fim de contrato do jogador
            entrada.read(reinterpret_cast<char*>(&altura), sizeof(altura));
            
            // Lendo o nacionalidade
            entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam)); // Lendo o tamanho da string
            nacionalidade.resize(tam);
            entrada.read(reinterpret_cast<char*>(&nacionalidade[0]), tam); // Lendo os caracteres da string

            // Lendo a idade do jogador
            entrada.read(reinterpret_cast<char*>(&idade), sizeof(idade));

            // Lendo as caracteristicas específicas dos jogadores
            switch (posicao)
            {
                case DEFENSOR:
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam)); // Lendo o tamanho da string
                    posicaoEspecifica.resize(tam);
                    entrada.read(reinterpret_cast<char*>(&posicaoEspecifica[0]), tam); // Lendo os caracteres da string
                    this->jogadores.push_back(new Defensor(nome, apelido, salario, numCamisa, posicaoEspecifica, fimContrato, altura, nacionalidade, idade)); // Inserindo no vector
                    break;

                case MEIO_CAMPISTA:
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam)); // Lendo o tamanho da string
                    posicaoEspecifica.resize(tam);
                    entrada.read(reinterpret_cast<char*>(&posicaoEspecifica[0]), tam); // Lendo os caracteres da string
                    this->jogadores.push_back(new MeioCampista(nome, apelido, salario, numCamisa, posicaoEspecifica, fimContrato, altura, nacionalidade, idade)); // Inserindo no vector
                    break;

                case ATACANTE:
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam)); // Lendo o tamanho da string
                    posicaoEspecifica.resize(tam);
                    entrada.read(reinterpret_cast<char*>(&posicaoEspecifica[0]), tam); // Lendo os caracteres da string
                    this->jogadores.push_back(new Atacante(nome, apelido, salario, numCamisa, posicaoEspecifica, fimContrato, altura, nacionalidade, idade)); // Inserindo no vector
                    break;

                default:
                    this->jogadores.push_back(new Goleiro(nome, apelido, salario, numCamisa, fimContrato, altura, nacionalidade, idade)); // Inserindo no vector
                    break;
            }
            // Lendo a posição do jogador
            entrada.read(reinterpret_cast<char*>(&posicao), sizeof(posicao));
        }
    }   
    entrada.close();
}

// Retorna a poição do jogador procurado no vector "jogadores"
int Elenco::indice(int numeroCamisa)
{
    long unsigned int tam = this->jogadores.size();
    long unsigned int pos = 0;

    while(pos < tam && this->jogadores[pos]->getCamisa() != numeroCamisa)
    {
        pos++;
    }

    // Verifica-se o jogador está no elenco
    if(pos < tam)
    {
        return pos;
    }
    else 
    {
        return -1;
    }
}
