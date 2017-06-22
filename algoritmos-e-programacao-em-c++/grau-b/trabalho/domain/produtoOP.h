#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class ProdutoOP{
    Produto produto;
    int quantidade;

public:
    ProdutoOP(Produto produto, int quantidade) {
        this->quantidade = quantidade;
        this->produto = produto;
    }

    Produto getProduto() {
        return this->produto;
    }

    int getQuantidade() {
        return this->quantidade;
    }
};
