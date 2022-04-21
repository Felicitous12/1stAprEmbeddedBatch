/* AUTHORS NAME:ADIL AHMED and DHARANI K R
Date: 21/04/2022
PURPOSE: CHECKING THE ARBITRATION OF TWO VALUES
*/
#include<stdio.h>
int main()
{
int arbitration1,arbitration2;                                      // declaration of two arbitration values
printf("1st arbitration value\n");
scanf("%x",&arbitration1);                                          // scanning the 1st arbitration value in hexa decimal
printf("2nd arbitration value\n");
scanf("%x",&arbitration2);                                          // scanning the 2nd arbitration value in hexa decimal

for(int i=10;i>=0;i--)                                              // for loop for 11 iteration from MSB (i.e., 11th bit ) to LSB (i.e., 0th bit)
 {
    if(((arbitration1>>i)&0x01) != ((arbitration2>>i)&0x01))        // checking each bit one by one if it is not equal if condition is true go for next step
    {
        if(((arbitration1>>i)&0x01))                                // if condition for checking bit by bit of 1st arbitration , if true 2nd arbitration will win
        {
            printf("2nd arbitration wins");                         // printing the 2nd arbitration
            break;                                                  // if encountered value is printed then comes out of the for loop
        }
        else
        {
            printf("1st arbitration wins");                         // printing the 2nd arbitration
            break;                                                  //if encountered value is printed then comes out of the for loop
        }
    }

}

}
