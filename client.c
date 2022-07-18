#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    if (argc > 2)
    {
        const char *ip;
        int client_socket, numBytes, port;
        char buffer[100];
        port = atoi(argv[2]);
        ip = argv[1];

        struct sockaddr_in server;

        if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0)
        {
            printf("\nInvalid address/ Address not supported \n");
            return -1;
        }
        printf("Opening socket on %s:%d\n", ip, port);
        if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        {
            printf("\n Socket creation error \n");
            return -2;
        }
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        bzero(&(server.sin_zero), 8);

        printf("Connecting to %s:%d\n", ip, port);

        if (connect(client_socket, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
        {
            printf("\nConnection Failed \n");
            return -3;
        }

        printf("Receiving message from server\n");

        if ((numBytes = recv(client_socket, buffer, 100, 0)) == -1)
        {
            printf("\nError receiving message\n");
            return -4;
        }
        buffer[numBytes] = '\0';
        printf("Received message: %s\n", buffer);
        printf("Closing socket\n");
        shutdown(client_socket, 2);
    }
    else
    {
        printf("Please, set IP and a port");
        exit(1);
    }
}