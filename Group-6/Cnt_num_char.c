#include<stdio.h>

int print_rep(char str[])//function definiton for repeated characters and numbers in a given string
{
    int cnt=0,i,j,k;//intiallizing i,j,k
    char ch;
    for(i=0;str[i];i++)// for rotating the inner for loop upto NULL
    {
        cnt=0;//intiallizing the cnt for counting repeated characters
        int flag=0;//taking flag for repeated characters
        for(j=i;str[j];j++)//comparing the each char upto end of the string
        {
           for(k=0;k<i;k++)//it is checking if char is already printed or not
           {
               if(str[k]==str[i])//if both char will be same
                flag=1;// flag will be 1
           }
           if(flag==1)
           {
               flag=0;
               goto label;
           }
           if(str[i]==str[j])//now checking that both char are same or not
           {
               ch=str[i];//if same, then it stores in ch
               cnt++;//then same means cnt will incrtements
           }
    }
printf("%c character repeated=%d times\n",ch,cnt);//printing that char and number repated how many times
label:;
}
}


int main()
{
    int cnt1=0,i,cnt2=0;//intiallizing cnt1 cnt2 for counting purpose
    char str[50];//taking string from user
    printf("enter a string:");//user input
    gets(str);//collecting string


    for(i=0;str[i];i++)//for traversing the string upto NULL.
    {


    if((str[i]>='A'&& str[i]<='z'|| str[i]>='a'&& str[i]<='z'))//if any char peresent in the given string, the count will be incremented

        cnt1++;


    }
    printf("no.of characters=%d\n",cnt1);//printing no.of characters will be present in the string

    for(i=0;str[i];i++)//for string upto NULL
    {
         if(str[i]>='0'&& str[i]<='9')//if number is present in thr given string count will be increments
           cnt2++;
    }


    printf("no.of numbers=%d\n",cnt2);//printing the number of numbers
     print_rep(str);//function call for repeated chars and numbers

}






