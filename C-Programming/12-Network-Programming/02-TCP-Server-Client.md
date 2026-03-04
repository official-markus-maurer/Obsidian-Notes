# TCP Server & Client

TCP (Transmission Control Protocol) is connection-oriented. It guarantees that data arrives in order and without errors.

## 🖥️ TCP Server Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // 1. Create Socket
    // AF_INET = IPv4, SOCK_STREAM = TCP
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 2. Bind
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(8080); // Port 8080

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // 3. Listen
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // 4. Accept
    printf("Listening on port 8080...\n");
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // 5. Read/Write
    read(new_socket, buffer, 1024);
    printf("Client sent: %s\n", buffer);
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    
    close(new_socket);
    close(server_fd);
    return 0;
}
```

## 📱 TCP Client Example

```c
// ... includes ...

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    // 1. Create Socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    
    // Convert IP from string to binary
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // 2. Connect
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // 3. Send/Receive
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    read(sock, buffer, 1024);
    printf("Server sent: %s\n", buffer);
    
    close(sock);
    return 0;
}
```

---
[[00-Index|Back to Network Programming Index]]
