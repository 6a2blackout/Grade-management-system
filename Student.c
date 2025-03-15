//this is the student functions

#include "Student.h"



Student * createStudent(int idIn, char *nameIn){

    Student *johnDoe = malloc(sizeof(Student));

    johnDoe->id = idIn;
    johnDoe->name=nameIn;
    Grade *gradeList;
    johnDoe->gradeCounter=0;
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
        sum+= temp->classGrade;
    }

    float result = (sum/johnDoe->gradeCounter);
    return result;
}

void changeStudentName(Student *johnDoe, char *newName){
    johnDoe->name=newName;
}

void changeStudentId(Student *johnDoe, int newId){
    johnDoe->id=newId;
}


/*void addGrade(Student *johnDoe, Grade *newGrade){
    johnDoe->gradeCounter++;

    if(johnDoe->gradeCounter == 1){
        johnDoe->grades[johnDoe->gradeCounter] = *newGrade;
        johnDoe->gpa = calculateGpa(johnDoe);
        return;
    }


    johnDoe->grades = (Grade *)realloc(johnDoe->grades, (sizeof(Grade) * johnDoe->gradeCounter));
    johnDoe->grades[johnDoe->gradeCounter] = *newGrade;
    johnDoe->gpa = calculateGpa(johnDoe);
}*/


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
        printf("%d.\tClass Name: %s\tClass Grade: %f\n\n", i, johnDoe->grades[i].className, johnDoe->grades[i].classGrade);
    }
}

