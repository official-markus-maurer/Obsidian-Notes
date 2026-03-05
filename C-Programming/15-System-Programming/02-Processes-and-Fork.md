# Processes and Forking

In Unix-like systems, new processes are created by cloning an existing one using `fork()`.

## 🍴 `fork()`

`fork()` creates a duplicate of the current process.
-   **Parent Process**: `fork()` returns the Child's PID.
-   **Child Process**: `fork()` returns `0`.
-   **Error**: Returns `-1`.

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("I am the child! My PID is %d\n", getpid());
        sleep(1); // Simulate work
    } else if (pid > 0) {
        // Parent process
        printf("I am the parent! My child is %d\n", pid);
        wait(NULL); // Wait for child to finish
    } else {
        perror("fork failed");
    }
    return 0;
}
```

## 🧠 Memory Layout: Copy-On-Write (COW)

When `fork()` is called, the kernel does **not** copy all memory (Heap, Stack, Data) immediately. That would be too slow.

Instead, it marks all memory pages as **Read-Only**.
1.  Both Parent and Child share the same physical RAM.
2.  If either tries to **Write** to a page, a CPU exception (Page Fault) occurs.
3.  The kernel catches this fault, allocates a **new** physical page, copies the data, and maps it to that process.
4.  Execution resumes.

This makes `fork()` extremely fast if the child immediately calls `exec()`.

## 🚀 `exec()` Family

Usually, after forking, the child process wants to run a *different* program. The `exec` functions replace the current process image with a new program.

```c
if (pid == 0) {
    // Replace child process with "ls -l"
    // execlp searches PATH for "ls"
    execlp("ls", "ls", "-l", NULL);
    
    // If exec returns, it MUST have failed
    perror("exec failed");
    exit(1);
}
```

## 🧟 Zombie Processes
A zombie process is a process that has completed execution but still has an entry in the process table. This happens if the parent does not call `wait()`.

### Prevention
The parent **must** call `wait()` or `waitpid()` to read the child's exit status and remove the zombie.

## ⏳ Waiting

### `wait()`
Waits for **any** child to terminate.
```c
int status;
wait(&status);
if (WIFEXITED(status)) {
    printf("Child exited with code %d\n", WEXITSTATUS(status));
}
```

### `waitpid()`
Waits for a **specific** child. Can be non-blocking with `WNOHANG`.

```c
// Wait for specific PID, don't block if it's still running
pid_t res = waitpid(child_pid, &status, WNOHANG);

if (res == 0) {
    printf("Child is still running...\n");
} else if (res > 0) {
    printf("Child finished.\n");
}
```

---
[[00-Index|Back to System Programming Index]]
