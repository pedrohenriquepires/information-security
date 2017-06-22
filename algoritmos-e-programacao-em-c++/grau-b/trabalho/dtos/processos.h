#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <regex>


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

    Processo getProcessoByNome(string nome) {
        Processo processo;
        regex expression ("\\W");

        for(auto value: this->processos) {
            nome = regex_replace(nome, expression, "");

            // cout << value.getNome() << "(" << value.getNome().length() << ")" << " - " << nome  << "(" << nome.length() << ")" << endl;

            if(strcmp(value.getNome().c_str(), nome.c_str()) == 0) {
                processo = value;
            }
        }

        return processo;
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
                        processo.setTempo(stoi(*col));
                        break;
                }

                colCount++;
            }

            adicionaProcesso(processo);
        }
    }

};
