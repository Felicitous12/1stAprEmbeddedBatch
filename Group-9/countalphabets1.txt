/*Author name:Naveen ; lakshmi;
date : 18-04-2022
purpose : write a program to count alphabets and numbers of frequency of given input*/
#include<stdio.h>
#include<string.h>
void main()
{
    char s[100];                                    //declaring a string
    int i,j,b,count1=0,count2=0,count;
   printf("enter the string \n");                   //enter the string
   scanf("%s",s);                                   //read the string
   for(b=0;s[b];b++);                               //for loop to get the string
   printf("string  : %d\n",b);                                //print the string
    for(i=0;s[i];i++)                               //for loop for rotating a string
    {
        if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z') //if condition to check alphabets
        {
            count1++;                                   //character increment
        }
        else if(s[i]>='0'&&s[i]<='9')                    //if condition to check number
        {
            count2++;                                     //number increment
        }
    }
        printf("no.of.characters : %d\nno.of.numbers : %d\n",count1,count2);                // print the total number and character
        for(i=0;i<b;i++)
        {
            count=1;
            if(s[i]!=0)                                     //if condition to rotate end of the string
            {
            for(j=i+1;j<b;j++)
            {
                if(s[i]==s[j])                               // if condition to check same character or number
                {
                    count++;
                    s[j]='\0';                                 //end of the string
                }

            }

    printf("frequency of %c is %d\n",s[i],count);             //print the frequency of the string
        }
        }

}



