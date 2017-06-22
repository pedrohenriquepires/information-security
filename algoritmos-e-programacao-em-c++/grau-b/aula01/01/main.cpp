#include <iostream>
#include <string>
#include "Paralelepipedo.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Paralelepipedo *paralelepipedo = new Paralelepipedo(10, 10, 10);
    cout <<
        "Base: " << paralelepipedo->getBase() << endl <<
        "Altura: " << paralelepipedo->getAltura() << endl <<
        "Profundidade: " << paralelepipedo->getProfundidade() << endl <<
        "Volume: " << paralelepipedo->getVolume() << endl;

    delete paralelepipedo;
}
