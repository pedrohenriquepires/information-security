#include "../utils.h"
#include "math.h"

int main()
{
    double altura;
	double base;

    readDouble("Base", &base);
    readDouble("Altura", &altura);

    printf("\n-----------------------\n");
    printf("Área: %.2f\n", (altura * base) / 2);

	return 0;
}
