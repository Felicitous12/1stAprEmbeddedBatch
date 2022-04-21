/*
Author: Manish And Vishal
Date:21/04/2022
Description: WAP for arbitration of two frame id's
*/
#include<stdio.h>                                   //including header file
void check_arb(unsigned int id1,unsigned int id2)   // defining the function check arbitration
{
    if(id2>id1)                                     // checking which id has smaller value.. because if id is small that id will win
        printf("\nid1 0x%x won arbitration\n",id1); //printing the result
    else
         printf("\nid2 0x%x won arbitration\n",id2); //printing the result
}
int main()                                         //starting of main function
{
    unsigned int id1,id2;                          //declaring the required variables
    printf("enter 1st identifier: 0x");            //scanning the first id
    scanf("%x",&id1);
    printf("enter 2nd identifier: 0x");
    scanf("%x",&id2);                              //scanning the 2nd id..
    printf("1st identifier: 0x%x\n2nd identirier: 0x%x\n",id1,id2); //printing the entered ids
     printf("\nid1: ");
    for(int i=15;i>=0;i--)                                         //printing the binary format of the first id
        printf("%d ",(id1>>i)&1);
    printf("\nid2: ");
    for(int i=15;i>=0;i--)                                         //printing the binary format of the second id
        printf("%d ",(id2>>i)&1);

    check_arb(id1&0xffff,id2&0xffff);                              //passing the id values
}
