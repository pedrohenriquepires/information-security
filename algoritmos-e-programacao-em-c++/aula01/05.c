#include "../utils.h"
#include "math.h"

int main()
{
	double raio;

	readDouble("Raio", &raio);

	printf("\n-----------------------\n");
	printf("Diâmetro: %.2f\n", raio * 2);
	printf("Circunferência: %.2f\n", (raio * 2) * M_PI);
	printf("Area: %.2f\n", M_PI * pow(raio, 2));

	return 0;
}
