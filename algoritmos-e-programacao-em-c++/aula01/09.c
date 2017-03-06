#include "../utils.h"
#include "math.h"

int main()
{
	double cateto1;
    double cateto2;
    double hipotenusa;

    readDouble("Primeiro Cateto", &cateto1);
    readDouble("Segundo Cateto", &cateto2);

    hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));

    printf("\n-----------------------\n");
    printf("Hipotenusa: %.2f\n", hipotenusa);
    printf("Área: %.2f\n", (cateto1 * cateto2) / 2);
	printf("Perímetro: %.2f\n", cateto1 + cateto2 + hipotenusa);
    printf("Seno α: %.2f\n", cateto1 / hipotenusa);
	printf("Seno β: %.2f\n", cateto2 / hipotenusa);
	printf("Cosseno α: %.2f\n", cateto2 / hipotenusa);
	printf("Cosseno β: %.2f\n", cateto1 / hipotenusa);
	printf("Tangente α: %.2f\n", cateto1 / cateto2);
	printf("Tangente β: %.2f\n", cateto2 / cateto1);

	return 0;
}
