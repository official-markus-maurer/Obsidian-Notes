# Introduction to Sockets

## 🔌 What is a Socket?
A socket is an endpoint for communication between two machines. It is defined by an **IP Address** and a **Port Number**.

## 🏗️ Client-Server Model

1.  **Server**: Listens for incoming connections on a specific port.
2.  **Client**: Initiates a connection to the server's IP and port.

## 📦 Headers (Linux/Unix)

```c
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
```

> **Note**: Windows uses `<winsock2.h>` which requires different initialization (`WSAStartup`). This guide focuses on the standard POSIX (Linux/Mac) API.

## 🔢 Key Functions
-   `socket()`: Create a socket.
-   `bind()`: Bind socket to an IP/Port (Server).
-   `listen()`: Listen for connections (Server).
-   `accept()`: Accept a connection (Server).
-   `connect()`: Connect to a server (Client).
-   `send()` / `recv()`: Transmit data.

---
[[00-Index|Back to Network Programming Index]]
