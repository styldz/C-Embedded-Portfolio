#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

unsigned char *memoryBlock = NULL;
size_t memorySize = 0;

void allocateMemory(size_t size){
    if(memoryBlock != NULL){
        printf("Memory already allocated. Free it first!\n");
        return;
    }

    memoryBlock = (unsigned char *)malloc(size);
    if(!memoryBlock){
        printf("Failed to allocate memory.\n");
        return;
    }

    memorySize = size;
    for(size_t i=0; i<size; ++i){
        memoryBlock[i] = 0;
    }

    printf("Allocated %zu bytes of memory.\n", size);
}

void freeMemory(){
    if(memoryBlock == NULL){
        printf("No memory to free.\n");
        return;
    }

    free(memoryBlock);
    memoryBlock = NULL;
    memorySize = 0;
    printf("Memory freed successfully.\n");
}

void displayMemory(){
    if(!memoryBlock){
        printf("No memory allocated!\n");
        return;
    }

    printf("\nMemory content (Hex view):\n");
    for(size_t i=0; i<memorySize; ++i){
        printf("%02X", memoryBlock[i]);

        if((i+1)%16 == 0 || i+1 == memorySize){
            printf("\n");
        }
    }
}

void modifyMemory(size_t index, unsigned char value){
    if(!memoryBlock){
        printf("No memory allocated!\n");
        return;
    }

    if(index >= memorySize){
        printf("Index out of bounds (0 to %zu).\n", memorySize-1);
        return;
    }

    memoryBlock[index] = value;
    printf("Modified memory at index %zu to 0x%02x.\n", index, value);
}