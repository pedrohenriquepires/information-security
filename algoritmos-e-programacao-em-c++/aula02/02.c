#include "stdio.h"
#include "../utils.h"

// Solicitar um número inteiro "a"
// e imprimir na tela se ele é par ou ímpar;
int main()
{
	int a;

	readInt("Informe um número", &a);

	printf("O número informado foi: %s\n", a % 2 == 0 ? "Par" : "Impar");

	return 0;
}
