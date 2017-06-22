#include <iostream>

using namespace std;

class Veiculo {
    protected:
        int ano;
        int peso;
        float tanque;
        string modelo;

    public:
        Veiculo(int ano, int peso, float tanque, string modelo) {
            this->ano = ano;
            this->peso = peso;
            this->tanque = tanque;
            this->modelo = modelo;
        }

        void info() {
            cout << "Ano: " << this->ano << endl;
            cout << "Peso: " << this->peso << endl;
            cout << "Tanque: " << this->tanque << endl;
            cout << "Modelo: " << this->modelo << endl;
        }

        float autonomia(float consumo) {
            return this->tanque * consumo;
        }
};
