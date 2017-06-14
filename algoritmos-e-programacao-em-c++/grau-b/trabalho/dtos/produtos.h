#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Produtos {
    vector<Produto> produtos;

public:
    Produtos(){}

    vector<Produto> getProdutos() {
        return this->produtos;
    }

    void adicionaProduto(Produto produto){
        produtos.push_back(produto);
    }

    void parse(vector<vector<string>> str)
    {
        vector< vector<string> >::iterator row;
        vector<string>::iterator col;

        for (row = str.begin(); row != str.end(); row++) {
            Produto produto;
            int colCount = 0;

            for (col = row->begin(); col != row->end(); col++) {
                switch (colCount) {
                    case 0:
                        produto.setNome(*col);
                        break;
                    case 1:
                        vector<string> insumosStr = split(*col, '|');
                        int insumoCount = 0;

                        for (auto i = insumosStr.begin(); i != insumosStr.end(); i++ ) {
                            Insumo insumo;

                            if(insumoCount % 2 == 0) {
                                insumo.setNome(*i);
                            } else {
                                produto.adicionaInsumo(insumo, stoi(*i));
                            }

                            insumoCount++;
                        }

                        break;
                }

                colCount++;
            }

            adicionaProduto(produto);
        }
    }

};
