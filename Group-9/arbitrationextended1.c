/*name: Naveen kumar, Lakshmi c
date : 21/04/2022
purpose: write a program to perform arbitration of two arguments*/

#include<stdio.h>                                             //  including header file
void standard(int ,int );                                   // declaring function prototype for standard
void extended(int , int );                                 // declaring function prototype for extended
int main ()
{
int arg1,arg2,i,j;                                     // considering  2 arguments
printf("enter the arguments1\n");                   // entering first argument
scanf("%x",&arg1);                                   // read the entered arguments
printf("enter the arguments2\n");                     // entering the second arguments
scanf("%x",&arg2);                                     //read the second arguments
printf("Binary value");                                 //print the binary value
printf("\n");                                           // read the second arguments
standard(arg1,arg2);                                     //calling the function
printf("\n");                                           // read the second arguments
extended(arg1,arg2);                                       // calling  function
}
void standard(int arg1,int arg2)                         // passing arguments in function
{

for(int j=10;j>=0;j--)                                 // for loop to  print binary value
 {
     printf("%d ",arg1>>j&1);                           // printing the binary values of arg1

 }
 printf("\n");                                        //line spacing
 for(int i=10;i>=0;i--)
 {
     printf("%d ",arg2>>i&1);                      // printing the binary values of arg 2
 }
 printf("\n");
for(int i=10;i>=0;i--)                               // running for loop
{
    if(((arg1>>i)&0x01)!=((arg2>>i)&0x01))         // comparing  2 arguments bit by bit
    {
        if(((arg1>>i)&0x01)>((arg2>>i)&0x01))        // if condition is used to print the won argument
            {
                printf("arbitration 2 wins");       // printing the won arguments
                break;
            }
            else
            {

                printf("arbitration 1 wins");     // printing the won arguments
                break;
            }
    }
}
}
void extended(int arg1,int arg2)                         // passing arguments in  extended function
{

for(int j=28;j>=0;j--)                                 // for loop to print binary
 {
     printf("%d ",arg1>>j&1);                         //  printing  argument 1

 }
 printf("\n");                                        //print next line
 for(int i=28;i>=0;i--)                              // for loop to print the argument 2 values
 {
     printf("%d ",arg2>>i&1);                          // print the argument 2 binary value
 }
 printf("\n");                                         // print next line
for(int i=28;i>=0;i--)                               // running for loop for 29 times
{
    if(((arg1>>i)&0x01)!=((arg2>>i)&0x01))         // comparing  2 arguments bit by bit
    {
        if(((arg1>>i)&0x01)>((arg2>>i)&0x01))        // if condition is used to print the won argument
            {
                printf("arbitration 2 wins");       // printing the won arguments
                break;                                 // end of the condition
            }
            else
            {

                printf("arbitration 1 wins");     // printing the won arguments
                break;                              // break the condition
            }
    }
}
}

