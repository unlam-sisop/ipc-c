#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

using namespace std;

int main()
{
    sem_t *semaforo = sem_open("miSemaforoContador",
                               O_CREAT,
                               0600, // r+w user
                               5); // valor incial

    sem_post(semaforo); // V()

    cout << "Liberé un semáforo +1" << endl;

    sem_close(semaforo);
    sem_unlink("miSemaforoContador"); // Borra el semáforo del sistema.

    return EXIT_SUCCESS;
}
