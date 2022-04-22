/*
Author name:yugadharshini.B,kathirvannan.M
Date :21-04-2022
Purpose: Write a program for arbitration of two frames ,if two can id fun(arg1, arg2),the output : CAN Id that achieved arbitration*/





#include<stdio.h>
void print(int,int);   //function definition
void  arbit_det(int,int);  //function definition
void main()
{
     int byte1,byte2;         //initializing two input byte values
    printf("Enter Message Id 1:\n");  // taking input from the users
    scanf("%x",&byte1);
    printf("Enter Message Id 2:\n");      //initializing two input byte values
    scanf("%x",&byte2);                 // taking input from the users
    printf("Binary format of the bytes\n");
    print(byte1,byte2);                         //call the print function to get binary values
    arbit_det(byte1,byte2);                     //call arbitration func to get identifier that won arbitration

}
void print(int byte1,int byte2)                 //function prototype
{
    for(int j=10;j >= 0; j--)                   //iterating the loop for getting binary values
        printf ("%d ",byte1>>j&1);              //prints binary value of given input
        printf("\n");
    for(int i=10;i >= 0; i--)                   //iterating the loop for getting binary values
        printf ("%d ",byte2>>i&1);               //prints binary value of given input
        printf("\n");
}
void  arbit_det(int byte1,int byte2)                //function prototype
{
    for(int i=10;i>=0;i--)                          //iterating the loop for checking the bit values
    {
        //if(byte1>>i&1== byte2>>i&1)
         if(byte1>>i&1 != byte2>>i&1)               //checks if byte 1 is not equal to byte2 ,condition true enter to next
            {
                if((byte1>>i&1)>(byte2>>i&1))      //checks if byte1 is greater than byte2
                   {
                    printf("CAN Id 2 wins the arbitration\n");          //if conditon true prints the ID that wins
                    break;                          //then breaks the loop
                   }
            }
        else if((byte1>>i&1)<(byte2>>i&1))          //checks if byte1 is less than byte2
                    {
                        printf("CAN Id 1 wins the arbitration\n");       //if conditon true prints the ID that wins
                        break;                       //then breaks the loop
                    }
}
}
