#include "stdio.h"
#include "../utils.h"

// Solicitar dois números inteiros "a" e "b" e imprimir na tela se o
// resultado da subtração entre eles ("a"-"b") resulta em número positivo ou negativo;
int main()
{
	int a, b;

    readInt("Informe o primeiro número", &a);
	readInt("Informe o segundo número", &b);

	printf("%i - %i resulta em um número %s (%i)\n", a, b, (a - b) > 0 ? "positivo" : "negativo", a - b);

	return 0;
}
