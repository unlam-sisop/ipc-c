// STL
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include "persona.hpp"

using namespace std;

bool comparadorPersonas(const Persona &a, const Persona &b)
{
    return a.edad < b.edad;
}

int main()
{
    vector<int> miVector = { 1, 5, 3, -6 };
    vector<Persona> personas;
    vector<string> cadenas;

    string miCadena = "hola esta es una cadena";
    miCadena.c_str();

    sort(personas.begin(), personas.end(), comparadorPersonas);
    
    miVector.push_back(2);
    miVector.push_back(8);

    cout << "Cantidad elementos miVector: " << miVector.size() << endl;

    for (int elemento : miVector)
    {
        cout << elemento << endl;
    }

    sort(miVector.begin(), miVector.end());

    for (int elemento : miVector)
    {
        cout << elemento << endl;
    }

    return EXIT_SUCCESS;
}
