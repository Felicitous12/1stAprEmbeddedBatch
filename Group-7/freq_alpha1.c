/*
author=Abhishek & Naresh
date=18/04/2022
purpose=count how many alphabets and numbers and count freq of num and alphabets
*/



#include<stdio.h>
#include<string.h>
int main()
{
    int alp_cnt=0,num_cnt=0,i,j,k,cnt=0; // initialize alphabet count, number count,count for frequency,and i,j,k for loops
    char str[200]; //array size
    printf("enter the characters: \n"); //taking input as string
    gets(str);    //scaning the input string
    int len=strlen(str); // length of a string
    printf("size of string=%d\n",len);  // prints the length of string
    for(i=0;str[i];i++)  // traversing upto null character using loop
    {
    if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))  //check char a to z and A to Z
    {
        alp_cnt++;                                                     //if alphabet found alp_cnt increment
    }
    else if(str[i]>='0' && str[i]<='9')       //checking num betwen 0 to 9
    {
        num_cnt++;                            //if num found num_cnt incriment
    }
    }
    printf("alp_cnt=%d\n",alp_cnt);  // printing no of alphabets present in the string
    printf("num_cnt=%d\n",num_cnt);  // printing no of numbers present in the string

    for(i=0;i<len;i++) // here i iterates up to less than length of a string
    {
        cnt=1;      // if alphabet or number is found, itself counted as one

        if(str[i])       // here taking each element
        {
           for(j=i+1;j<len;j++)  // j loop iteration starts next to i loop element
           {
                if(str[i]==str[j])     // comparing the two characters
                {
                    cnt++;       // if it appeared more than ones and cnt incriment
                    str[j]='\0';  // ensures that j iterates up to last
                 }
            }
            printf("%c is repeated %d times\n",str[i],cnt); // printing the each character of how many times it is repeated

         }

    }
    return 0;
}
