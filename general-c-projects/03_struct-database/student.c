#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student students[MAX_STUDENTS];
int studentCount=0;


void addStudent(){
    if(studentCount >= MAX_STUDENTS){
        printf("Database is full!\n");
        return;
    }

    Student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
 
    printf("Enter gpa: ");
    scanf("%f", &s.gpa);

    students[studentCount++] = s;
    printf("Student added successfully to database.\n");
}

void viewStudents(){
    if(studentCount == 0){
        printf("There is no student in the database!\n");
        return;
    }

    printf("\n Student List:\n");
    for(int i = 0; i < studentCount; i++){
        printf("ID: %d  |  Name: %s  | GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}


void saveToFile(const char *filename){
    FILE *fp = fopen(filename, "w");
    if(!fp){
        printf("Failed to open file for writing!");
        return;
    }

    for(int i=0; i<studentCount; i++){
        fprintf(fp, "%d,%s,%.2f\n",students[i].id, students[i].name, students[i].gpa);
    }

    fclose(fp);
    printf("Saved %d students to '%s' successfully.\n", studentCount, filename);
}

void loadFromFile(const char *filename){
    FILE *fp = fopen(filename, "r");
    if(!fp){
        printf("Failed to open file for reading!");
        return;
    }

    studentCount = 0;
    while (fscanf(fp, "%d, %49[^,], %f\n", &students[studentCount].id, students[studentCount].name, &students[studentCount].gpa) == 3){
        studentCount++;
        if(studentCount >= MAX_STUDENTS){
            break;
        }
    }

    fclose(fp);
    printf("Loaded %d students from '%s' successfully.", studentCount,  filename);
}

