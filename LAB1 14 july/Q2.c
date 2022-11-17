// Q2 Write a c program to assign values to each member 
//of the follwing structure.Pass the populated structure 
//to a function using call by address and display the values of each member of the strucuture
// in that fucnction.
// struct info
// {
// int roll;
// char name[50];
// float cgpa;
// };
#include<stdio.h>
#include<stdlib.h>
struct info
{
    int roll;
    char name[50];
    float cgpa;
};

void Print(struct info S[],int n)
{
    printf("The Members are:\n");
    for(int i=0;i<n;++i)
   {
    printf("Student %d",n+1);
    printf("\nRoll number:%d",S[i].roll);
    printf("\nName :%s",S[i].name);
    printf("\nCGPA:%f",S[i].cgpa);
    printf("\n");
   }

}
void main()
{
   struct info S1[10];
   int n;
   printf("Enter the Number of members you have:");
   scanf("%d",&n);
   for(int i=0;i<n;++i)
   {
    printf("Enter the Roll number:");
    scanf("%d",&S1[i].roll);
    printf("Enter the Name :");
    scanf("%s",&S1[i].name);
    printf("Enter the CGPA:");
    scanf("%f",&S1[i].cgpa);
   }
   Print(S1,n);
}