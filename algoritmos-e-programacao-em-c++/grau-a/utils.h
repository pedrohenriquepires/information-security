#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

void readInt(const char* label, int * arg) {
	printf("%s ", label);
	scanf("%i", arg);
}

void readDouble(const char* label, double * arg) {
	printf("%s ", label);
	scanf("%lf", arg);
}

void readChar(const char* label, char * arg) {
	printf("%s ", label);
	scanf("\n%c", arg);
}

void readString(const char* label, char arg[]) {
	printf("%s ", label);
	scanf("\n%[^\n]s", arg);
}

void readTime(const char* label, int * horas, int * minutos, int * segundos) {
	printf("%s ", label);
	scanf("%d:%d:%d", horas, minutos, segundos);
}

void printArrayInt(const int size, int * array) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", array[i]);
	}
}

void printArrayDouble(const int size, double * array) {
	for (int i = 0; i < size; i++) {
		printf("%.2lf\n", array[i]);
	}
}

void separator() {
	printf("\n--------------------\n\n");
}

void repeatChar(char input , int count ) {
    for (int i=0; i != count; i++ ) {
        printf("%c", input);
    }
}

void clear() {
	system("@cls||clear");
}
