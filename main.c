#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.c"
#include "GPACalc.c"

int main(int argc, char * * argv){
    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL){
        perror("error opening the file");
        return 1;
    }
    

    Student *std1 = getStudentFromFile(fptr);

    printf("%d, %s, {", std1->id, std1->name);

    for(int i=0; i<(sizeof(std1->grades)/sizeof(std1->grades[0])); i++){
        if(i == (sizeof(std1->grades)/sizeof(std1->grades[0]))-1){
            printf("%lf}, %f", std1->grades[i], std1->gpa);
        }
        else{
            printf("%lf, ", std1->grades[i]);
        }
    }

    StudentDestruct(std1);
    fclose(fptr);
    return 0;
}

