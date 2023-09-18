#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <thread>

using namespace std;

void hilo(int socketId)
{
    time_t ticks = time(NULL);
    char sendBuff[2000];
    snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));

    write(socketId, sendBuff, strlen(sendBuff));
    close(socketId);
}

int main()
{
    struct sockaddr_in serverConfig;
    memset(&serverConfig, '0', sizeof(serverConfig));

    serverConfig.sin_family = AF_INET; // 127.0.0.1
    serverConfig.sin_addr.s_addr = htonl(INADDR_ANY);
    serverConfig.sin_port = htons(5000); // Mayor 1023

    int socketEscucha = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketEscucha, (struct sockaddr *)&serverConfig, sizeof(serverConfig));

    listen(socketEscucha, 10);

    while (true)
    {
        int socketComunicacion = accept(socketEscucha, (struct sockaddr *)NULL, NULL);
        
        thread th(hilo, socketComunicacion);
        th.detach();        
    }

    return EXIT_SUCCESS;
}
