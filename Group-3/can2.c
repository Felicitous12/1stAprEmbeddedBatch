/*Arunkumar and mahesh
date:21/04/2022
WAP to do arbitration of 2Id
*/

#include<stdio.h>
int main()
{

    int i,j,byte1,byte2;
    printf("enter the first byte\n");// take input from user for 1st byte
    scanf("%x",&byte1);
     for(i=10;i>=0;i--)
        printf("%d",byte1>>i&1);
        printf("\n");
    printf("enter the second byte\n");//take input from user for second byte
    scanf("%x",&byte2);
 for(i=10;i>=0;i--) //
        printf("%d",byte2>>i&1);
        printf("\n");
for(i=10;i>=0;i--)
{

    if((byte1>>i&1)!=(byte2>>i&1))//comparing 2 bytes in if loop
        {
        if((byte1>>i&1))
     {
         printf("arb2 wins\n");
           // return;
           break;
     }
     else{
        printf("arb1 wins\n");
           // return;
           break;
     }
}
}
}
