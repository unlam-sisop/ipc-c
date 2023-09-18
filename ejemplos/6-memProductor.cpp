#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

#define NombreMemoria "miMemoria"
// shm => SHared Memory = memoria compartida

int main() // PRODUCTOR
{
    int idMemoria = shm_open(NombreMemoria, O_CREAT | O_RDWR, 0600);
    ftruncate(idMemoria, sizeof(int));

    int *memoria = (int *)mmap(NULL,
                               sizeof(int),
                               PROT_READ | PROT_WRITE,
                               MAP_SHARED,
                               idMemoria,
                               0);

    close(idMemoria);

    *memoria = *memoria + 1;

    munmap(memoria, sizeof(int));
    return EXIT_SUCCESS;
}
