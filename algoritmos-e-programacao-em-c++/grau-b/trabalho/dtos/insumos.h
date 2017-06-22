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

    void clear() {
        this->insumos.clear();
    }

    Insumo* getInsumo(int id) {
        return &insumos[id];
    }

    void adicionaInsumo(Insumo insumo){
        insumos.push_back(insumo);
    }

    void retiraEstoque(string nome, int quantidade) {
        int counter = 0;

        for(auto value : this->insumos) {
            if(nome == value.getNome()) {
                this->insumos[counter].retiraEstoque(quantidade);
            } else {
                counter++;
            }
        }
    }

    string write() {
        string str;

        for(auto value: this->insumos) {
            str += value.getNome() + "," + value.getUnidade() + "," + to_string(value.getQtEstoque()) + "\n";
        }

        return str;
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
                        insumo.setQtEstoque(stoi(*col));
                        break;
                }

                colCount++;
            }

            adicionaInsumo(insumo);
        }
    }

};
