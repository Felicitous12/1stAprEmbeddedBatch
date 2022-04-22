#include<stdio.h>
void standard_arbit(int , int );                                   //prototype of standard_arbit with two arguments and no return type
void Extended_arbit(int , int );                                   //prototype of extended_arbit with two arguments and no return type
void main()
{
int arbitration1,arbitration2,choice;                              // declaration of two arbitration values and one choice variable
printf("1st arbitration value: 0x");
scanf("%x",&arbitration1);                                         // scanning the 1st arbitration value in hexa decimal either it is standard or extended arbitration
printf("2nd arbitration value: 0x");
scanf("%x",&arbitration2);                                         // scanning the 2st arbitration value in hexa decimal either it is standard or extended arbitration
printf("enter the choice\n");
scanf("%d",&choice);                                               // scanning the choice value in decimal to select standard and extended arbitration
switch(choice)                                                     //switch case is for selecting the cases
{
    case 1:printf("both are standard Arbitration Id\n");
           standard_arbit(arbitration1,arbitration2);              //function call of standard arbitration with two arguments and no return type.
           break;                                                  // if encountered value is printed then comes out of the for loop.
    case 2:printf("both are Extended Arbitration Id\n");
           Extended_arbit(arbitration1,arbitration2);              //function call of extended arbitration with two arguments and no return type.
           break;                                                  // if encountered value is printed then comes out of the for loop.
    default:printf("wrong choice\n");
}
}
void standard_arbit(int arbitration1,int arbitration2)
{
    int i;
    printf("arbitration1 Id: ");
    for(i=10;i>=0;i--)                                              //for loop for 11 iteration
    printf("%d ",(arbitration1>>i)&1);                              //printing standard Arbitration 1 value in decimal format
    printf("\n");
    printf("arbitration2 Id: ");
    for(i=10;i>=0;i--)                                              //for loop for 11 iteration
    printf("%d ",(arbitration2>>i)&1);                              //printing Arbitration 2 value in decimal format

    for(int i=10;i>=0;i--)                                          // for loop for 11 iteration from MSB (i.e., 11th bit ) to LSB (i.e., 0th bit)
    {
    if(((arbitration1>>i)&0x01) != ((arbitration2>>i)&0x01))        // checking each bit one by one if it is not equal if condition is true go for next step
    {
        if(((arbitration1>>i)&0x01))                                // if condition for checking bit by bit of 1st arbitration , if true 2nd arbitration will win
        {
            printf("\n2nd standard arbitration wins\n");            // printing the 2nd arbitration
            break;                                                  // if encountered value is printed then comes out of the for loop
        }
        else
        {
            printf("\n1st standard arbitration wins");              // printing the 2nd arbitration
            break;                                                  //if encountered value is printed then comes out of the for loop
        }
    }
    }
}

void Extended_arbit(int arbitration1,int arbitration2)
{
    int i;
    for(i=28;i>=0;i--)                                              //for loop for 11 iteration
    printf("%d ",(arbitration1>>i)&1);                              //printing Extended Arbitration 1 value in decimal format
    printf("\n");

    for(i=28;i>=0;i--)                                              //for loop for 11 iteration
    printf("%d ",(arbitration2>>i)&1);                              //printing Extended Arbitration 1 value in decimal format

    for(int i=28;i>=0;i--)                                          // for loop for 11 iteration from MSB (i.e., 11th bit ) to LSB (i.e., 0th bit)
    {
    if(((arbitration1>>i)&0x01) != ((arbitration2>>i)&0x01))        // checking each bit one by one if it is not equal if condition is true go for next step
    {
        if(((arbitration1>>i)&0x01))                                // if condition for checking bit by bit of 1st arbitration , if true 2nd arbitration will win
        {
            printf("\n2nd Extended arbitration wins\n");            // printing the 2nd Extended arbitration
            break;                                                  // if encountered value is printed then comes out of the for loop
        }
        else
        {
            printf("\n1st Extended arbitration wins");              // printing the 1nd Extended arbitration
            break;                                                  //if encountered value is printed then comes out of the for loop
        }
    }
    }

}
