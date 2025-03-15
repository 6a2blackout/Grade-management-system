#include <stdio.h>
#include <stdlib.h>
#include "Student.c"

int main(int argc, char * * argv){
    char *student1Name = "loay abu saifan";
    Student *student1 = createStudent(12345, student1Name);
    char *class1Name = "computer science";
    char *class2Name = "engineering";
    Grade *grade1 = createGrade(class1Name, 2);
    Grade *grade2 = createGrade(class2Name, 4);

    printf("before grades are added:\nname: %s\nid: %d\nGPa: %f\n\n\n", student1->name, student1->id, student1->gpa);

    addGrade(student1, grade1);
    printf("after 1 grade is added:\nname: %s\nid: %d\nGpa: %f\n\n\n", student1->name, student1->id, student1->gpa);

    addGrade(student1, grade2);
    printf("after 2 grade are added:\nname: %s\nid: %d\nGpa: %f\n\n\n", student1->name, student1->id, student1->gpa);



}

