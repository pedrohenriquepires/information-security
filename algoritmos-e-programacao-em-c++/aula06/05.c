#include "stdio.h"
#include "stdbool.h"
#include "../utils.h"

bool verificaMenor(menorAtual, x) {
	return x < menorAtual;
}

bool verificaMaior(maiorAtual, x) {
	return x > maiorAtual;
}

int main()
{
	int menor, indiceMenor,
		maior, indiceMaior,
		tamanho = 10, vetor[tamanho];

	for (int i = 0; i < tamanho; i++) {
		int in;

		readInt("Entre com um número", &in);

		if(verificaMenor(menor, in)) {
			menor = in;
			indiceMenor = i;
		}

		if(verificaMaior(maior, in)) {
			maior = in;
			indiceMaior = i;
		}
	}

	printf("Menor valor - Indice: %d | Valor: %d\n", indiceMenor, menor);
	printf("Maior valor - Indice: %d | Valor: %d\n", indiceMaior, maior);
	printf("Diferença entre maior e menor: %d\n", maior - menor);

	return 0;
}
