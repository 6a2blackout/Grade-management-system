//this is the student functions

#include "Student.h"
#include <string.h>



Student * createStudent(int idIn, char *nameIn){

    Student *johnDoe = malloc(sizeof(Student));

    johnDoe->id = idIn;
    char *newName;
    newName = strdup(nameIn);
    johnDoe->name = newName;
    Grade *gradeList;
    johnDoe->gradeCounter = 0;
    gradeList=malloc(sizeof(Grade));
    johnDoe->grades=gradeList;
    johnDoe->gpa=0;

    return johnDoe;
}

void deleteStudent(Student *johnDoe){

    for(int i=0; i<johnDoe->gradeCounter; i++){
        Grade *tempo = &johnDoe->grades[i];
        freeGrade(tempo);
    }
    free(johnDoe->grades);
    free(johnDoe);
}




float calculateGpa(Student * johnDoe){
    float sum = 0;
    Grade *temp;
    for(int i=0; i<johnDoe->gradeCounter; i++){
        temp = &johnDoe->grades[i];
        sum+= (temp->classGrade/25);
    }

    float result = (sum/johnDoe->gradeCounter);
    return result;
}

void changeStudentName(Student *johnDoe, char *newName){
    johnDoe->name = newName;
}

void changeStudentId(Student *johnDoe, int newId){
    johnDoe->id=newId;
}




void addGrade(Student *johnDoe, Grade *newGrade){
    johnDoe->gradeCounter++;
    int temp = johnDoe->gradeCounter * (sizeof(Grade));
    johnDoe->grades=(Grade *)realloc(johnDoe->grades, temp);

    johnDoe->grades[johnDoe->gradeCounter-1] = *newGrade;

    johnDoe->gpa=calculateGpa(johnDoe);

}

void removeGrade(Student *johnDoe, char *courseName, float courseGrade){


    int index;
    for(int i=0; i<johnDoe->gradeCounter; i++){
        Grade *currentGrade = &johnDoe->grades[i];
        if((currentGrade->className == courseName) && (currentGrade->classGrade == courseGrade)){
            index = i;
            break;
        }
    }


    johnDoe->grades[index]=johnDoe->grades[johnDoe->gradeCounter-1];
    johnDoe->gradeCounter--;

    johnDoe->gpa=calculateGpa(johnDoe);


}

void printClassList(Student *johnDoe){
    if(johnDoe->gradeCounter == 0){
        printf("no grades added to the list");
        return;
    }
    for(int i=0; i<johnDoe->gradeCounter; i++){
        printf("%d.\n\tClass Name: %s\n\tClass Grade: %f\n\n", i+1, johnDoe->grades[i].className, johnDoe->grades[i].classGrade);
    }
}







char *getStudentName(Student * johnDoe){
    return johnDoe->name;
}

void printGradeGraph(Student *johnDoe){
    printf("\nStudent Name:\t%s\nStudent ID:\t%d\nStudent GPA:\t(%f)\n", johnDoe->name, johnDoe->id, johnDoe->gpa);
    for(int i=0; i<johnDoe->gradeCounter; i++){
        printf("\n%d.\t%s:   \t", i+1, johnDoe->grades[i].className);
        int repetitions = johnDoe->grades[i].classGrade/10;
        for(int j=0; j<repetitions; j++){
            printf("#");
        }
    }
}