#include "stdio.h"
#include "string.h"
#include "../utils.h"

int main()
{
	char palavra[255];

	readString("Entre com a palavra ou frase", palavra);

	printf("Tamanho: %lu\n", strlen(palavra));

	return 0;
}
