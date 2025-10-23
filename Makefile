# Makefile for EECS 348 Lab 8 - C Programming

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Executable names
EXE1 = temperature_convert
EXE2 = score_combinations

# Source files
SRC1 = temperature_convert.c
SRC2 = score_combinations.c

# Default target (build both programs)
all: $(EXE1) $(EXE2)

# Build temperature converter
$(EXE1): $(SRC1)
	$(CC) $(CFLAGS) -o $(EXE1) $(SRC1)

# Build NFL score combinations
$(EXE2): $(SRC2)
	$(CC) $(CFLAGS) -o $(EXE2) $(SRC2)

# Clean up compiled files
clean:
	rm -f $(EXE1) $(EXE2)
