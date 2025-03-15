#include "Grade.h"





Grade * createGrade(char * classNameIn, float classGradeIn){
    Grade * grade1 = malloc(sizeof(Grade));
    grade1->className = classNameIn;
    grade1->classGrade = classGradeIn;

    return grade1;
}


void freeGrade(Grade *gradeIn){
    free(gradeIn);
}