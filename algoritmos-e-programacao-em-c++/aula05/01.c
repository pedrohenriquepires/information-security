#include "stdio.h"
#include "../utils.h"
#include "stdbool.h"

bool operadorValido(char operador);
double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);

int main()
{
	double num1, num2;
	char operador, resultado;

	readDouble("Entre com o primeiro número", &num1);

	while(!operadorValido(operador)) {
		readChar("Entre com o operador (+ * - /)", &operador);
	}

	readDouble("Entre com o segundo número", &num2);

	switch (operador) {
		case '+':
			resultado = soma(num1, num2);
			break;
		case '-':
			resultado = subtracao(num1, num2);
			break;
		case '*':
			resultado = multiplicacao(num1, num2);
			break;
		case '/':
			resultado = divisao(num1, num2);
			break;
	}

	printf("Resultado: %d\n", resultado);

	return 0;
}

double soma(double a, double b) {
	return a + b;
}

double subtracao(double a, double b) {
	return a - b;
}

double multiplicacao(double a, double b) {
	return a * b;
}

double divisao(double a, double b) {
	return a / b;
}

bool operadorValido(char operador) {
	return  operador == '+' ||
			operador == '-' ||
			operador == '*' ||
			operador == '/';
}
