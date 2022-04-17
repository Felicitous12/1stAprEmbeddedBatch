/* Author Name: G.Naresh
    Date: 17/04/2022
    purpose: c program */

    // WAP to count the no of alphabets and numbers also frequency of each character
    #include<stdio.h>
    #include<string.h>
    int main()
    {
        int alp_cnt=0,num_cnt=0,i,j,k,cnt;
        char str[50];
        printf("enter the characters:\n");
        scanf("%s",str);
        for(i=0;str[i]!='\0';i++)
        {
            if((str[i]>='a' && str[i]<='z') || str[i]>='A' && str[i]<='Z')
            {
                alp_cnt++;
            }
            else if(str[i]>='0' && str[i]<='9')
            {
                num_cnt++;
            }
            else{}

        }
        printf("alp_cnt= %d\n",alp_cnt);
        printf("num_cnt= %d\n",num_cnt);

        for(i=0;str[i]!='\0';i++)
        {
            cnt=1;
            for(j=i+1;str[j]!='\0';j++)
            {
                if(str[i]==str[j])
                    cnt++;
                for(k=0;str[k]!='\0';k++)
                    str[k]=str[k+1];
                //j;
            }
            printf("%c repeats %d times\n",str[i],cnt);
        }
    }
