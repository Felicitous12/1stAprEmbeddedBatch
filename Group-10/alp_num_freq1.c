/* Author Name: G.Naresh
    Date: 17/04/2022
    purpose: c program */

// WAP to count the no of alphabets and numbers also frequency of each character

    #include<stdio.h>                         // header file stdio.h
    #include<string.h>                        // header file string.h
    int main()
    {
        int alp_cnt=0,num_cnt=0,cnt,i,j,k;    // Intialiaze the alphabet count,number count,frequency of each character count and i,j,k for variables.
        char str[50];                         // Str array of char type which size is 50
        printf("enter the characters:\n");    // Here input string taken from the user
        scanf("%s",str);                      // Scanning the input string,which is a user input
// to verify the each character from the input,that belongs to alphabet or number

        for(i=0;str[i]!='\0';i++)             //Here for loop i iterates from zero index up to last index(NULL character)
        {
            if((str[i]>='a' && str[i]<='z') || str[i]>='A' && str[i]<='Z') // Here searching each character that belongs to alphabet or not
            {
                alp_cnt++;                                           // If it belongs to alphabet,then alphabet count incriment
            }
            else if(str[i]>='0' && str[i]<='9')                     //Here else if loop searching for number
            {
                num_cnt++;                                          //If it belongs to number category,then number count incriment
            }
            else{}                               //It is a optional loop, because when you use if loop else is mandatory also one extra benefit that is we can another special character purpose

        }
        printf("alp_cnt= %d\n",alp_cnt);  // Printing the alphabet count
        printf("num_cnt= %d\n",num_cnt);  // Printing the number count

        for(i=0;str[i]!='\0';i++)              //Here i loop starts from zero index up to last index(NULL character)
        {
                cnt=1;                         // the frequency count is default ie,one because every character itself counted as one time occure
                for(j=i+1;str[j]!='\0';j++)   //Here j loop,it starts next index to the i'th index
                {
                    if(str[i]==str[j])       // Comparing the two characters,if they are belongs same category then frequency count incriment
                    {
                        cnt++;                      // Frequency count incriment
                        for(k=j+1;str[k]!='\0';k++) // Here k loop index starts next to j loop index,and traverse up to the last index(NULL character)
                            str[k-1]=str[k];        //Here k'th index element over writes the previous element,that is j'th index element,which is a second time occured
                        str[k-1]=str[k];            //Here k'th index element over writes the i'th index element
                    }//if ends
                }//for ends

            printf("%c repeats %d times\n",str[i],cnt);    //Here it prints the frequency of each character of how many times it is occured
        }//for ends
        return 0;  // Here program returns zero,that means our code successfully executed
    }//main
