// Write a c program to accept 2 integer from a c program and swap the contents of the variable using pointer pointing to those variables.

#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void main()
{
    int x,y;
    printf("Enter the two number below:");
    scanf("%d%d",&x,&y);
    printf("\nThe two numbers are %d %d",x,y);
    swap(&x,&y);
    printf("\nThe two numbers are %d %d",x,y);
}