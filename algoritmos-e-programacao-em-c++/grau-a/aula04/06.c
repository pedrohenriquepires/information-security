#include "stdio.h"
#include "../utils.h"

int main()
{
	double inicio, somador, repeticoes;

	readDouble("Informe o valor de inicio", &inicio);
	readDouble("Informe o valor de soma", &somador);
	readDouble("Informe o número de repetições", &repeticoes);


	for (int i = 0; i < repeticoes; i++) {
		printf("%.1f\n", inicio);
		inicio += somador;
	}

	return 0;
}
