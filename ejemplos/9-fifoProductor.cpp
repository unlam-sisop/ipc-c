#include <iostream>
#include <fstream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        cout << "Falta parámetro" << endl;
        return EXIT_FAILURE;
    }

    cout << "Escribo \"" << argv[1] << "\" en el pipe" << endl;

    mkfifo("mififo", 0666);

    ofstream fifo("mififo");
    fifo << string(argv[1]) << ends;
    fifo.close();

    return EXIT_SUCCESS;
}
