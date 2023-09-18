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

    sem_wait(semaforo); // P()

    int valSem = 0;
    sem_getvalue(semaforo, &valSem);
    cout << "El semáforo tiene valor: " << valSem << endl;

    sem_close(semaforo);
    return EXIT_SUCCESS;
}
