#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> // read(), write(), close()
#include <arpa/inet.h>

#define MAX 80 
#define PORT 8080 
#define SOCKETADDRESS struct sockaddr

// Driver function 
int main() 
{ 
	int my_socket, connfd, len; 
	struct sockaddr_in server_address, client;

	// SOCKET 
	my_socket = socket(AF_INET, SOCK_STREAM, 0); 
	if (my_socket < 0) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
    else
        printf("Socket successfully created..\n");
	printf("Socket successfully created..\n");

    // Asignación de IP, PORT 
    
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = inet_addr("3.88.42.145");
    server_address.sin_port = htons(PORT);

        // BIND
    // Binding newly created socket to given IP and verification 
    if ((bind(my_socket, (SOCKETADDRESS*)&server_address, sizeof(server_address))) != 0) { 
        perror("socket bind failed...\n"); // Manejo de errores
        exit(EXIT_FAILURE); 
    } 
    else
        printf("Socket successfully binded..\n"); 
    
    // LISTEN
    int backlog = 5; // máxima cantidad de conexiones pendientes
    int status = listen(my_socket, backlog);
    if(status == -1){
        printf("Listen failed...\n");
        exit(0);
    }
    else{
        printf("Server complete\n");
    }

    // ACCEPT
    
    len = sizeof(client);
    // Accept the data packet from client and verification 
    connfd = accept(my_socket, (SOCKETADDRESS*)&client, &len); 
    if (connfd < 0) { 
        perror("server accept failed...\n"); // Manejo de errores
        exit(EXIT_FAILURE); 
    } 
    else
        printf("server accept the client...\n"); 
    // READ
    // WRITE
    // READ
    // CLOSE
    return 0;
}