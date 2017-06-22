class Paralelepipedo {
	double base, altura, profundidade;

	public:
		Paralelepipedo(double base, double altura, double profundidade) {
			this->base = base;
			this->altura = altura;
			this->profundidade = profundidade;
		}

		double getBase() {
			return this->base;
		}
		void setBase(double base) {
			this->base = base;
		}

		double getAltura() {
			return this->altura;
		}
		void setAltura(double altura) {
			this->altura = altura;
		}

		double getProfundidade() {
			return this->profundidade;
		}
		void setProfundidade(double profundidade) {
			this->profundidade = profundidade;
		}

		double getVolume() {
			return this->base * this->altura * this->profundidade;
		}
};
