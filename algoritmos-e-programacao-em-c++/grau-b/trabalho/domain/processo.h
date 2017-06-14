#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Processo{
    string nome;
    int tempo;

public:
    Processo(){}

    string toString(){
        return this->nome + ',' + to_string(this->tempo);
    }

    void setNome(string nome) {
        this->nome = nome;
    }
    string getNome(){
        return this->nome;
    }

    void setTempo(int tempo) {
        this->tempo = tempo;
    }
    int getTempo(){
        return this->tempo;
    }
};
