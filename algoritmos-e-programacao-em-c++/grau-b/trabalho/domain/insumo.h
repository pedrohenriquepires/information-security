#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Insumo {
    string nome, unidade;
    int qtEstoque;

public:
    Insumo(){}

    string toString(){
        return this->nome + ',' + this->unidade + ',' + to_string(this->qtEstoque);
    }
    void adicionaEstoque(int val){
        this->qtEstoque + val;
    }
    void retiraEstoque(int val){
        this->qtEstoque - val;
    }

    void setNome(string nome) {
        this->nome = nome;
    }
    string getNome(){
        return this->nome;
    }

    void setUnidade(string unidade) {
        this->unidade = unidade;
    }
    string getUnidade(){
        return this->unidade;
    }

    void setQtEstoque(int qtEstoque) {
        this->qtEstoque = qtEstoque;
    }
    int getQtEstoque(){
        return this->qtEstoque;
    }
};
