#include "../utils.h"
#include "math.h"

int main()
{
	double base;
    double expoente;

    readDouble("Base", &base);
    readDouble("Expoente", &expoente);

    printf("\n-----------------------\n");
    printf("Potência: %.2f\n", pow(base, expoente));

	return 0;
}
