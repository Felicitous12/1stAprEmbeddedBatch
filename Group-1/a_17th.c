/*
Authors Name : Sharada , Siva
Date : 17/04/2022
Purpose : Write a Program to count number of alphabets, numbers and frequency of alphabets, numbers in a given input
*/
#include<stdio.h>
void main()
{
    int alpha_count = 0, number_count = 0, frequency = 0, length = 0, i = 0, j = 0;//initialization of variables
    char str[100]="JOIN25FELICITOUS123BRIGOSHA5678";//assign the string to the character array

    //to count the the number of alphabets, numeric characters
    for(int i=0;str[i] != '\0';i++)//iterate till null character
    {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') )//condition checks for alphabets
                alpha_count++;//increment count
        else if(str[i] >= '0' && str[i] <= '9')//condition checks for numeric characters
            number_count++; //increment count
    }
    printf("Count of alphabets : %d\n",alpha_count); //display the count
    printf("Count of numeric characters : %d\n",number_count);//display the count
    length = alpha_count + number_count; //to find string length

    //to find frequency of characters
    for(i = 0;i < length ;i++)//iterates over the length
    {
        frequency = 1; //assign 1 to the frequency
        if(str[i])//condition checks for non null character
        {
            for(j = i + 1 ; j < length ;j++) // iterate over length
            {
                if(str[i] == str[j]) //compare the characters

                   {
                       frequency++;//increment count
                       str[j] = '\0';//null character is added
                   }
            }
            printf("Frequency of the character %c is %d\n",str[i],frequency);
        }
    }




}
