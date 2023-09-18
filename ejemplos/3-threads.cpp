#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
#include <mutex>

using namespace std;

mutex mtxPantalla;
int varGlobal = 2;

void trabajoHilo(int idHilo)
{
    int miVariable = 0;
    for (int i = 0; i < 5; i++)
    {
        // P(mtxPantalla)
        mtxPantalla.lock();
        cout << "Hilo " << idHilo << " dice " << i << endl;
        sleep(3);
        // V(mtxPantalla)
        mtxPantalla.unlock();
    }
}

int main()
{
    cout << "Ejecutando threads en C++" << endl;

    thread hilo1(trabajoHilo, 1);
    thread hilo2(trabajoHilo, 2);

    for (int i = 0; i < 5; i++)
    {
        // P(mtxPantalla)
        mtxPantalla.lock();
        cout << "Hilo main dice " << i << endl;
        sleep(3);
        // V(mtxPantalla)
        mtxPantalla.unlock();
    }

    hilo1.join(); // equivalente de wait para hilos
    hilo2.join();

    cout << "Hilos esperados" << endl;
    cout << "Fin" << endl;

    return EXIT_SUCCESS;
}
