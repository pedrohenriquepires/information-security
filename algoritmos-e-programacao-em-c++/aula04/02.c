#include "stdio.h"
#include "../utils.h"

int main()
{
	int valorFinal;

	readInt("Informe o valor final", &valorFinal);

	for (int i = 0; i <= valorFinal; i += 2) {
		printf("%d\n", i);
	}

	return 0;
}
