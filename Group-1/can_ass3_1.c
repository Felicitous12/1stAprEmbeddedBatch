/*
Author : Siva, Sharada
Date : 21-04-2022
Purpose : Program to perform arbitration of message identifiers of standard frame
*/

#include<stdio.h>
void function( int arg1, int arg2);//function prototype

void main()
{
    
    int arg1, arg2;//declaration of variables
    //read the inputs
    printf("Enter the Message Identifier 1 for a standard frame : ");
    scanf("%x",&arg1);
    printf("Enter the Message Identifier 2 for a standard frame : ");
    scanf("%x",&arg2);
    function(arg1&0x7ff,arg2&0x7ff);//function call
}
void function( int arg1, int arg2)//function definition
{
    for(int i = 10 ; i >= 0 ; i--)//itereate over 11 bits
    {
        if(((arg1>>i)&0x01)!=((arg2>>i)&0x01))//condition checks if the bit of argument 1 and argument 2 are unequal
        {
            if(((arg1>>i)&0x01))//condition checks if the bit is 1
            {
                printf("Message Identifier 2  won the arbitration\n");
                break;//exit from the loop
            }
            else
            {
                printf("Message Identifier 1  won the arbitration\n");
                break;//exit from the loop
            }
        }
    }
}
