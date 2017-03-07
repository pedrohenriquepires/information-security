#include "stdio.h"
#include "stdbool.h"

void readInt(const char* label, int * arg) {
	printf("%s: ", label);
	scanf("%i", arg);
}

void readDouble(const char* label, double * arg) {
	printf("%s: ", label);
	scanf("%lf", arg);
}

void readChar(const char* label, char * arg) {
	printf("%s: ", label);
	scanf("\n%c", arg);
}

void readTime(const char* label, int * horas, int * minutos, int * segundos) {
	printf("%s: ", label);
	scanf("%d:%d:%d", horas, minutos, segundos);
}
