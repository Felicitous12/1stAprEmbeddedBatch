#include<stdio.h>
int main()
{
   int a,b,c;
printf("enter the byte");    //entering the byte value
scanf("%d",&a);              //scanning purpose
for(b=11;b>=0;b--)           //rotating for 11 times
    printf("%d ",a>>b&1);    //printing in the bit values
    printf("\n");            // new line
    printf("enter the 2nd byte");  //entering 2nd byte value
scanf("%d",&c);                   //scanning
for(b=11;b>=0;b--)              // rotating up to 11 times
    printf("%d ",c>>b&1);      //printing in the bit values
    printf("\n");            //for new line
for(b=11;b>=0;b--)           // rotating up to 11 times
{
if((a>>b&1)!=(c>>b&1))      //comparing bits

    if(a>>b&1){
    printf("arbitration 2nd wins");

}
else
    printf("arbitration 1st wins");
}
}

