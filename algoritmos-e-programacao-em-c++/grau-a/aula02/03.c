#include "stdio.h"
#include "../utils.h"

// Solicitar dois números inteiros "a" e "b" e imprimir na tela se o
// primeiro é perfeitamente divisível pelo segundo ("a"/"b"), sem gerar resto;
int main()
{
	int a, b;

    readInt("Informe o primeiro número", &a);
	readInt("Informe o segundo número", &b);

	printf("%i %s perfeitamente divisível por %i\n", a, a % b == 0 ? "é" : "não é", b);

	return 0;
}
