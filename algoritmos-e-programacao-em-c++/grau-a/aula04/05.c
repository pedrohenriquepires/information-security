#include "stdio.h"
#include "../utils.h"

int main()
{
	int valorFinal;
	double seq = 1.5;

	readInt("Informe o valor final", &valorFinal);


	for (int i = 0; i < valorFinal; i++) {
		seq += 0.5;
		printf("%.1f\n", seq);
	}

	return 0;
}
