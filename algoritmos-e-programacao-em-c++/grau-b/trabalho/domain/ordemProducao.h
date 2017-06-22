#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class OrdemProducao{
    string cliente;
    string dataEntrega;
    vector<ProdutoOP*> produtos;
    Processos *processos;

public:
    OrdemProducao(string cliente, string dataEntrega, Processos *processos) {
        this->cliente = cliente;
        this->dataEntrega = dataEntrega;
        this->processos = processos;
    }

    void adicionaProduto(Produto produto, int qtProdutos) {
        produtos.push_back(new ProdutoOP(produto, qtProdutos));
    }

    string getCliente() {
        return this->cliente;
    }

    string getDataEntrega() {
        return this->dataEntrega;
    }

    string write() {
        string str;

        str += "Cliente: " + this->cliente + "\n" +
                "Data: " + this->dataEntrega + "\n\n";

        str += "Produtos: \n";

        for(auto value: this->produtos) {
            str += to_string(value->getQuantidade()) + " - ";
            str += value->getProduto().getNome() + "\n";

            str += "Insumos: \n";
            for(auto insumo: value->getProduto().getInsumos()) {
                str += " - " + insumo->getInsumo().getNome() + " (" + to_string(insumo->getQuantidade() * value->getQuantidade()) + ")\n";
            }

            str += "\nProcessos: \n";
            for(auto proc: value->getProduto().getProcessos()) {
                Processo processo = this->processos->getProcessoByNome(proc->getNome());

                str += " - " + processo.getNome() + " - Tempo: " + to_string(processo.getTempo() * value->getQuantidade()) + " minuto(s)\n";
            }

            str += "\n";
        }

        return str;
    }

    void imprimeFicha() {
        cout << write();
    }

    bool liberaProducao(Insumos *insumos) {
        bool canBuild = true;

        for(auto produto: this->produtos) {
            for(auto produtoInsumo: produto->getProduto().getInsumos()) {
				insumos->retiraEstoque(produtoInsumo->getInsumo().getNome(), produtoInsumo->getQuantidade() * produto->getQuantidade());
            }
        }

        for(auto insumo : insumos->getInsumos()) {
            if(insumo.getQtEstoque() < 0) {
                cout << insumo.getNome() << " insuficiente. Por favor, adicione pelo menos mais " << (insumo.getQtEstoque() * -1) << " unidade(s) no estoque." << endl;
                canBuild = false;
            }
        }

        return canBuild;
    }
};
