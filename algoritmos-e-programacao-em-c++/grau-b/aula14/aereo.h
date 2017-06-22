#include <iostream>

using namespace std;

class Aereo : public Veiculo {
    private:
        int qtAsa;
        int qtMotor;

    public:
        Aereo(int ano, int peso, float tanque, string modelo, int qtAsa, int qtMotor)
            : Veiculo(ano, peso, tanque, modelo) {
                this->qtAsa = qtAsa;
                this->qtMotor = qtMotor;
        }

        void info() {
            this->Veiculo::info();

            cout << "Quantidade de Asas: " << this->qtAsa << endl;
            cout << "Quantidade de Motores: " << this->qtMotor << endl;
            cout << "Consumo: " << this->consumo() << " Km/l" << endl;
            cout << "Autonomia: " << this->Veiculo::autonomia(this->consumo()) << " Km" << endl;
        }

        float consumo() {
            return 1/((this->peso * 0.00003) + (this->qtMotor * 0.01));
        }
};
