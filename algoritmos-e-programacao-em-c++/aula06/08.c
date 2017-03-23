#include "stdio.h"
#include "../utils.h"

int main()
{
	int tamanho = 10, vetor[tamanho];

	for (int i = 0; i < tamanho; i++) {
		int in;

		readInt("Entre com um número", &in);

		vetor[i] = in;
	}

	for (int i = 0; i < tamanho - 1; i++) {
		for (int x = 0; x < (tamanho - 1) - i; x++) {
			vetor[x] = vetor[x] + vetor[x + 1];
			vetor[x + 1] = vetor[x] - vetor[x + 1];
			vetor[x] = vetor[x] - vetor[x + 1];
		}
	}

	printArrayInt(tamanho, vetor);

	return 0;
}
