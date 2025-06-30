#include <stdio.h>
#include "calculator.h"


int main(){
    int a, b, choice;
    float result;

    while(1){
        printf("\nSimple Calculator\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        if (choice==5){
            printf("\nGoodbye!\n");
            break;
        }

        printf("Enter two integers: ");
        scanf("%d %d", &a, &b);

        switch(choice) {
            case 1: result = add(a,b); break;
            case 2: result = subtract(a,b); break;
            case 3: result = multiply(a,b); break;
            case 4: result = divide(a,b); break;

            default:
                printf("\n Invalid choice!");
                continue;
        }

        printf("Result: %.2f\n", result);
    }
    return 0;
}


