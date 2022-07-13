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

        if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)))
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
    }
    else
    {
    }
}