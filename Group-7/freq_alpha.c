#include<stdio.h>
#include<string.h>
int main()
{
    int alp_cnt=0,num_cnt=0,i,j,cnt=0;
    char str[50];
    printf("enter the characters: \n");
    gets(str);
    int len=strlen(str);
    printf("%d\n",len);
    for(i=0;str[i];i++)
    {
    if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
    {
        alp_cnt++;
    }
    else if(str[i]>='1' && str[i]<='9')
    {
        num_cnt++;
    }
    }
    printf("alp_cnt=%d\n",alp_cnt);
    printf("num_cnt=%d\n",num_cnt);
    for(i=0;str[i]!='\0';i++)
    {
        cnt=0;
        if(i==0)
        {

           if(str[i]==str[i-1])
            i++;
        }

        for(j=i+1;str[j];j++)
        {
            if(str[i]==str[j])
               cnt++;
        }
        printf("%d\n",cnt);

    }
}
