#include "stdio.h"
#include "../utils.h"

int main()
{
	int i, tamanho = 10;
	int meuArray[tamanho];

	for(i = 0; i < tamanho; i++)
		meuArray[i] = i;

	for(i = 0; i < tamanho; i++) {
		if(meuArray[i] % 2 == 0)
			printf("%d\n", meuArray[i]);
	}

	return 0;
}
