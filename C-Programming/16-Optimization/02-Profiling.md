# Profiling

"Premature optimization is the root of all evil." - Donald Knuth.
Before optimizing, you must **measure** where your program spends its time.

## ⏱️ `gprof` (GNU Profiler)

`gprof` helps you analyze the performance of your C programs.

### Steps

1.  **Compile with Profiling Enabled (`-pg`)**
    ```bash
    gcc -pg -o myapp main.c
    ```

2.  **Run the Program**
    ```bash
    ./myapp
    ```
    This generates a file named `gmon.out`.

3.  **Analyze the Output**
    ```bash
    gprof myapp gmon.out > analysis.txt
    ```

### Interpreting Output
The "Flat Profile" shows how much time was spent in each function.

```
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 40.00      0.40     0.40  1000000     0.00     0.00  complex_calculation
 20.00      0.60     0.20        1   200.00   200.00  main
```
Focus your optimization efforts on `complex_calculation`.

---
[[00-Index|Back to Optimization Index]]
