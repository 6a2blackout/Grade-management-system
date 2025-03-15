//this is the student structure
#include "Grade.c"



typedef struct {
    int id;
    char *name;
    Grade *grades;
    int gradeCounter;
    float gpa;
} Student;