#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
    char *pattern;
    char *response;
} IntentRule;

IntentRule intents[] = {
    {"Hello!", "Hi there! How can I assist you today?"},
    {"Tell me about your latest smartphone.", "Our latest smartphone is the XYZ model, featuring a high-resolution camera and a long-lasting battery."},
    {"What are your business hours?", "Our business hours are Monday to Friday, 9:00 AM to 5:00 PM."},
    {"Your service is great!", "Thank you for your kind words! We're here to help. Is there anything specific you'd like assistance with?"},
    {NULL, "I'm sorry, I didn't understand. Could you please provide more details or ask a specific question?"}
};

char* process_input(char *user_input) {
    for (int i = 0; intents[i].pattern != NULL; ++i) {
        if (strstr(user_input, intents[i].pattern) != NULL) {
            return intents[i].response;
        }
    }
    return intents[4].response; // Default response for unrecognized input
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);

        char *response = process_input(buffer);
        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == -1) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);

        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_client(client_socket);
    }

    close(server_socket);

    return 0;
}

