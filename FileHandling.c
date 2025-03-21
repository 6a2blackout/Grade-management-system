#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.c"


Student *ReadCsvFile(FILE * fptr){
    
   
    Student *daStudent;
    int studentIdFromFile;
    char studentNameFromFile[50];
    fscanf(fptr, "%d, %49[^,] ", &studentIdFromFile, studentNameFromFile);

    daStudent = createStudent(studentIdFromFile, studentNameFromFile);


    return daStudent;
}