#include "stdio.h"
#include "../utils.h"

int main()
{
	int tamanho = 6, vetor[tamanho];

	for (int i = 0; i < tamanho; i++) {
		vetor[i] = (i + 1) * 2;
	}

	printArrayInt(tamanho, vetor);

	return 0;
}
