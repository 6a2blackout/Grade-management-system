#include <stdio.h>
#include <stdlib.h>
#include "Student.c"

void swap1(Student *a, Student *b){
    Student temp = *a;
    *a = *b;
    *b = temp;
}
int partition1(Student **list, int low, int high){
    float p = list[low]->gpa;
    int i=low;
    int j=high;

    while(i<j){
        while(list[i]->gpa <= p && i<=high-1){
            i++;
        }

        while(list[j]->gpa > p && j>=low+1){
            j--;
        }
        if(i < j){
            swap1(list[i], list[j]);
        }
    }
    swap1(list[low], list[j]);
    return j;
}
void quickSort1(Student **list, int low, int high){
    if(low < high){
        int pi = partition1(list, low, high);

        quickSort1(list, low, pi-1);
        quickSort1(list, pi+1, high);
    }
}
void sortByGPA(Student **list, int low, int high){
    quickSort1(list, low, high);
}

//------------------------------------------------------------------------------------------------------------------------------------------------

int partition2(Student **list, int low, int high){
    int p = list[low]->id;
    int i=low;
    int j=high;

    while(i<j){
        while(list[i]->id <= p && i<=high-1){
            i++;
        }

        while(list[j]->id > p && j>=low+1){
            j--;
        }
        if(i < j){
            swap1(list[i], list[j]);
        }
    }
    swap1(list[low], list[j]);
    return j;
}


void quickSort2(Student **list, int low, int high){
    if(low < high){
        int pi = partition2(list, low, high);

        quickSort2(list, low, pi-1);
        quickSort2(list, pi+1, high);
    }
}


void sortById(Student **list, int low, int high){

}
//------------------------------------------------------------------------------------------------------------------------------------------------



int main(int argc, char * * argv){
    int choice;
    int count = 0;
    size_t size = 0 * sizeof(Student *);
    Student **studentList = malloc(size);

    printf("\n1.\tCreate a new Student\n\n2.\tCSV Files\n\n3.\tAdd Grade for a Student\n\n4.\tUpdate Student Details");
    printf("\n\n5.\tPrint Student List\n\n6.\tPrint Student Grades\n\n-1.\tQuit\n\n");
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
            printf("Enter name of the file:\t");
            char fileName[50];
            scanf("%s", fileName);
            FILE *fptr = fopen(fileName, "r");
            fscanf(fptr, "%d, %49[^,]", &studentIdIn, studentNameIn);
            count++;
            size = count * sizeof(Student *);
            studentList = realloc(studentList, size);
            studentList[count-1] = createStudent(studentIdIn, studentNameIn);

            printf("\n\t\t\t\t\t-------------------------------STUDENT ADDED SUCCESSFULLY--------------------------------\n\n");




            break;
        case 3:

            printf("Enter a Student ID:\t");
            targetId = -1;
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
        case 4:
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
            printf("1.\tUpdate Student ID\n\n2.\tUpdate Student name\n\n3.\tRemove a Student\n\n");
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
            case 3:

                for(int i=0; i<count; i++){
                    if(studentList[i]->id == targetId){
                        deleteStudent(studentList[i]);
                        for(int j=i; j<count-1; j++){
                            studentList[j] = studentList[j+1];
                        }
                        count--;
                        size = count * sizeof(Student *);
                        studentList = realloc(studentList, size);
                        i=count;
                        setter = 1;
                    }
                }
            
                break;
            default:
                break;
            }
            break;
        case 5:
            printf("\n\n1.\tPrint by Name\n\n2.\tPrint by Student ID\n\n3.\tPrint by GPA\n\n");
            printf("Enter choice:\t");
            scanf("%d", &decision);

            switch (decision)
            {
            case 1:
                for(int i=0; i<count; i++){
                    printf("\n%d.\n\tStudent ID:\t%d\n\n\tStudent Name:\t%s\n" ,i+1, studentList[i]->id, studentList[i]->name);
                }
                break;
            case 2:
                sortById(studentList, 0, count-1);
                for(int i=count-1; i>=0; i--){
                    printf("\n%d.\n\tStudent ID:\t%d\n\n\tStudent Name:\t%s\n\nGPA: %f\n-----------------------------------\n" ,(count-i), studentList[i]->id, studentList[i]->name, studentList[i]->gpa);
                }
                break;
            case 3:
                sortByGPA(studentList, 0, count-1);
                for(int i=count-1; i>=0; i--){
                    printf("\n%d.\n\tStudent ID:\t%d\n\n\tStudent Name:\t%s\n\nGPA: %f\n-----------------------------------\n" ,(count-i), studentList[i]->id, studentList[i]->name, studentList[i]->gpa);
                }
                break;
            default:
                break;
            }
            break;
        case 6:
            printf("Enter a Student ID:\t");
            targetId = -1;
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
        printf("\n1.\tCreate a new Student\n\n2.\tCSV Files\n\n3.\tAdd Grade for a Student\n\n4.\tUpdate Student Details");
        printf("\n\n5.\tPrint Student List\n\n6.\tPrint Student Grades\n\n-1.\tQuit\n\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    }
}