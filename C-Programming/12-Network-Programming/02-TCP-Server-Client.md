# TCP Server & Client

TCP (Transmission Control Protocol) is connection-oriented. It guarantees that data arrives in order and without errors.

## 🖥️ TCP Server Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // 1. Create Socket (IPv4, TCP, 0)
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 2. Set Options (Optional: Reuse Address/Port)
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // 3. Bind to IP/Port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on 0.0.0.0 (all interfaces)
    address.sin_port = htons(PORT);       // Host to Network Short

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // 4. Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    // 5. Accept a connection (Blocking call)
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted!\n");

    // 6. Read/Write Data
    ssize_t bytesRead = read(new_socket, buffer, 1024);
    if (bytesRead > 0) {
        printf("Client sent: %s\n", buffer);
    }
    
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    
    // 7. Close Sockets
    close(new_socket);
    close(server_fd);
    return 0;
}
```

## 📱 TCP Client Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    // 1. Create Socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IP from string to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // 2. Connect to Server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    // 3. Send Data
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    
    // 4. Read Response
    read(sock, buffer, 1024);
    printf("Server sent: %s\n", buffer);
    
    // 5. Close
    close(sock);
    return 0;
}
```

---
[[00-Index|Back to Network Programming Index]]
