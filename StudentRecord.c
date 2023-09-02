#include<stdio.h>
#include<stdlib.h>
struct studentData
    {
        char name[30];
        float subject[10];
        int subjectCredit[10];
        char usn[20];
        float total_marks,average,percentage,cgpa;
        

    };
int n;
struct studentData input(struct studentData student[]); //To input student details
struct studentData calculate(struct studentData student[]); //To calculate required details
struct studentData display(struct studentData student[]); //To display student details
int main()
{
    
    struct studentData student[20];
    struct studentData input(struct studentData student[]);
    struct studentData calculate(struct studentData student[]);
    struct studentData display(struct studentData student[]);
    return 0;
}
struct studentData input(struct studentData student[])
{
    printf("\n*****INPUT STUDENT DETAILS*****\n");
    printf("Enter the total number of students: ");
    scanf("%d",&n);
}