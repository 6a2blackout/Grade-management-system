#include <stdio.h>
#include <stdlib.h>
#include "Student.c"




int main(int argc, char * * argv){
    int choice;
    int count = 0;
    size_t size = 0 * sizeof(Student *);
    Student **studentList = malloc(size);

    printf("\n1.\tCreate a new Student\n\n2.\tAdd Grade for a Student\n\n3.\tUpdate Student Details\n\n4.\tPrint Student List\n\n5.\tPrint Student Grades\n\n-1.\tQuit\n\n");
    printf("Enter Choice : ");
    scanf("%d", &choice);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    int studentIdIn;
    char studentNameIn[50];
    int targetId;
    int decision;
    char gradeName[50];
    float gradegrade;
    int setter;



    while(choice != -1){
        switch (choice)
        {
        case 1:
            printf("Enter Student ID:\t");
            scanf("%d", &studentIdIn);
            printf("\n\nEnter Student Name:\t");
            scanf("%s", studentNameIn);

            count++;

            size = count * sizeof(Student *);
            studentList = realloc(studentList, size);
            studentList[count-1] = createStudent(studentIdIn, studentNameIn);

            printf("\n\t\t\t\t\t-------------------------------STUDENT ADDED SUCCESSFULLY--------------------------------\n\n");






            break;
        case 2:

            printf("Enter a Student ID:\t");
            scanf("%d", &targetId);
            printf("\n\n");
            setter = 0;
            for(int i=0; i<count; i++){
                if(studentList[i]->id == targetId){
                    i=count;
                    setter = 1;
                }
            }
            if(setter == 0){
                printf("\nWrong id try again\n\n");
                break;
            }
            printf("Enter Class Name:\t");
            scanf("%s", gradeName);
            printf("\nEnter Final Grade:\t");
            scanf("%f", &gradegrade);
            printf("\n\n");

            for(int i=0; i<count; i++){
                if(studentList[i]->id == targetId){
                    Grade *newGrade = createGrade(strdup(gradeName), gradegrade);
                    addGrade(studentList[i], newGrade);
                    i=count;
                }
            }

            printf("\n\t\t\t\t\t-------------------------------GRADE ADDED SUCCESSFULLY--------------------------------\n\n");



            break;
        case 3:
            printf("Enter a Student ID:\t");
            scanf("%d", &targetId);
            printf("\n\n");
            setter = 0;
            for(int i=0; i<count; i++){
                if(studentList[i]->id == targetId){
                    i=count;
                    setter = 1;
                }
            }
            if(setter == 0){
                printf("\nWrong id try again\n\n");
                break;
            }

            int decision;
            printf("1.\tUpdate Student ID\n\n2.\tUpdate Student name\n\n");
            printf("Enter choice:\t");
            scanf("%d", &decision);
            switch (decision)
            {
            case 1:
                printf("\nEnter new Student ID:\t");
                int newId;
                scanf("%d", &newId);
                setter = 0;
                for(int i=0; i<count; i++){
                    if(studentList[i]->id == targetId){
                        changeStudentId(studentList[i], newId);
                        i=count;
                        setter = 1;
                    }
                }
                if(setter == 0){
                    printf("\nOperation Failed\n\n");
                    break;
                }
                printf("\n\t\t\t\t\t-------------------------------ID Successfully Changed--------------------------------\n\n");
                break;
            case 2:
                printf("\nEnter new Student Name:\t");
                char newName[50];
                scanf("%s", newName);
                setter = 0;
                for(int i=0; i<count; i++){
                    if(studentList[i]->id == targetId){
                        changeStudentName(studentList[i], newName);
                        i=count;
                        setter = 1;
                    }
                }
                if(setter == 0){
                    printf("\nOperation Failed\n\n");
                    break;
                }
                printf("\n\t\t\t\t\t-------------------------------Name Successfully Changed--------------------------------\n\n");
                break;
            default:
                break;
            }
            break;
        case 4:
            for(int i=0; i<count; i++){
                printf("\n%d.\n\tStudent ID:\t%d\n\n\tStudent Name:\t%s\n" ,i+1, studentList[i]->id, studentList[i]->name);
            }
            
            break;
        case 5:
            printf("Enter a Student ID:\t");
            scanf("%d", &targetId);
            printf("\n\n");
            setter = 0;
            for(int i=0; i<count; i++){
                if(studentList[i]->id == targetId){
                    printGradeGraph(studentList[i]);
                    i=count;
                    setter = 1;
                }
            }
            if(setter == 0){
                printf("\nWrong id try again\n\n");
                break;
            }


            break;
        default:
            break;
        }
        printf("\n\n\n1.\tCreate a new Student\n\n2.\tAdd Grade for a Student\n\n3.\tUpdate Student Details");
        printf("\n\n4.\tPrint Student List\n\n5.\tPrint Student Grades\n\n7.\tSort Student List\n\n-1.\tQuit\n\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    }
}