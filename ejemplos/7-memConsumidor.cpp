#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

#define NombreMemoria "miMemoria"
// shm => SHared Memory = memoria compartida

int main() // CONSUMIDOR
{
    // Al crear la memoria compartida, se crea un archivo que la representa.
    // Este archivo se encuentra en /dev/shm. Para este ejemplo, el archivo
    // se llamará "miMemoria".
    int idMemoria = shm_open(NombreMemoria, O_CREAT | O_RDWR, 0600);
    int *memoria = (int *)mmap(NULL,
                               sizeof(int),
                               PROT_READ | PROT_WRITE,
                               MAP_SHARED,
                               idMemoria,
                               0);
    close(idMemoria);

    cout << "Valor de la memoria: " << *memoria << endl;

    munmap(memoria, sizeof(int));

    // Al igual que los semáforos, la memoria se tiene que eliminar del sistema
    // una vez que se terminó de utilizar. Para ello se usa la función:
    // shm_unlink(NombreMemoria);

    return EXIT_SUCCESS;
}