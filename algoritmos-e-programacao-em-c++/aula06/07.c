#include "stdio.h"
#include "../utils.h"

int main()
{
	int tamanho = 10, vetor[tamanho], vetorInverso[tamanho];

	for (int i = 0; i < tamanho; i++) {
		int in;

		readInt("Entre com um número", &in);

		vetor[i] = in;
	}

	for (int i = tamanho - 1; i >= 0; i--) {
		int indice = (tamanho - 1) - i;

		vetorInverso[indice] = vetor[i];
	}

	for (int i = 0; i < tamanho; i++) {
		printf("INDICE %d (%d - %d)\n", i, vetor[i], vetorInverso[i]);
	}

	return 0;
}
