#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "helpers/CSVReader.h"
#include "helpers/StringSplit.h"
#include "helpers/clear.h"

#include "domain/insumo.h"
#include "domain/processo.h"
#include "domain/insumoProduto.h"

#include "dtos/insumos.h"
#include "dtos/processos.h"

#include "domain/produto.h"
#include "dtos/produtos.h"
#include "domain/produtoOP.h"
#include "domain/ordemProducao.h"

using namespace std;

CSVReader   *reader       = new CSVReader();
Insumos     *insumos      = new Insumos();
Processos   *processos    = new Processos();
Produtos    *produtos     = new Produtos();
OrdemProducao *ordemProducao;

void pause() {
    cout << endl << "Pressione <ENTER> para continuar";
    getchar();
    getchar();
}

void printMenu() {
    clear();
    cout <<
        "MENU" << endl << endl <<

        "1. Listar Insumos"             << endl <<
        "2. Listar Processos"           << endl <<
        "3. Listar Produtos"            << endl <<
        "4. Detalhar Produto"           << endl <<
        "5. Adicionar Estoque"          << endl <<
        "6. Abrir Ordem de Producao"    << endl <<
        "7. Imprimir Ordem de Producao" << endl <<
        "8. Liberar Ordem de Producao"  << endl <<
        "9. Sair"                       << endl << endl <<

        "Escolha uma opção: ";
}

void listarInsumos() {
    int count = 1;

    for(auto value: insumos->getInsumos()) {
        cout << count++ << " - " << value.toString() << endl;
    }
}

void listarProcessos() {
    int count = 1;

    for(auto value: processos->getProcessos()) {
        cout << count++ << " - " << value.toString() << endl;
    }
}

void listarProdutos() {
    int count = 1;

    for(auto value: produtos->getProdutos()) {
        cout << count++ << " - " << value.toString() << endl;
    }
}

void detalharProduto() {
    int idProduto;

    listarProdutos();

    cout << endl << "Escolha o produto: ";
    cin >> idProduto;
    cout << endl;

    Produto produto = produtos->getProdutos()[idProduto - 1];

    cout << endl << produto.getNome() << ":" << endl << "Insumos: " << endl;
    produto.listaInsumos();
    cout << "Processos: " << endl;
    produto.listarProcessos(processos);
}

void adicionarEstoque() {
    int idInsumo, quantidade;

    listarInsumos();

    cout << endl << "Escolha o insumo: ";
    cin >> idInsumo;
    cout << "Informe a quantidade: ";
    cin >> quantidade;

    insumos->getInsumo(idInsumo - 1)->adicionaEstoque(quantidade);

    cout << "salvou";

    reader->objectWriter< Insumos* >(insumos, "database/insumo.txt");
    insumos->clear();
    reader->objectParser< Insumos* >(insumos, "database/insumo.txt");

    listarInsumos();
}

void abrirOrdemProducao() {
    string nomeCliente, dataEntrega;
    int quantidade = -1, idProduto;

    fflush(stdin);

    cout << "Informe o nome do cliente: ";
    cin >> nomeCliente;

    cout << endl << "Informe a data de entrega: ";
    cin >> dataEntrega;

    cout << endl;

    ordemProducao = new OrdemProducao(nomeCliente, dataEntrega, processos);

    do {
        clear();

        listarProdutos();

        cout << "Informe a quantidade: ";
        cin >> quantidade;

        if(quantidade == 0) {
            break;
        }

        cout << endl << "Informe o produto: ";
        cin >> idProduto;

        Produto produto = produtos->getProdutos()[idProduto - 1];

        ordemProducao->adicionaProduto(produto, quantidade);
    } while(quantidade != 0);
}

void imprimeFicha() {
    ordemProducao->imprimeFicha();
    reader->objectWriter< OrdemProducao* >(ordemProducao, "database/ficha.txt");
}

void liberaProducao() {
    if(ordemProducao->liberaProducao(insumos)) {
        cout << "Ordem de produção liberada com sucesso!";
        reader->objectWriter< Insumos* >(insumos, "database/insumo.txt");
    } else {
        insumos->clear();
        reader->objectParser< Insumos* >(insumos, "database/insumo.txt");
    }
}

void menu() {
    int option = 0;

    do {
        clear();

        printMenu();
        cin >> option;

        clear();

        switch (option) {
            case 1:
                listarInsumos();
                pause();
                break;
            case 2:
                listarProcessos();
                pause();
                break;
            case 3:
                listarProdutos();
                pause();
                break;
            case 4:
                detalharProduto();
                pause();
                break;
            case 5:
                adicionarEstoque();
                pause();
                break;
            case 6:
                abrirOrdemProducao();
                pause();
                break;
            case 7:
                imprimeFicha();
                pause();
                break;
            case 8:
                liberaProducao();
                pause();
                break;
        }
    } while(option != 9);
}

int main(){
    reader->objectParser< Insumos* >(insumos, "database/insumo.txt"); // load 'insumo'
    reader->objectParser< Processos* >(processos, "database/processo.txt"); // load 'processo'
    reader->objectParser< Produtos* >(produtos, "database/produto.txt"); // load 'produto'

    menu();
}
