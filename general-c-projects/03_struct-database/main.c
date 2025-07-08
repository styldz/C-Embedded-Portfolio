#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(){
    int choice;
    char filename[100]= "students.txt";

    while(1){
        printf("\n===== Student Database =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                saveToFile(filename);
                break;
            case 4:
                loadFromFile(filename);
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}