#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Produto
{
private:
    string nome;
    vector <insumoProduto*> insumos;
    vector <Processo*> processos;

public:
    Produto(){}

    void adicionaInsumo(Insumo insumo, int quantidade) {
        this->insumos.push_back(new insumoProduto(insumo, quantidade));
    }

    void adicionaProcesso(Processo *processo) {
        this->processos.push_back(processo);
    }

    void setNome(string nome) {
        this->nome = nome;
    }
    string getNome() {
        return this->nome;
    }

    vector <insumoProduto*> getInsumos() {
        return this->insumos;
    }

    void listaInsumos() {
        for(auto value: this->insumos) {
            cout << value->getInsumo().toString();
        }
    }

    // int tempoProcessos(){
    //     int tempoTotal = 0;
    //     for (vector<Processo*>::iterator it=processos.begin(); it != processos.end(); it++) {
    //         tempoTotal += (*it)->tempo;
    //     }
    // }
    // bool possuiinsumoEmEstoque(){
    //     for (vector<insumoProduto*>::iterator it = insumos.begin((); it!= insumos.end(); i++) {
    //         return (*it)->insumo->qtEstoque > 0;
    //     }
    // }
};
