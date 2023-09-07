#include<stdio.h>
#include<stdlib.h>
int i,j;
static int n,total_sub;
struct studentData
    {
        char name[30],subjectName[10][30];
        float subjectMarks[10];
        int subjectCredit[10];
        float gp[10],CrGp[10],total_CrGp,total_credit;
        char usn[20];
        float total_marks,average,cgpa;

    };
struct studentData student[20];
void input(struct studentData student[]); //To input student details and calculate
void display(struct studentData student[]); //To display student details
int main()
{
    
    
    input(student);
    display(student);
    return 0;
}


void input(struct studentData student[])
{
    char cred,credDetail;
    //Modify the 1st printf sunidhi (this is given for eg)
    printf("Hey There! Find details about your marks just by entering details");
    for(i=0;i<1000000;i++);
    printf("\n\n-----INPUT STUDENT DETAILS-----\n\n");
    printf("Enter the total number of students: ");
    scanf("%d",&n);
    printf("\nEnter number of subjects: ");
    scanf("%d",&total_sub);
    for(i=0;i<n;i++)
    {
        student[i].total_marks=0;
        student[i].total_credit=0;

        //inputting details
        printf("Enter student %d details\n",i+1);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Enter student name: ");
        fgets(student[i].name,sizeof(student[i].name),stdin);
        printf("\nEnter usn: ");
        scanf("%s",student[i].usn);

        //print details about credits
        printf("Do you want credit calculation details? (y/n)");
        scanf(" %c",&credDetail);
        if(credDetail=='y' || credDetail=='Y')
        {    printf("\n-----CREDIT SYSTEM-----\n");
            printf("Marks\tGrade\tGrade Point\n");
            printf("91-100\tO\t10\n81-90\tA+\t9\n71-80\tA\t8\n61-70\tB+\t7\n51-60\tB\t6\n46-50\tC\t5\n40-45\tP\t4");
            printf("\nNOTE: If marks<40 -> Grade=F -> Grade Points =0");
        }
        printf("\nDo you have a credit system? (y/n) ");
        scanf(" %c",&cred);

        //entering each subject marks
        for(j=0;j<total_sub;j++)
        {
            printf("\nEnter subject %d name: ",j+1);
            scanf(" %s",student[i].subjectName[j]);
            printf("\nEnter subject %d marks(out of 100) ",j+1);
            scanf("%f",&student[i].subjectMarks[j]);

            //calculating total marks
            student[i].total_marks+=student[i].subjectMarks[j];

            
            if(cred=='y' || cred=='Y')
            {
                

                //input credits
                printf("\nEnter subject %d credits ",j+1);
                scanf("%d",&student[i].subjectCredit[j]);

                //assign grade acc to credit
                if(student[i].subjectMarks[j]>100)
                {
                    printf("Bro Chill! You got %f marks out of 100? I'm outta here",student[i].subjectMarks[j]);
                    exit(0);
                }
                else if(student[i].subjectMarks[j]>90)
                    student[i].gp[j]=10;
                else if(student[i].subjectMarks[j]>80)
                    student[i].gp[j]=9;
                else if(student[i].subjectMarks[j]>70)
                    student[i].gp[j]=8;
                else if(student[i].subjectMarks[j]>60)
                    student[i].gp[j]=7;
                else if(student[i].subjectMarks[j]>50)
                    student[i].gp[j]=6;
                else if(student[i].subjectMarks[j]>45)
                    student[i].gp[j]=5;
                else if(student[i].subjectMarks[j]>39)
                    student[i].gp[j]=4;
                else
                    student[i].gp[j]=0;
                
                /*Here, gp=grade points
                CrGp= gp * credits(of each subject) 
                cgpa=final cgpa(actually it's sgpa of one semester)*/

                student[i].total_credit+=student[i].subjectCredit[j];
                student[i].CrGp[j]=student[i].subjectCredit[j]*student[i].gp[j];
                student[i].total_CrGp+=student[i].CrGp[j];

            }

        }
        student[i].average=student[i].total_marks/total_sub;
        student[i].cgpa=student[i].total_CrGp/student[i].total_credit;

        //testing output using printf
        //printf("\nCgpa= %f\nAverage= %f\nperc=%f%%",student[i].cgpa,student[i].average,student[i].average);

    }
    
}

//Displaying details
void display(struct studentData student[])
{
    printf("\n\n-----GRADE CARD-----\n");
    for ( i = 0; i < n; i++)
    {
        
        printf("\nStudent Name: %s\tUSN: %s\n", student[i].name,student[i].usn);
        printf("\nSubject\tMarks\tCredit\tGrade\tCredit*Grade\n");
        printf("-------\t-----\t------\t------\t------------\n");
        for(j=0;j<total_sub;j++)
        {
            printf("%s\t%.2f\t%d\t%.2f\t%.2f\n",student[i].subjectName[j],student[i].subjectMarks[j],student[i].subjectCredit[j],student[i].gp[j],student[i].CrGp[j]);
        }
        printf("\nCGPA:%f",student[i].cgpa);
        printf("\nTotal Marks: %f",student[i].total_marks);
        printf("\nAverage: %.2f \nPercentage=%.2f%%\n",student[i].average,student[i].average);
        printf("****************\n");


    }
    
}