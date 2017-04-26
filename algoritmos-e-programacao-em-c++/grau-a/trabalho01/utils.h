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

void separator() {
	printf("\n--------------------\n");
}

void space() {
	printf("\n");
}

void repeatChar(char input , int count ) {
    for (int i=0; i != count; i++ ) {
        printf("%c", input);
    }
}

void blockSection() {
	printf("Pressione <ENTER> para voltar ao menu ");
	getchar();
	getchar();
}

void clear() {
	system("@cls||clear");
}
