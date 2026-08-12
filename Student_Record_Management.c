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

/*----------------------------------------------
                Global Variable
-------------------------------------------------*/ 

struct Student student[MAX] ;
int totalStudents = 0;

/**/