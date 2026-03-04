# Code Coverage with gcov

Code coverage tells you what percentage of your code is executed by your tests.

## Generating Coverage Data
Compile with `--coverage`:

```bash
gcc -fprofile-arcs -ftest-coverage -g main.c -o app
./app
```
This generates `.gcno` and `.gcda` files.

## Viewing Results (`gcov`)
Run `gcov` on your source file:
```bash
gcov main.c
```
This creates `main.c.gcov`, which annotates source lines with execution counts.

## LCOV (HTML Report)
For a nice visual report:
```bash
sudo apt install lcov
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory out
```
Open `out/index.html` to see color-coded coverage.

## CI Integration (Codecov)
Upload coverage reports to Codecov.io in your GitHub Action:

```yaml
    - name: Upload coverage reports to Codecov
      uses: codecov/codecov-action@v3
```

---
[[00-Index|Back to Index]]
