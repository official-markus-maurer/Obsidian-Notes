# Secure Coding in C

C gives you direct access to memory, which is powerful but dangerous. Security vulnerabilities in C software have caused billions of dollars in damages.

## 📋 Topics

1.  **[[../../Shared-Concepts/Security/01-CIA-Triad|Security Principles (Shared)]]**
    -   CIA Triad (Confidentiality, Integrity, Availability).

2.  **[[../../Shared-Concepts/Security/02-Buffer-Overflows|Buffer Overflows (Shared)]]**
    -   Conceptual overview and prevention.

3.  **[[01-Buffer-Overflows|Implementing Buffer Overflow Protection]]**
    -   C-specific techniques (`strncpy`, Stack Canaries).

4.  **[[02-Format-String-Attacks|Format String Vulnerabilities]]**
    -   The danger of `printf(user_input)`

3.  **[[03-Integer-Overflows|Integer Overflows]]**
    -   Wrapping behavior
    -   Impact on memory allocation

---
**Next Section**: [[../15-System-Programming/00-Index|System Programming]]
