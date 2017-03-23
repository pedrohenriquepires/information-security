#include "stdio.h"
#include "../utils.h"

int main()
{
	int tamanho = 10;
	double B[tamanho];

	for (int i = 0; i < tamanho; i++) {
		double id = i;
		B[i] = (id / 2) - 1.5;
	}

	printArrayDouble(tamanho, B);

	return 0;
}
