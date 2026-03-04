# Makefile for C Vault Examples

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Directories
EXAMPLES_DIR = Code-Examples

# Targets
all: basics fsm libmath

basics:
	$(CC) $(CFLAGS) $(EXAMPLES_DIR)/01-Basics/hello.c -o $(EXAMPLES_DIR)/01-Basics/hello

fsm:
	$(CC) $(CFLAGS) $(EXAMPLES_DIR)/37-State-Machines/turnstile.c -o $(EXAMPLES_DIR)/37-State-Machines/turnstile

# Standard Project Structure Example
libmath:
	$(MAKE) -C $(EXAMPLES_DIR)/38-Project-Structure

# GTK requires pkg-config, so we make it optional
gui:
	$(CC) $(CFLAGS) `pkg-config --cflags gtk4` $(EXAMPLES_DIR)/32-GUI-Programming/hello_gtk.c -o $(EXAMPLES_DIR)/32-GUI-Programming/hello_gtk `pkg-config --libs gtk4`

clean:
	rm -f $(EXAMPLES_DIR)/01-Basics/hello
	rm -f $(EXAMPLES_DIR)/37-State-Machines/turnstile
	rm -f $(EXAMPLES_DIR)/32-GUI-Programming/hello_gtk
	$(MAKE) -C $(EXAMPLES_DIR)/38-Project-Structure clean
