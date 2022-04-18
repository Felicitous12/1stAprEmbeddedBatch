#include<stdio.h>
void main()
{
    char str[35];                                                                          //declaration of string
    printf("Enter the string\n");
    scanf("%[^\n]",str);                                                                   //scanning the data in string type with space
    int size=sizeof(str)/sizeof(str[0]);                                                   //finding the size of string
    printf("%d\n",size);                                                                   //printing the size of string
    int i,j,k,count_alp=0,count_digits=0,count_particular_str;                             //declaration of variables

    /* LOGIC FOR COUNTING THE ALPHABETS AND NUMBERS */

    for(i=0;str[i];i++)                                                                     //for each iteration of string starting from base address rotate till end of strings is reached
    {
        if(str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z')                        //if() condition for checking the given string is alphabetical character or not, if present count the number of character
        {
            count_alp++;                                                                    //counting the number of alphabets (count_alp)
        }
        else if(str[i]>='0' && str[i]<='9')                                                 //else if condition for checking the given string is digits or not, if present count the number of digits
        {
            count_digits++;                                                                 //counting the number of digits (count_digits)
        }
    }
    printf("ALPHABETS=%d  NUMBERS=%d\n",count_alp,count_digits);                            //printing the count of character (count_alp) and digits (count_digits)

    /* checking the frequency of particular character and digits in the given string */

    for(i=0;str[i];i++)                                                                     //for each iteration of string starting from base address rotate till end of strings is reached
    {
        for(j=i+1,count_particular_str=1;str[j];j++)                                        //for each iteration of string starting from previous iterate value + 1 (i.e, i + 1 ), initializing count (count_particular_str=1) and counting particular value, and rotate till end of strings is reached
        {
            if(str[i]==str[j])                                                              // comparing previous two iterations ( i and j )
            {
                count_particular_str++;                                                     //counting compared data
                for(k=j+1;str[k];k++)                                                       //for each iteration of string starting from previous iterate value + 1 ( i.e, j + 1 ), and rotate till end of strings is reached
                    str[k-1]=str[k];                                                        //deleting particular repeated value and shifting the next value to the deleted address
                    str[k-1]=str[k];                                                        //storing the last value in the previous address
                j--;                                                                        // decrementing the size of j string because deleting the particular value
            }
        }
     printf("%c is repeated %d times\n",str[i],count_particular_str);                       // printing the number of times value that has been repeated
    }
}
