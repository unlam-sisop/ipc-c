#include <iostream>
#include <fstream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main()
{
    mkfifo("mififo", 0666);
    
    string buffer;
    ifstream fifo("mififo");
    while (!fifo.eof())
    {
        getline(fifo, buffer);
    }
    fifo.clear();
    fifo.close();

    cout << "Del fifo leí \"" << buffer << "\"" << endl;

    return EXIT_SUCCESS;
}
