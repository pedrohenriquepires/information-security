#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "helpers/CSVReader.h"
#include "helpers/StringSplit.h"

#include "domain/insumo.h"
#include "domain/processo.h"
#include "domain/insumoProduto.h"
#include "domain/produto.h"

#include "dtos/insumos.h"
#include "dtos/processos.h"
#include "dtos/produtos.h"

using namespace std;

int main(){
    CSVReader *reader = new CSVReader();

    Insumos *insumos = new Insumos();
    Processos *processos = new Processos();
    Produtos *produtos = new Produtos();

    reader->objectParser< Insumos* >(insumos, "database/insumo.txt"); // load 'insumo'
    reader->objectParser< Processos* >(processos, "database/processo.txt"); // load 'processo'
    reader->objectParser< Produtos* >(produtos, "database/produto.txt"); // load 'produto'

    for(auto value: produtos->getProdutos()) {
        value.listaInsumos();
        cout << endl;
    }
}
