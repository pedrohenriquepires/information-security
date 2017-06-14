#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Processos {
    vector<Processo> processos;

public:
    Processos(){}

    vector<Processo> getProcessos() {
        return this->processos;
    }

    void adicionaProcesso(Processo processo){
        processos.push_back(processo);
    }

    void parse(vector<vector<string>> str)
    {
        vector< vector<string> >::iterator row;
        vector<string>::iterator col;

        for (row = str.begin(); row != str.end(); row++) {
            Processo processo;
            int colCount = 0;

            for (col = row->begin(); col != row->end(); col++) {
                switch (colCount) {
                    case 0:
                        processo.setNome(*col);
                        break;
                    case 1:
                        processo.setTempo(1);
                        break;
                }

                colCount++;
            }

            adicionaProcesso(processo);
        }
    }

};
