#include "stdio.h"
#include "../utils.h"

int soma(double a, double b);
int subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);

int main()
{
	int tamanho = 5, vetorA[tamanho], vetorB[tamanho];

	printf("Informe os valores do primeiro vetor\n");

	separator();

	for (int i = 0; i < tamanho; i++) {
		int in;

		readInt("Entre com um número", &in);

		vetorA[i] = in;
	}

	separator();

	printf("Informe os valores do primeiro vetor\n");

	separator();

	for (int i = 0; i < tamanho; i++) {
		int in;

		readInt("Entre com um número", &in);

		vetorB[i] = in;
	}

	for (int i = 0; i < tamanho; i++) {
		separator();
		printf("%d + %d = %d \n", vetorA[i], vetorB[i], soma(vetorA[i], vetorB[i]));
		printf("%d - %d = %d \n", vetorA[i], vetorB[i], subtracao(vetorA[i], vetorB[i]));
		printf("%d * %d = %.2f \n", vetorA[i], vetorB[i], multiplicacao(vetorA[i], vetorB[i]));
		printf("%d / %d = %.2f \n", vetorA[i], vetorB[i], divisao(vetorA[i], vetorB[i]));
	}

	return 0;
}

int soma(double a, double b) {
	return a + b;
}

int subtracao(double a, double b) {
	return a - b;
}

double multiplicacao(double a, double b) {
	return a * b;
}

double divisao(double a, double b) {
	return a / b;
}
