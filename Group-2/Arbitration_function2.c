/*
Author name:yugadharshini.B,kathirvannan.M
Date :21-04-2022
Purpose: Write a program for arbitration of two frames ,if two can id fun(arg1, arg2),the output : CAN Id that achieved arbitration*/



#include<stdio.h>
void print(int,int,int);   //function definition
void  arbit_det(int,int,int);  //function definition
void main()
{
     int byte1,byte2,res;         //initializing two input byte values
    printf("Enter Message Id 1:\n");  // taking input from the users
    scanf("%x",&byte1);
    printf("Enter Message Id 2:\n");      //initializing two input byte values
    scanf("%x",&byte2);   // taking input from the users
    res=func(byte1,byte2);      //function call to get  return value
    switch(res)             //stores the value in switch case
    {
    case 1: printf("Both are Standard message Id\n");       //if one print standard msg
            print(byte1,byte2,10);                          //calls the function to print binary value of input
            arbit_det( byte1, byte2,10);                    //call the function to print the arbitration id
            break;

    case 2: printf("Both are Extended message Id\n");          //if one print extended  msg
            print(byte1,byte2,28);                               //calls the function to print binary value of input
            arbit_det( byte1, byte2,28);                            //call the function to print the arbitration id
            break;

    case 3: arbit_det( byte1, byte2,10);
            break;
    case 4: arbit_det( byte1, byte2,10);
            break;
    }
}


    int func(int byte1,int byte2)
    {
    if(byte1<=0x7ff&& byte2<=0x7ff)             //checks wheather given input is standard
    {
        return 1;                               //condition true returns the value
    }
    else if(byte1<=0x1fffffff && byte2<=0x1fffffff )             //checks wheather given input is extended
    {
        return 2;                                                  //condition true returns the value
    }
    else if(byte1<=0x7ff && byte2<=0x1fffffff )                     //checks wheather given input is extended or standard
    {
        return 3;                                                      //condition true returns the value
    }
    else if(byte1<=0x1fffffff && byte2<=0x7ff )                     //checks wheather given input is extended or standard
    {
        return 4;                                                   //condition true returns the value
    }
    }

void print(int byte1,int byte2,int size)                 //function prototype
{
    printf("Binary format of the bytes\n");
    for(int j=size;j >= 0; j--)                   //iterating the loop for getting binary values
        printf ("%d ",byte1>>j&1);              //prints binary value of given input
        printf("\n");
    for(int i=size;i >= 0; i--)                   //iterating the loop for getting binary values
        printf ("%d ",byte2>>i&1);               //prints binary value of given input
        printf("\n");
}

void  arbit_det(int byte1,int byte2,int size)                //function prototype
{
    for(int i=size;i>=0;i--)                          //iterating the loop for checking the bit values
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

