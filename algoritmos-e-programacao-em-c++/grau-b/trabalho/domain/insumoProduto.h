#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class insumoProduto {
    Insumo insumo;
    int quantidade;

public:
    insumoProduto(Insumo insumo, int quantidade) {
        this->insumo = insumo;
        this->quantidade = quantidade;
    }

    Insumo getInsumo() {
        return this->insumo;
    }

    int getQuantidade () {
        return this->quantidade;
    }
};
