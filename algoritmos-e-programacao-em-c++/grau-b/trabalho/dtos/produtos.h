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
            int colCount = 0, insumoCount;
            vector<string> vectorStr;
            Insumo insumo;

            for (col = row->begin(); col != row->end(); col++) {
                switch (colCount) {
                    case 0:
                        produto.setNome(*col);
                        break;
                    case 1:
                        vectorStr = split(*col, '|');
                        insumoCount = 0;

                        for (auto i = vectorStr.begin(); i != vectorStr.end(); i++ ) {

                            if(insumoCount % 2 == 0) {
                                insumo.setNome(*i);
                            } else {
                                produto.adicionaInsumo(insumo, stoi(*i));
                            }

                            insumoCount++;
                        }

                        break;
                    case 2:
                        vectorStr = split(*col, '|');

                        for (auto i = vectorStr.begin(); i != vectorStr.end(); i++ ) {
                            produto.adicionaProcesso(*i);
                        }

                        break;
                }

                colCount++;
            }

            adicionaProduto(produto);
        }
    }

};
