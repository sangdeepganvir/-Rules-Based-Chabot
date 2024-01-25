#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char message[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        printf("Enter message: ");
        fgets(message, BUFFER_SIZE, stdin);

        send(client_socket, message, strlen(message), 0);

        bytes_received = recv(client_socket, message, sizeof(message), 0);
        if (bytes_received > 0) {
            message[bytes_received] = '\0';
            printf("Received: %s", message);
        }
    }

    close(client_socket);

    return 0;
}
