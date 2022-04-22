/* NAME: ANBAN,CHANDRASHEKAR
   DATE: 22/04/2022
*/

#include<stdio.h>
void arb_std(int,int);
void arb_ext1(int,int);
void main()
{
    int arb1,arb2,ch;    //declaration of variables
    printf("enter the arb1\n"); //entering the arbitration 1st
    scanf("%x",&arb1);          //reading purpose
     printf("enter the arb2\n"); //entering the arbitration 2nd
    scanf("%x",&arb2);           //scanning
     printf("enter the ch\n");   //entering the choice
    scanf("%d",&ch);
    switch(ch)                  // using switch case for choice
    {
        case 1:printf("stand_arb\n"); //if switch case is true it will print or if it is false it will for 2nd
                arb_std(arb1,arb2);   // func call
                break;
        case 2:printf("ext1_arb\n"); // print purpose
                arb_ext1(arb1,arb2); //func call
                break;
        default:printf("wrong");   //default condition, if entered choice is wrong it will execute

}
}
void arb_std(int arb1,int arb2)
{
    int i;
    printf("arb1\n");
    for(i=10;i>=0;i--)
        printf("%x",(arb1>>i)&1);
    printf("\n");
    printf("arb2\n");
    for(i=10;i>=0;i--)
        printf("%x",(arb2>>i)&1);

    for(i=10;i>=0;i--)
        if(((arb1>>i)&0x01)!=((arb2>>i)&0x01))
        {
            if(((arb1>>i)&0x01))
            {
                printf("2nd stand_arb wins\n");
                break;
            }
            else{
                printf("1st stand_arb wins\n");
                break;
            }
        }
    }
    void arb_ext1(int arb1,int arb2)
    {
        int i;
   printf("arb1\n");
    for(i=28;i>=0;i--)
        printf("%x",(arb1>>i)&1);
    printf("\n");
    printf("arb2\n");
    for(i=28;i>=0;i--)
        printf("%x",(arb2>>i)&1);
        printf("\n");
    for(i=28;i>=0;i--)
    {
        if(((arb1>>i)&0x01)!=((arb2>>i)&0x01))
        {
            if(((arb1>>i)&0x01))
            {
                printf("2nd ex1_arb wins\n");
                break;
            }
            else{
                printf("1st ext1_arb wins\n");
                break;
            }
        }
    }


    }




