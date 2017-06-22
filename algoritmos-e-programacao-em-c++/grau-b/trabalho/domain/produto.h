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

    string toString() {
        return "Nome: " + this->nome;
    }

    void adicionaInsumo(Insumo insumo, int quantidade) {
        this->insumos.push_back(new insumoProduto(insumo, quantidade));
    }

    void adicionaProcesso(string nome) {
        Processo *processo = new Processo();
        processo->setNome(nome);

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

    vector <Processo*> getProcessos() {
        return this->processos;
    }

    void listaInsumos() {
        for(auto value: this->insumos) {
            cout << value->toString() << endl;
        }
    }

	void listarProcessos(Processos *processos) {
        for(auto value: this->processos) {
            Processo processo = processos->getProcessoByNome(value->getNome());

            cout << "Nome: " << processo.getNome() << " - Tempo: " << to_string(processo.getTempo()) << " minuto(s)" << endl;
        }
    }
};
