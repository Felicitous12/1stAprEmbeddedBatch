/*
Author  : Abhishek, Naresh.
Date    : 20/04/2022
purpose : for getting engine information

*/

#include<stdio.h>   // header file

///////////////////////////////////////// INPUT //////////////////////////////////////////////////////////////
/*Information*/
unsigned char G_Eng_EngineTemperature_uchar = 50u ;
unsigned int G_Eng_EngineRpm_uint = 1000u;
signed int G_Str_SteeringAngle_sint = -60;

/********************** DO NOT MODIFY BELOW SECTION **********************************************************/

/*Message*/
unsigned char G_Msg_SteeringInformation_Byte[3u];
unsigned char G_Msg_EngineInformation_Byte[5u];

unsigned char GetEngineTemperature(void);
unsigned int GetEngineRPM(void);
signed int GetSteeringRotation(void);



unsigned char GetEngineTemperature(void)
{
	/*Every increment in LSB value increases 1 deg (i.e. return value 1 represents 1deg */
	/*Range of output is 0deg to 255deg C*/
	return G_Eng_EngineTemperature_uchar;
}

unsigned int GetEngineRPM(void)
{
	/*Every increment in LSB value increases 1 rpm (i.e. return value 1 represents 1rpm */

	/*Range of output is 0 rpm to 8192 rpm*/
	return G_Eng_EngineRpm_uint;

}

signed int GetSteeringRotation(void)
{
	/*Every increment in LSB value increases 1 deg (i.e. return value 1 represents 1deg and return value -1 represents -1 deg */
	/*Range of output is -720 deg to +720 deg angle */
	return G_Str_SteeringAngle_sint;
}

/********************** DO NOT MODIFY UNTILL HERE**********************************************************/

/* function definition*/
void Com_PackEngineInformation(unsigned char *Byte_uchar) // engine information function definition starts here
{
	/*Type your code here*/
    unsigned char eng_temp=GetEngineTemperature(); // Here we calling engine temperature function
    unsigned int eng_rpm=GetEngineRPM();    // Here we calling engine rpm function
    Byte_uchar[0u]=0X1f & (eng_rpm>>8);     // to store 5 bits of MSB in engine_rpm index 0, for that purpose to right shift 8 times and performing logic AND operation to get output
    Byte_uchar[1u]=0xff & (eng_rpm);        // to store remaining 8 bits in engine_rpm index 1,for that purpose perform logic AND operation
    Byte_uchar[2u]=0x00 & (eng_rpm);       // we allocate zero bits because not necessary, that is future purpose
    Byte_uchar[3u]=0xff & (eng_temp);      // Here to store 8 bits of engine temperature and perform logic AND operation
    Byte_uchar[4u]=0x00 & (eng_temp);      //we allocate zero bits because not necessary, that is future purpose

/* Here to print the Engine information*/

    for(int i=0;i<5;i++)                   // i loop iterates fro zero index up to less than index 5
    {
        printf("G_Eng_Engineinformation_Byte[%d]=%d \n",i,Byte_uchar[i]); //to print engine information along with index value
    }
}
/* function definition*/
void Com_PackSteeringInformation(unsigned char *Byte_uchar)  //steering information function starts here
{
	/*Type your code here*/
	short int str_angle=GetSteeringRotation();   // Here we calling engine steering function
	Byte_uchar[0u]=0xf & (str_angle>>8);        // Here to store the steering angle information of 4 MSB bits and perform AND logic operation
	Byte_uchar[1u]=0xff & (str_angle);          // to store remaining 8 bits in steering angle informatio index 1,for that purpose perform logic AND operation
	Byte_uchar[2u]=0x0 & (str_angle);           //we allocate zero bits because not necessary, that is future purpose

/* Here to print the Steering information */

	for(int i=0;i<3;i++)   // Here i loop iterates from zero index to less than index 3
    {
        printf("G_Msg_SteeringInformation_Byte[%d] =%d\n",i,Byte_uchar[i]); //to print steering information along with index value
    }
}

/* Here main function starts*/
int main()
{
    Com_PackSteeringInformation(G_Msg_SteeringInformation_Byte); //Here we are calling the steering information function to get the steering information

    Com_PackEngineInformation(G_Msg_EngineInformation_Byte);     //Here we are calling the engine information function to get the engine information
}



