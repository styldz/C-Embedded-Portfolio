# ---- Makefile for Memory Editor ----

# Output file name
TARGET = memory_editor

# Source files
SRCS = main.c memory.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=c99

# Default build rule
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	del $(TARGET).exe 2> NUL || true

.PHONY: all clean