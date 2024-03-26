#include <stdio.h>
#include <string.h>

#define MAX_METHOD_LENGTH 10  // Longitud máxima del método HTTP
#define MAX_REQUEST_SIZE 2048

// Función para analizar la solicitud HTTP y extraer el método HTTP
void parse_http_request(char* request, char* method) {
    // Buscar el primer espacio en blanco para encontrar el final del método HTTP
    char* space_ptr = strchr(request, ' ');
    if (space_ptr == NULL) {
        *method = '\0'; // Error: no se encontró el espacio en blanco
        return;
    }

    // Calcular la longitud del método HTTP
    int method_length = space_ptr - request;
    if (method_length > MAX_METHOD_LENGTH - 1) {
        method_length = MAX_METHOD_LENGTH - 1;
    }

    // Copiar el método HTTP al buffer
    strncpy(method, request, method_length);
    method[method_length] = '\0'; // Agregar el carácter nulo al final del método
}

int main() {
    // Ejemplo de solicitud HTTP
    char http_request[MAX_REQUEST_SIZE] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\n\r\n";

    // Buffer para almacenar el método HTTP
    char method[MAX_METHOD_LENGTH];

    // Analizar la solicitud HTTP y extraer el método HTTP
    parse_http_request(http_request, method);

    // Imprimir el método HTTP
    if (*method != '\0') {
        printf("Método HTTP: %s\n", method);
    } else {
        printf("Error: No se pudo analizar la solicitud HTTP.\n");
    }

    return 0;
}
