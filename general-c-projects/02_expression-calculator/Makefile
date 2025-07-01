# Name of the output program
TARGET = calc

# Source files
SRCS = main.c parser.c evaluator.c

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -std=c99

# Build rule
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lm

clean:
	del $(TARGET).exe 2> NUL || true