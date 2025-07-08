# ---- Makefile for 03_struct_database ----

# Output executable name
TARGET = student_db

# Source files
SRCS = main.c student.c

# Compiler
CC = gcc

# Compiler flags:
# -Wall: enable all warnings
# -std=c99: use C99 standard
CFLAGS = -Wall -std=c99

# Default rule: how to build the project
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Cleanup rule for Windows
clean:
	del $(TARGET).exe 2> NUL || true

# Optional: prevent "all" and "clean" from being treated as filenames
.PHONY: all clean