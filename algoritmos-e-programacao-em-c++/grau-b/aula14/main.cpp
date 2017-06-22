#include <iostream>
#include "veiculo.h"
#include "terrestre.h"
#include "aereo.h"
#include "aquatico.h"

int main(int argc, char* argv[])
{
	Aquatico *veiculo = new Aquatico(12, 12, 12, "teste", 12, 12);

	veiculo->info();
}
