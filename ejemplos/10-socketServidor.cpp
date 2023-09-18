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

using namespace std;

int main()
{
    struct sockaddr_in serverConfig;
    memset(&serverConfig, '0', sizeof(serverConfig));

    serverConfig.sin_family = AF_INET; // IPV4: 127.0.0.1
    serverConfig.sin_addr.s_addr = htonl(INADDR_ANY);
    serverConfig.sin_port = htons(5000); // Es recomendable que el puerto sea mayor a 1023 para aplicaciones de usuario.

    int socketEscucha = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketEscucha, (struct sockaddr *)&serverConfig, sizeof(serverConfig));

    listen(socketEscucha, 10);

    while (true)
    {
        int socketComunicacion = accept(socketEscucha, (struct sockaddr *)NULL, NULL);
        
        time_t ticks = time(NULL);
        char sendBuff[2000];
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));

        write(socketComunicacion, sendBuff, strlen(sendBuff));
        close(socketComunicacion);
    }

    return EXIT_SUCCESS;
}
