# Sockets

A socket is an endpoint for sending or receiving data across a computer network.

## Types
-   **Stream Sockets (`SOCK_STREAM`)**: Uses TCP. Reliable, two-way connection.
-   **Datagram Sockets (`SOCK_DGRAM`)**: Uses UDP. Unreliable, message-based.

## Lifecycle (TCP Server)
1.  **`socket()`**: Create the socket.
2.  **`bind()`**: Attach to an IP/Port.
3.  **`listen()`**: Wait for connections.
4.  **`accept()`**: Accept a client connection (returns a new socket).
5.  **`recv()` / `send()`**: Communicate.
6.  **`close()`**: Terminate.

## Lifecycle (TCP Client)
1.  **`socket()`**
2.  **`connect()`**: Connect to server IP/Port.
3.  **`send()` / `recv()`**
4.  **`close()`**

---
[[00-Index|Back to Networking Index]]
