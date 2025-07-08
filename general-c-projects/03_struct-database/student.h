#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LEN 50
#define MAX_STUDENTS 100

typedef struct{
    int id;
    char name[MAX_NAME_LEN];
    float gpa;
}Student;

extern Student students[MAX_STUDENTS];
extern int studentCount;


void addStudent();
void viewStudents();
void saveToFile(const char *filename);
void loadFromFile(const char *filename);


#endif

