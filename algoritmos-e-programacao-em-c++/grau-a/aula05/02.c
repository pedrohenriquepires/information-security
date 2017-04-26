#include "stdio.h"
#include "../utils.h"

int ehPositivo(int numero);

int main()
{
	int numero;

	readInt("Informe o número", &numero);

	printf("Resultado: %d\n", ehPositivo(numero));

	return 0;
}

int ehPositivo(int numero) {
	return numero >= 0 ? 1 : 0;
}
