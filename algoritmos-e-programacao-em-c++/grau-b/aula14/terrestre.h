#include <iostream>

using namespace std;

class Terrestre : public Veiculo {
    private:
        int qtRoda;
        int qtPorta;

    public:
        Terrestre(int ano, int peso, float tanque, string modelo, int qtRoda, int qtPorta)
            : Veiculo(ano, peso, tanque, modelo) {
                this->qtRoda = qtRoda;
                this->qtPorta = qtPorta;
        }

        void info() {
            this->Veiculo::info();

            cout << "Quantidade de Rodas: " << this->qtRoda << endl;
            cout << "Quantidade de Portas: " << this->qtPorta << endl;
            cout << "Consumo: " << this->consumo() << " Km/l" << endl;
            cout << "Autonomia: " << this->Veiculo::autonomia(this->consumo()) << " Km" << endl;
        }

        float consumo() {
            return 1/((this->peso * 0.00005) + (this->qtRoda * 0.005));
        }
};
