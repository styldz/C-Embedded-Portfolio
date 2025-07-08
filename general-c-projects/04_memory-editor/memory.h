#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

extern unsigned char *memoryBlock;
extern size_t memorySize;

void allocateMemory(size_t size);
void freeMemory();
void displayMemory();
void modifyMemory(size_t index, unsigned char value);

#endif