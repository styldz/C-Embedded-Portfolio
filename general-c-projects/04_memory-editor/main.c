#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int main(){

    int choice;
    size_t size, index;
    unsigned int value;

    while(1){
        printf("\n===== Memory Editor =====\n");
        printf("1. Allocate memory\n");
        printf("2. View memory (hex)\n");
        printf("3. Modify memory cell\n");
        printf("4. Free memory\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter number of bytes to allocate: ");
                scanf("%zu", &size);
                allocateMemory(size);
                break;
            
            case 2:
                displayMemory();
                break;

            case 3:
                printf("Enter index to modify: ");
                scanf("%zu", &index);
                printf("Enter new value (0-255): ");
                scanf("%u", &value);

                if(value > 255){
                    printf("Value must be between 0 and 255.\n");
                }

                else{
                    modifyMemory(index, (unsigned char)value);
                }

                break;
            
            case 4:
                freeMemory();
                break;
            
            case 5:
                freeMemory();
                printf("Exiting program...\n");
                return 0;
            default: 
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}