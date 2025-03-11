#include <stdio.h>
#include <stdlib.h>


float calculateGPA(float grades[], int numGrades){

    int sum = 0;
    for(int i=0; i<numGrades; i++){
        sum += grades[i];
    }

    return (sum/numGrades);
}