#include "stdio.h"
#include "../utils.h"

int main()
{
	int valorFinal;
    int fatorial;

	readInt("Informe o valor final", &valorFinal);
    fatorial = valorFinal;

	for (int i = valorFinal - 1; i > 0; i--) {
        fatorial *= i;
	}

    printf("%d\n", fatorial);

	return 0;
}
