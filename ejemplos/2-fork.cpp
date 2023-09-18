#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

int main()
{
    cout << "Ejemplo de fork()" << endl;

    int a = 0;
    a++;

    cout << "antes del fork " << a << endl;

    pid_t pid = fork();

    cout << "después del fork " << a << endl;

    if (pid == 0)
    {
        cout << "Soy el proceso hijo " << getpid() << endl;
        a = 100;
        cout << "Hijo, a = " << a << endl;
    }
    else if (pid > 0)
    {
        cout << "Soy el proceso padre y mi hijo es " << pid << endl;
        a = 50;
        cout << "Padre, a = " << a << endl;
    }
    else
    {
        cout << "Hubo error" << endl;
    }

    return EXIT_SUCCESS;
}
