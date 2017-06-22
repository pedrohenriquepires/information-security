#include <iostream>

using namespace std;

class Aquatico : public Veiculo {
    private:
        int qtConves;
        int qtMotor;

    public:
        Aquatico(int ano, int peso, float tanque, string modelo, int qtConves, int qtMotor)
            : Veiculo(ano, peso, tanque, modelo) {
                this->qtConves = qtConves;
                this->qtMotor = qtMotor;
        }

        void info() {
            this->Veiculo::info();

            cout << "Quantidade de Convés: " << this->qtConves << endl;
            cout << "Quantidade de Motores: " << this->qtMotor << endl;
            cout << "Consumo: " << this->consumo() << " Km/l" << endl;
            cout << "Autonomia: " << this->Veiculo::autonomia(this->consumo()) << " Km" << endl;
        }

        float consumo() {
            return 1/((this->peso * 0.00002) + (this->qtMotor * 0.02));
        }
};
