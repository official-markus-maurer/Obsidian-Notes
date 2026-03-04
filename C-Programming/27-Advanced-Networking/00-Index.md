# Advanced Network Programming

Basic socket programming is blocking (one thread per client). To scale to thousands of connections (the C10k problem), we need **Non-blocking I/O** and **I/O Multiplexing**.

## 📋 Topics

1.  **[[01-Blocking-vs-NonBlocking|Blocking vs Non-Blocking]]**
    -   Understanding blocking calls
    -   Setting sockets to non-blocking mode

2.  **[[02-IO-Multiplexing|I/O Multiplexing]]**
    -   `select()`: The portable old way
    -   `poll()`: The slightly better way
    -   `epoll()`: The Linux high-performance way

---
**Next Section**: [[../28-Modern-Tooling/00-Index|Modern Tooling]]
