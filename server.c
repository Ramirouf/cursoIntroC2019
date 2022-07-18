#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    if (argc > 1)
    {
        int server_socket, client_socket, client_message_size, port;
        port = atoi(argv[1]);

        struct sockaddr_in server;
        struct sockaddr_in client;

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = INADDR_ANY;
        bzero(&(server.sin_zero), 8);

        if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        {
            perror("Unable to create socket");
            exit(1);
        }

        if (bind(server_socket, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
        {
            perror("Unable to open port  on the server\n");
            exit(1);
        }
        if (listen(server_socket, 5) == -1)
        {
            perror("Unable to listen on port\n");
            exit(1);
        }

        int length = sizeof(struct sockaddr_in);
        printf("Waiting for a connection...\n");
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client, &length)) == -1)
        {
            perror("Unable to accept connection\n");
            exit(1);
        }

        char str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client.sin_addr, str, INET_ADDRSTRLEN);

        printf("Client connected from %s:%d\n", str, client.sin_port);
        send(client_socket, "Hello client", strlen("Hello client"), 0);
        printf("Message sent to client\n");
        shutdown(client_socket, 2);
        shutdown(server_socket, 2);
    }
    else
    {
        printf("Please, set a port");
    }
}