CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Source files
SRC = src/mymath.c
TEST_SRC = test/test_main.c

# Targets
all: test_runner

test_runner: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f test_runner
