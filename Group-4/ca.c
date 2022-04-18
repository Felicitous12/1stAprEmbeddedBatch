/* NAME:ANBAN , CHANDRASHEKAR
   DATE:18/04/2022
   PURPOSE:WRT A PROGRAM TO COUNT NO.OF ALPHABETS,NUM AND FRQUENCY.
*/

#include<stdio.h>
void main(){
char s[100];
int i,j,b,count=0,n,alpha_c=0,num_c=0;
printf("enter the string");
scanf("%s",s);
for(b=0;s[b];b++);     //find the lenth dummy loop

   printf("%s",s);  //printing string
   printf("\n");    //newline
   for(i=0;s[i];i++)
   {
       if(s[i]>='A' && s[i]<='Z'|| s[i]>='a' && s[i]<='z') //checking alphabets from A to z
       {
           alpha_c++;                   //alphabets for counting
       }
       else if (s[i]>='0' && s[i]<='9')  // checking digits from 0 to 9
            {
                num_c++;              //digits counting
            }
   }
    printf("%d %d\n",alpha_c,num_c);     //printing counts of alphabets and digits
//printf("frequency count");
for(i=0;i<b;i++)      //rotate 0 to size
{
    count=1;    //initialing count=1
    if(s[i])    //condition
    {
        for(j=i+1;j<b;j++)    //check the all elements
        {

            if(s[i]==s[j])  // check both are equal
            {
                count++;     //increament
                s[j]='\0';  //take the value null

            }
        }
    printf("%c %d\n",s[i],count);// print the count values of digits and
    }
}
}
