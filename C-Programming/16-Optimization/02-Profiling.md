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

## 🔥 `perf` (Linux)

`perf` is a powerful sampling profiler built into the Linux kernel. It has much lower overhead than `gprof` and doesn't require recompiling (though `-g` helps).

### Usage

1.  **Record**:
    ```bash
    perf record -g ./myapp
    ```
    This creates `perf.data`.

2.  **Report**:
    ```bash
    perf report
    ```
    Opens an interactive TUI showing where CPU time was spent.

3.  **Annotate**:
    Press `a` inside the report to see the assembly code with hot instructions highlighted.

### Flame Graphs
You can visualize `perf` output as a Flame Graph (requires Brendan Gregg's scripts).
1.  `perf script > out.perf`
2.  `./stackcollapse-perf.pl out.perf > out.folded`
3.  `./flamegraph.pl out.folded > flamegraph.svg`

## 🧠 Valgrind (Callgrind)

Valgrind is mostly for memory debugging, but the `callgrind` tool is excellent for profiling instruction counts and cache misses.

```bash
valgrind --tool=callgrind ./myapp
```
View the output (`callgrind.out.PID`) with **KCachegrind** (GUI).

---
[[00-Index|Back to Optimization Index]]
