#include "stdio.h"
#include "stdbool.h"
#include "../utils.h"

int main()
{
	int tamanho = 10, vetor[tamanho], procurar;
	bool encontrou = false;

	for (int i = 0; i < tamanho; i++) {
		int in;

		readInt("Entre com um número", &in);

		vetor[i] = in;
	}

	separator();

	printArrayInt(tamanho, vetor);

	separator();

	readInt("Entre com um número para procurar no vetor", &procurar);

	separator();

	for (int i = 0; i < tamanho; i++) {
		if(vetor[i] == procurar) {
			encontrou = true;
			printf("Encontrado %d na posição %d\n", procurar, i);
		}
	}

	if(!encontrou) {
		printf("Não foi encontrado nenhum número %d\n", procurar);
	}

	return 0;
}
