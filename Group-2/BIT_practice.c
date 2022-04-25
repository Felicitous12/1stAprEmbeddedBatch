#include<stdio.h>
void main()
{
    char num = 0x0f;
    for(int i=7;i>=0;i--)
        printf("%d ",num>>i&1);
    printf("\n");
    num = ((num<<6)|(num>>2));
    for(int i=7;i>=0;i--)
        printf("%d ",num>>i&1);
    printf("\n");

}
