/* this is the file handling
this program will read the student data from a file and create a new student instance
it will also be able to write student data back to a file
*/

/*the data input will have to be in this form
<student_id>, <student_Name>, <number of grades><{grade1,grade2,...}>, <GPA>
*/

/*is will also write the student data in this format*/
#include <stdio.h>
#include <stdlib.h>
#include "StudentCreator.c"
#include "GPACalc.c"

void toString(Student *stdIn){
    printf("%d, %.49s", stdIn->id, stdIn->name);

}


Student *getStudentFromFile(FILE * fptr){


    int stdId;
    char stdName[50];
    int numGrades;
    float stdGpa;
    fscanf(fptr, "%d, %49[^,], %d{", &stdId, stdName, &numGrades);

    float stdGrades[numGrades];

    for(int i=0; i<numGrades; i++){
        if(i==numGrades-1){
            fscanf(fptr, "%f}", &stdGrades[i]);
        }
        else{
            fscanf(fptr, "%f, ", &stdGrades[i]);
        }
    }


    stdGpa = calculateGPA(stdGrades, numGrades);

    Student *student1 = StudentCreate(stdId, stdName, stdGrades, stdGpa);
    return student1;

}





int main(int argc, char * * argv){


    FILE *fptr = fopen(argv[1], "r");
    if(fptr == NULL){
        return 1;
    }

    Student *myStudent;
    myStudent = getStudentFromFile(fptr);

    toString(myStudent);

    return 0;
}