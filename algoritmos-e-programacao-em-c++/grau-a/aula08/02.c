#include "stdio.h"
#include "string.h"
#include "../utils.h"

int getStringLength(char str[]);

int main()
{
	char str[255];

	readString("Entre com a palavra ou frase", str);

	printf("Tamanho: %lu\n", getStringLength(str));

	return 0;
}

int getStringLength(char str[]) {
	return strlen(str);
}
