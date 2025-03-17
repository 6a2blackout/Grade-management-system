#include <stdio.h>
#include <stdlib.h>
#include "Student.c"




int main(int argc, char * * argv){


    int choice;
    int count = 0;
    size_t size = 0 * sizeof(Student *);
    Student **studentList = malloc(size);


    printf("1.\tCreate new Student\n2.\tRead student data from CSV File\n3.\tUpdate Student\n4.\tprint student List\n");
    printf("5.\tPrint Student Grades\n6.\tTo Sort\n7.\tAdd Grade to Student\n-1.\tQuite\n\nEnter choice:\t");
    scanf("%d", &choice);
    printf("\n");

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
            //ask for student name and id
            
            printf("\nEnter Student Id: ");
            scanf("%d", &studentIdIn);

            printf("\nenter student Name: ");
            scanf("%s", studentNameIn);
            count++;

            size = count * sizeof(Student *);
            studentList = realloc(studentList, size);
            studentList[count-1] = createStudent(studentIdIn, studentNameIn);
            printf("\n\t\t\t\t\t-------------------------------STUDENT ADDED SUCCESSFULLY--------------------------------\n\n");
            
            break;




        case 2:
            //needs to be able to read if there is any grades
            printf("\nenter the name of the file:\n");
            char fileName[50];
            scanf("%s", fileName);
            FILE *fptr = fopen(fileName, "r");
            fscanf(fptr, "%d, %49[^,]", &studentIdIn, studentNameIn);
            count++;
            size = count * sizeof(Student *);
            studentList = realloc(studentList, size);
            studentList[count-1] = createStudent(studentIdIn, studentNameIn);

            printf("\n\t\tstudent data successfully read and added\n\n");
            break;
    
        case 3:
            //ask if he wants to change name, or he wants to add or remove a grade, or whatever
            printf("\n1.\tChange student ID\n");

            scanf("%d", &decision);

            switch (decision)
            {
            case 1:
                printf("\nenter the student id of the student you want to change: ");
                scanf("%d", &targetId);
                printf("\nenter the new student id: ");
                scanf("%d", &studentIdIn);
                for(int i=0; i<count; i++){
                    if(studentList[i]->id == targetId){
                        changeStudentId(studentList[i], studentIdIn);
                        i=count;
                    }
                }

                break;
            default:
                break;
            }

            break;
        
        case 4:
            //to print the list of students

            for(int i=0; i<count; i++){
                printf("\n%d.\n\tStudent ID: %d\n\tStudent Name: %s", i+1, studentList[i]->id, studentList[i]->name);
            }

            break;


        case 5:

            printf("\nenter Student ID: \n");
            scanf("%d", &targetId);
            for(int i=0; i<count; i++){
                if(studentList[i]->id == targetId){
                    printClassList(studentList[i]);
                }
            }

            break;


        case 6:
            printf("\nEnter student id: \n");
            scanf("%d", &targetId);
            



            break;
        case 7:


            printf("\nenter the student id for the student you want to add the grade to:\n");
            scanf("%d", &targetId);
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
            printf("\nenter the class name: \n");
            scanf("%s", gradeName);
            printf("\nenter the final grade: \n");
            scanf("%f", &gradegrade);

            for(int i=0; i<count; i++){
                if(studentList[i]->id == targetId){
                    Grade *newGrade = createGrade(strdup(gradeName), gradegrade);
                    addGrade(studentList[i], newGrade);
                    i=count;
                }
            }

            printf("\n\t\t\t\t\t-------------------------------GRADE ADDED SUCCESSFULLY--------------------------------\n\n");

            break;
        case 8:
            printf("\nenter student id: ");
            scanf("%d", &targetId);
            for(int i=0; i<count; i++){
                if(studentList[i]->id == targetId){
                    printGradeGraph(studentList[i]);
                }
            }
            break;
        default:
            break;
        }
        printf("1.\tCreate new Student\n2.\tRead student data from CSV File\n3.\tUpdate Student\n4.\tprint student List\n");
        printf("5.\tPrint Student Grades\n6.\tTo Sort\n7.\tTo Add Grade to student\n-1.\tQuite\n");
        scanf("%d", &choice);
        printf("\n");
    }


}

