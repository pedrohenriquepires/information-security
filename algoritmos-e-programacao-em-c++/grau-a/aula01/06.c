#include "../utils.h"
#include "math.h"

int main()
{
    double altura;
	double largura;

    readDouble("Altura", &altura);
	readDouble("Largura", &largura);

    printf("\n-----------------------\n");
    printf("Perímetro: %.2f\n", 2 * (altura + largura));
    printf("Área: %.2f\n", altura * largura);

	return 0;
}
