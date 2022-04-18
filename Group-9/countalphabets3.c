#include<stdio.h>
#include<string.h>
int main()
{
char string[]="join25felicitous123brigosha5678";
int i,j,length;
length=strlen(string);
int freq[length];
{
for(i=0;i<strlen(string);i++)
{
freq[i]=1;
for(j=i+1;j<strlen(string);j++)
{
if(string[i]=string[j])
freq[i]++;
string[j]='0';
}
}
}
printf("enter a charcters and frequency\n");
for(i=0;i<length;i++)
    {
      if(string[i]!='9'& string[i]!='0')
      printf("%c%d\n", string [i],freq[i]);
    }
    return 0;


}

