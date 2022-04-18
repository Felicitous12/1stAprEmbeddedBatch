/*
Author name:yugadharshini,kathirvannan
Date :17-04-2022
Purpose:Write to count the alphabet and number and frequency of the alphabet and number in a given i/p
*/#include<stdio.h>

void main()
{
    char str[50]="JOIN25FELICITOUS123BRIGOSHA5678";
    int C=0;              // for  counting the alpha
    int D=0;              //for  counting the numbers
    int i,j,freq,b ;
    //scanf("%[^\n]",str);
    for( b=0;str[b];b++);   // to find the length for str
    printf("%d\n",b);       // printing the length of str

    for (i=0;str[i];i++)     //iterating for whole string
     {
        if(str[i]>='A' && str[i]<='Z'|| str[i]>='a' && str[i]<='z') //comparing string value with each character
        {
            C++;  //increment  the alpha count
        }
       else if(str[i]>='0' && str[i]<='9')  // comparing string value with numbers
       {
           D++;  //increses the number count
       }

    }
    printf("%d is count of alphabets\n%d is count of number\n",C,D); //prints the alpha count and number count
    for (i=0 ; i<b ; i++)  //rotating whole array
    {
        freq=1;              //intialize count as 1
        if(str[i])          // check condition true
            {
                for(j =i+1 ; j<b ; j++) //iterating the loop for array times
                    {
                        if(str[i]==str[j])  //checking  both string values are equal
                          {
                               freq++;  //increment the count value
                               str[j]='\0';  // then take that value as null character
                          }
                    }
                printf("frequency of %c is %d\n",str[i],freq); //prints the count values of each character
            }

    }

}

