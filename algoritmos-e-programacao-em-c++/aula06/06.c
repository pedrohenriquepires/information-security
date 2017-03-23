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

	for (int i = (tamanho - 1); i >= 0; i--) {
		printf("%d\n", vetor[i]);
	}

	return 0;
}
