/*
-------------------------------------------------------------------------------------------------------------------------------------------
*Project Name : Student Record Management System
*Description  :
This project is a menu-driven Student Record Management System developed in C.
It demonstrate the use of:
    -Structures
    -Arrays
    -Functions
    -Loops
    -Switch Case
    -Basic Data Management

Features:
    1.Add Student
    2.Display Students
    3.Search Student
    4.Update Student
    5.Delete Student
    6.Exit

Developed By : Ranveer Singh
Language     : C
--------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>

#define MAX 100

/*--------------------------------------
         STRUCTURE DEFINITION
----------------------------------------*/

struct Student
{
    int rollno;
    char name[50];
    int age;
    char department[30];

    float marks1;
    float marks2;
    float marks3;

    float percentage;
};

/*-----------------------------------------------
                Global Variable
-------------------------------------------------*/ 

struct Student student[MAX] ;
int totalStudents = 0;

/*--------------------------------------------
            Function Declarations
----------------------------------------------*/
float calculatePercentage(float marks1,float marks2,float marks3);

void addStudent();
void displayStudents();

void searchStudent();
void updateStudent();
void deleteStudent();

/*--------------------------------------------
            Calculate Percentage
----------------------------------------------*/
float calculatePercentage(float marks1,float marks2,float marks3)
{
    return(marks1 + marks2 + marks3) / 3.0;
}

/*--------------------------------------------
        Add Student
----------------------------------------------*/
void addStudent()
{
    printf("\n********************************\n");
    printf("\t\t ADD STUDENT RECORD\n");
    printf("********************************\n");

    printf("Enter Roll Number : "); // Input roll number of student
    scanf("%d", &student[totalStudents].rollno);

    printf("Enter Name : "); // Input name of student
    scanf(" %[^\n]", student[totalStudents].name); // To read string with spaces

    printf("Enter Age : "); // Input age of student
    scanf("%d", &student[totalStudents].age);

    printf("Enter Department : "); // Input department of student
    scanf(" %[^\n]", student[totalStudents].department);

    printf("Enter Marks of Subject 1 : "); // Input marks of subject 1
    scanf("%f", &student[totalStudents].marks1);

    printf("Enter Marks of Subject 2 : "); // Input marks of subject 2
    scanf("%f", &student[totalStudents].marks2);

    printf("Enter Marks of Subject 3 : "); // Input marks of subject 3
    scanf("%f", &student[totalStudents].marks3);
    
    student[totalStudents].percentage =
     calculatePercentage(student[totalStudents].marks1, student[totalStudents].marks2, student[totalStudents].marks3);

     totalStudents++; // Increment total number of students

     printf("\nStudent Record Added Successfully!\n");
}

/*----------------------------------------------------
        Display Students
------------------------------------------------------*/
void displayStudents()
{
    int i;// Loop variable

    if(totalStudents == 0)
    {
        printf("\n No Student Records Found ! \n");
        return;
    }

    printf("\n********************************\n");
    printf("\t\t STUDENT RECORDS\n");
    printf("********************************\n");

    for(i = 0; i<totalStudents; i++)
    {
        printf("\n Roll Number : %d \n", student[i].rollno); 
        printf("\n Name : %s \n", student[i].name);
        printf("\n Age : %d \n", student[i].age);
        printf("\n Department : %s \n", student[i].department);

        printf("\n Marks of Subject 1 : %.2f \n", student[i].marks1);
        printf("\n Marks of Subject 2 : %.2f \n", student[i].marks2);
        printf("\n Marks of Subject 3 : %.2f \n", student[i].marks3);

        printf("\n Percentage : %.2f \n", student[i].percentage);
    }

    printf("\n********************************\n");

}