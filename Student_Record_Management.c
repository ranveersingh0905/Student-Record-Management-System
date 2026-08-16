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

void savetoFile();
void loadFromFile();

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
    printf("   ADD STUDENT RECORD\n");
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

     savetoFile();

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
    printf("   STUDENT RECORDS\n");
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

/*-------------------------------------------
        Search Students by Roll Number
-------------------------------------------*/
void searchStudent()
{
    int rollno, i, found = 0; //Variable to store roll number, loop variable and found flag

    if(totalStudents == 0)
    {
        printf("\n No Student Records Found ! \n");
        return;
    }

    printf("\n********************************\n");
    printf("  SEARCH STUDENT RECORD \n");
    printf("***********************************\n");

    printf("Enter Roll Number to Search : "); // Input roll number to search
    scanf("%d", &rollno);

    for(i = 0; i<totalStudents; i++)
    {
        if(student[i].rollno == rollno) // Check if roll number matches
        {
            
            found = 1; // Set found flag to 1

            printf("\n\n Student Record Found : \n ");
            printf("\n ================================\n");
            printf("\n Roll Number : %d", student[i].rollno);
            printf("\n Name        : %s", student[i].name);
            printf("\n Age         : %d", student[i].age);
            printf("\n Department  : %s", student[i].department);
            printf("\n Marks 1     : %.2f", student[i].marks1);
            printf("\n Marks 2     : %.2f", student[i].marks2);
            printf("\n Marks 3     : %.2f", student[i].marks3);
            printf("\n Percentage  : %.2f %%", student[i].percentage);

            break;
        }
    }

    if(found == 0)
    {
        printf("\n Student Record Not Found. \n");
    }

}

/*--------------------------------------------
        Update Student Details
---------------------------------------------*/
void updateStudent()
{
    int roll,i;
    int found = 0;

    if(totalStudents == 0);
    {
        printf("\n No Student Records Available. \n");
        return;
    }

    printf("\n**************************************");
    printf("\n  UPDATE STUDENT ");
    printf("\n***************************************");

    printf("\n Enter Roll Number : ");
    scanf("%d",&roll);

    for(i = 0; i < totalStudents; i++)
    {
        if(student[i].rollno == roll)
        {
            found = 1;

            printf("\n Enter New Name  : ");
            scanf("%[^\n], student[i].name");

            printf("\n Enter New Age   :");
            scanf("%d", &student[i].age);

            printf("\n Enter New Department : ");
            scanf("%[^\n], student[i].department");

            printf("\n Enter new marks 1 : ");
            scanf("%f", &student[i].marks1);

            printf("\n Enter new marks 2 : ");
            scanf("%f", &student[i].marks2);

            printf("\n Enter new marks 3 : ");
            scanf("%f", &student[i].marks3);

            student[i].percentage = calculatePercentage(student[i].marks1, student[i].marks2 ,student[i].marks3);

            savetoFile();

            printf("\n Record of Student Updated Successfully. \n");
            break;
        }
    }

    if(found == 0)
    {
        printf("\n Student Record Not Found. \n");
    }

}

/*-------------------------------------------
        Delete Student Record
---------------------------------------------*/
void deleteStudent()
{
    int roll,i,j;
    int found = 0;
    
    if (totalStudents == 0)
    {
        printf("\nNo Student Records Available. \n");
        return;
    }

    printf("\n***********************************");
    printf("\n    DELETE STUDENT");
    printf("\n************************************");

    printf("\n Enter Roll Number :");
    scanf("%d",&roll);

    for(i = 0; i < totalStudents; i++)
    {
        found = 1;

        /* Shift all record one position left */

        for(j = i; j < totalStudents - 1;j++ )
        {
            student[j] = student[ j + 1];
        }

        totalStudents--;

        savetoFile();

        printf("\n Student Record Deleted Successfully. \n");
        break;
    }
}

/*--------------------------------------------
        Save Student Record to File   
----------------------------------------------*/
void savetoFile()
{
    FILE *fp;
    fp = fopen("student.dat","wb");

    if (fp == NULL)
    {
        printf("\n Error : Unable to create file. \n");
        return;
    }

    fwrite(student, sizeof( struct Student), totalStudents, fp);

    fclose(fp);

}

/*-------------------------------------------
        Load Student Records from File
---------------------------------------------*/
void loadFromFile()
{
    FILE *fp;

    fp = fopen("student.dat","rb");

    if(fp == NULL)
    {
        /* File does not exist yet */
        return;
    }

    totalStudents = fread(student, sizeof(struct Student), MAX, fp);

    fclose(fp);
}

/*--------------------------------------------
        Main Function 
----------------------------------------------*/

int main()
{
    int choice; // Variable to store user choice

    loadFromFile();

    while(1) //Infinite loop to display menu until user chooses to exit
    {
        printf("\n**********************************\n");
        printf(" STUDENT RECORD MANAGEMENT SYSTEM \n");
        printf("***********************************\n");
        
        printf("1. Add Student\n");
        printf("2. Display Students \n");
        printf("3. Search Student \n");
        printf("4. Update Student \n");
        printf("5. Delete Student \n ");
        printf("6. Exit \n");
        printf("\n ************************************\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            addStudent();
            break;

            case 2:
            displayStudents();
            break;

            case 3:
            searchStudent();
            break;

            case 4:
            updateStudent();
            break;

            case 5:
            deleteStudent();
            break;

            case 6:
            printf("\n Thank You for using Student Record Management System. Goodbye! \n");
            return 0;

            default:
            printf("\n Invalid Choice! Please try again. \n");
        }
    }

    return 0;
}