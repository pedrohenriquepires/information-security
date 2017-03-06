#include "stdio.h"

void readInt(const char* label, int * arg) {
	printf("%s: ", label);
	scanf("%i", arg);
}

void readDouble(const char* label, double * arg) {
	printf("%s: ", label);
	scanf("%lf", arg);
}
