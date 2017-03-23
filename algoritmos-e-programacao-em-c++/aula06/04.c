#include "stdio.h"
#include "../utils.h"

int main()
{
	int tamanho = 10, vetor[tamanho];

	for (int i = 0; i < tamanho / 2; i++) {
		vetor[i] = i;
	}

	printArrayInt(tamanho, vetor);

	return 0;
}
