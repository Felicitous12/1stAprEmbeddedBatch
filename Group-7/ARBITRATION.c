/*
author : Abhishek,Naresh
date: 21/04/2022
purpose: check the bit arbitration
*/
#include<stdio.h>                        // header file

//function definition

int arbitration(int id_1,int id_2)      //function definition starts here
{
    int i;                             //initialize i variable
    for(i=10;i>=0;i--)                 //i iterates from 10 to 0
    {
        if((id_1>>i)&1 != (id_2>>i)&1) //comparing bits of id_1 and id_2 if the two bits are not same it enters the loop
        {
            if(((id_1>>i)&1)>((id_2>>i)&1)) //comparing bits of id_1 and id_2 if 1st bit is greater than the 2nd bit, it prints the second id
            {
                printf("id_2 win");        //print the id_2
                break;                    //break for to come out of the loop
            }
            else                        //else for false condition
        {
            printf("id_1 win");            //print the id_1
            break;                         //break for to come out of the loop
        }
        }


    }

}

/* main function starts here */
int main()
{
    int id_1,id_2,n3,bit;                        //intialize the variables of  id_1,id_2,n3 ,bit;
    printf("enter the 1st value of arbitration\n");  //enter the 1st id_1 value
    scanf("%x",&id_1);                               //scanning the id_1 value

//  print binary format of id_1

    for(bit=10;bit>=0;bit--)                           //i iterates from 10 to 0
    {
    printf("%d",id_1>>bit&1);                          //print the binary format
    }
    printf("\n");                                       //print new line
    printf("enter the 2nd vale of aribtraion\n");       //enter the 1st id_2 value
     scanf("%x",&id_2);                                 //scanning the id_2 value

  //  print binary format of id_2

    for(bit=10;bit>=0;bit--)                          //   i iterates from 10 to 0
    {
    printf("%d",id_2>>bit&1);                       //print the binary format
    }
    printf("\n");                                  //print new line
    arbitration(id_1,id_2);                        //function callling
}
