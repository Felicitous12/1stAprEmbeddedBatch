/* name:arunkumar p and mahesh
 date:17/04/2022
 purpose:wap to count the alphabets and digits and frequency of both
 */
#include<stdio.h>
#include<string.h>
int cnt(char s[] );//function prototype

int main()
{

    char s[100];
    int i;
    printf("enter the string\n");//compile time providing input
    scanf("%s",s);
    cnt(s);
return 0;
}
int cnt(char s[50]) //function calling
{
    int i,j,c1=0,c2=0,count=0;
    int l=strlen(s);//string length
    for(i=0;i<l;i++)
    {
        if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122 ) //counting alphabets using ascii
        {

            c1++;
        }

        else if(s[i]>=48 && s[i]<=57)// counting  digits
        {
        c2++;
        }
    }
        printf("nbr of digits %d\n",c2);//printing digits
        printf("nbr of alpha %d\n",c1);//printng alphabets



    for(i=0;i<l;i++) //finding the frequency
    {
        count=1;
        if(s[i])
        {

        for(j=i+1;j<l;j++)
        {
            if(s[i]==s[j])
            {
                count++;
                s[j]='\0';
            }
        }

    printf("frqucy of %c is %d times \n",s[i],count );//printing the frequency
        }
}
}


