#include <stdio.h>
#include <stdlib.h>
#include "Student.c"

Student *StudentCreate(int idIn, char *nameIn, float *gradesIn, float gpaIn){
    Student * student1;
    student1 = malloc(sizeof(Student));
    student1->id = idIn;
    student1->name = nameIn;
    student1->grades = gradesIn;
    student1->gpa = gpaIn;

    return student1;
}


void StudentDestruct(Student * studentIn){
    free(studentIn);
}