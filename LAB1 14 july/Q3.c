// write a c program to extract each byte from a given number and store them in separate variables and print the content of those variable.

#include<stdio.h>    
#include<stdlib.h>  
int main()
{
    int n;
    printf("Enter integer number:");
    scanf("%d",&n);
    int num[4];
    num[0]=(n&0xff);
    num[1]=((n>>8)&0xff);
    num[2]=((n>>16)&0xff);
    num[3]=((n>>24)&0xff);

      for(int i=3;i>=0;--i)
      {
        printf("\nNum %d:%d",i+1,num[i]);
      }
}