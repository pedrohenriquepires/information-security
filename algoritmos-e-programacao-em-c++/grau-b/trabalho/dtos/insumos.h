#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Insumos {
    vector<Insumo> insumos;

public:
    Insumos(){}

    vector<Insumo> getInsumos() {
        return this->insumos;
    }

    void adicionaInsumo(Insumo insumo){
        insumos.push_back(insumo);
    }

    void parse(vector<vector<string>> str)
    {
        vector< vector<string> >::iterator row;
        vector<string>::iterator col;

        for (row = str.begin(); row != str.end(); row++) {
            Insumo insumo;
            int colCount = 0;

            for (col = row->begin(); col != row->end(); col++) {
                switch (colCount) {
                    case 0:
                        insumo.setNome(*col);
                        break;
                    case 1:
                        insumo.setUnidade(*col);
                        break;
                    case 2:
                        insumo.setQtEstoque(1);
                        break;
                }

                colCount++;
            }

            adicionaInsumo(insumo);
        }
    }

};
