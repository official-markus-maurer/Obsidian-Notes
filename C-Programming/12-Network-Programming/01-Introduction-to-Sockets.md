# Introduction to Sockets

## 🔌 What is a Socket?
A socket is an endpoint for communication between two machines. It acts like a file descriptor (integer), allowing you to read/write data across the network just like you would with a file.

## 🏗️ Client-Server Model

1.  **Server**: 
    -   Creates a socket.
    -   Binds to a specific IP and Port.
    -   Listens for incoming connections.
    -   Accepts a connection (creates a new socket for that client).
2.  **Client**: 
    -   Creates a socket.
    -   Connects to the server's IP and Port.

## 📦 Headers (Linux/Unix)

```c
#include <sys/socket.h> // Core socket functions
#include <netinet/in.h> // AF_INET, struct sockaddr_in
#include <arpa/inet.h>  // inet_pton, inet_ntop
#include <unistd.h>     // close, read, write
#include <netdb.h>      // getaddrinfo (DNS)
```

> **Note**: Windows uses `<winsock2.h>` which requires `WSAStartup()` and `WSACleanup()`.

## 🔢 Key Structures

### `struct sockaddr_in` (IPv4)
Used to specify the address and port.

```c
struct sockaddr_in {
    sa_family_t    sin_family; // AF_INET (IPv4)
    in_port_t      sin_port;   // Port number (Network Byte Order)
    struct in_addr sin_addr;   // IP Address
};

struct in_addr {
    uint32_t       s_addr;     // 32-bit IP address
};
```

## 🔄 Byte Ordering (Endianness)
Network protocols use **Big Endian** (Network Byte Order). Most CPUs (x86, ARM) use **Little Endian**. You must convert values!

-   **`htons()`**: Host to Network Short (for Port).
-   **`htonl()`**: Host to Network Long (for IP).
-   **`ntohs()`**: Network to Host Short.
-   **`ntohl()`**: Network to Host Long.

```c
server_addr.sin_port = htons(8080); // Correct
// server_addr.sin_port = 8080;     // WRONG!
```

## 🛠️ Key Functions
1.  **`socket(domain, type, protocol)`**: Create endpoint.
    -   `AF_INET`: IPv4.
    -   `SOCK_STREAM`: TCP.
    -   `SOCK_DGRAM`: UDP.
2.  **`bind(sockfd, addr, addrlen)`**: Assign IP/Port (Server).
3.  **`listen(sockfd, backlog)`**: Mark as passive (Server).
4.  **`accept(sockfd, addr, addrlen)`**: Block until connection (Server).
5.  **`connect(sockfd, addr, addrlen)`**: Initiate connection (Client).
6.  **`inet_pton(af, src, dst)`**: Convert "127.0.0.1" string to binary IP.

---
[[00-Index|Back to Network Programming Index]]
