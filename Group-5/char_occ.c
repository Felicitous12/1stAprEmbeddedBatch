/*
Name:- Manish & Vishal
Date:- 18/04/2022
WAP to calculate the no of alphabets and digit,
and the display the no of occurance of all characters.
*/
#include <stdio.h>
#include<string.h>

int main()
{
    int i=0,j=0,cnt=0,alp=0,num=0,k=0,f=0;//initialising the local variables
    char ch,str[200];//declaring the size of string
    printf("enter string:-  ");
    /* if i use fgets -> '\n' considered as a last character and after printing
    count of '\n' program is terminating */
    //fgets(str,200,stdin);//getting input string
    gets(str);
    puts(str);// dangerous to use gets()
    for(i=0; str[i]; i++)//for loop for calculating the alphabets and digits
    {
        if((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122))
        alp++;
        if(str[i]>=48&&str[i]<=57)
        num++;

    }
    printf("total alphabets are : %d\nTotal digits are : %d\n",alp,num);
// Below logic is to calculate and print the no of occorance of each characters
    for(i=0; str[i]; i++)//for itiration
    {
        cnt=0;
        f=0;
        for(j=i; str[j]; j++)// for loop for calculate occorance
            {
                for(k=0; k<i; k++)//for loop for checking whether this character already printed or not
                {
                    if(str[k]==str[i])
                    f=1;
                }
                if(f==1)
                {
                    f=0;
                    goto label;// use goto statement for skipping 1 itiration of outer for loop
                }

                if(str[i]==str[j])
                {
                    ch=str[i];
                    cnt++;
                }
            }
            //if(ch!='\n')//found bug (\n) thats why i am writing this condition
            printf("'%c' occour %d times\n",ch,cnt);
            label:;
    }
    return 0;
}
