/*
Author : Siva, Sharada
Date : 21-04-2022
Purpose : Program to perform arbitration of identifiers of standard frame or extended frame
*/

#include<stdio.h>//to print functions including stdio.h header file
void function( int arg1, int arg2, int bit);//function declaration
void main()//compiler start with main
{

    //declaration of variables
    int i,j;
    int arg1, arg2;
    int choice;
    printf("1. Standard Frame\n2. Extended Frame\n3. First argument is Standard Frame Second Argument is Extended Frame\n4. First argument is Extended Frame Second Argument is Standard Frame\nEnter the choice : ");
    scanf("%d",&choice);
    //read the inputs
    printf("Enter the Message Identifier 1 : ");
    scanf("%x",&arg1);
    printf("Enter the Message Identifier 2  : ");
    scanf("%x",&arg2);
    switch(choice)//check the given choice
    {
    case 1 ://case label
        printf("Entered both as a Standard Frame\n");//here enter the both standard frame format
        function(arg1&0x7ff,arg2&0x7ff,10);//function call it goes the called function
        break;
    case 2 ://case label
        printf("Entered both as a Extended Frame\n");
        function(arg1&0x1fffffff,arg2&0x1fffffff,28);//function call it will goes to called function
        break;
    case 3 :
        printf("Entered first frame as a Standard Frame and another frame as a Extended Frame\n");
        printf("Message Identifier 1  won the arbitration\n");
        break;
    case 4 :
        printf("Entered first frame as a Extended Frame and another frame as a Standard Frame\n");
        printf("Message Identifier 2  won the arbitration\n");
        break;
    }

}
void function( int arg1, int arg2, int bit)//function definition
{
    for(int i = bit ; i >= 0 ; i--)//by using the for loop to traverse  the loop until bit is equal to zero
    {
        if(((arg1>>i)&0x01)!=((arg2>>i)&0x01))//here check the if condition , performing both a arguments right shift with index and and logic operation
        {
            if(((arg1>>i)&0x01))//here check the if condition and arguments 1 is right shift with index andlogic with 1
            {
                printf("Message Identifier 2  won the arbitration\n");//print the message
                break;//it will break the loop
            }
            else//if if condition is fail print the else statement
            {
                printf("Message Identifier 1  won the arbitration\n");//print the message
                break;//here break loop
            }
        }
    }

}
