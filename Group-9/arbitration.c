/*name: Naveen kumar, Lakshmi c
date : 21/04/2022
purpose: write a program to perform arbitration of two arguments*/

#include<stdio.h>
void byte(int ,int );                                 // declaring function prototype
int main ()
{
int arg1,arg2,i;                                     // considering  2 arguments
printf("enter the arguments1\n");                   // entering first argument
scanf("%x",&arg1);                                   // read the entered arguments
printf("enter the arguments2\n");                     // entering the second arguments
scanf("%x",&arg2);                                    // read the second arguments
byte(arg1,arg2);                                       // calling  function
}
void byte(int arg1,int arg2)                         // passing arguments in function
{
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


