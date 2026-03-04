# UDP Sockets

UDP (User Datagram Protocol) is connectionless. It sends packets ("datagrams") without guaranteeing delivery or order. It is faster than TCP and used for streaming, gaming, and DNS.

## 🚀 Key Differences from TCP
1.  **No Connection**: No `connect()` or `accept()`. Just send and receive.
2.  **Datagrams**: Each packet is independent.
3.  **Functions**: Use `sendto()` and `recvfrom()` instead of `send()`/`recv()`.

## 📡 UDP Server Example

```c
// ... includes ...

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;

    // Create Socket (SOCK_DGRAM = UDP)
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);

    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));

    int len = sizeof(cliaddr);
    
    // Receive
    int n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *) &cliaddr, &len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);

    // Send
    sendto(sockfd, "Hello from server", 17, MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
    
    return 0;
}
```

---
[[00-Index|Back to Network Programming Index]]
