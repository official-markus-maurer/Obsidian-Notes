# Position Independent Code (PIC)

In modern operating systems, programs are often loaded at random memory addresses (**ASLR**). Shared libraries (`.so`, `.dll`) must be able to run from **any** address. This requires **Position Independent Code (PIC)**.

## 📍 RIP-Relative Addressing

On x86-64, accessing global data uses **RIP-Relative Addressing**. This means the address is relative to the *current instruction pointer*.

### Example: Global Variable Access

```asm
; C: extern int global_var;

; WRONG (Absolute Address - not PIC)
mov rax, [global_var]

; RIGHT (RIP-Relative)
mov rax, [rip + global_var_offset]
```
The assembler and linker calculate the offset between the current instruction and the data section. This offset is **constant**, regardless of where the program is loaded in memory.

## 🔗 The Global Offset Table (GOT)

When accessing a global variable from *another* shared library, we don't know the offset at compile time. We use the **Global Offset Table (GOT)**.

The GOT is a table of pointers in the data section. The dynamic linker fills it with the real addresses at runtime.

### Assembly Flow
1.  **Indirect Load via GOT**:
    ```asm
    mov rax, [rip + GOT_entry_for_var] ; Load address from GOT
    mov rbx, [rax]                     ; Load value from that address
    ```

## 🌉 The Procedure Linkage Table (PLT)

When calling a function from another library (like `printf`), we use the **Procedure Linkage Table (PLT)**.

### Assembly Flow
1.  **Call PLT Stub**:
    ```asm
    call printf@plt
    ```
2.  **PLT Stub**:
    Jumps to the address in the GOT. Initially, this points back to the resolver.
3.  **Lazy Binding**:
    On the first call, the dynamic linker resolves `printf` and updates the GOT. Subsequent calls jump directly to `printf`.

## 🛠️ Inspecting PIC with `objdump`

To see RIP-relative addressing in action:

```bash
objdump -d -M intel mylib.so | grep -A 5 main
```
You'll see instructions like:
`mov rax, QWORD PTR [rip+0x200a]`

---
[[00-Index|Back to Assembly Index]]
