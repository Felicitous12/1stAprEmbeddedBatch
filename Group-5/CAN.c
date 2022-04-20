/*
Name:- Manish and Vishal
Date:- 20/04/2022
assignment no. 1
*/
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
#include<stdio.h>

void Com_PackEngineInformation(unsigned char *Byte_uchar)
{
	/*Type your code here*/
	unsigned eng_info=GetEngineRPM();//storing the data in local variable directly by calling getengineRPM
	Byte_uchar[3u]=0xff&GetEngineTemperature();//directly storing information by calling and bitwise anding operator
	Byte_uchar[0u]=0x1f&((eng_info)>>8);//storing bit 8th to 12th with the help of shifting and bitwise anding opeator
    Byte_uchar[1u]=0xff&eng_info;//storing bit 0 to 7 by bitwise anding operator
    Byte_uchar[2u]=0x0;//clearing
    Byte_uchar[4u]=0x0;//clearing

}

void Com_PackSteeringInformation(unsigned char *Byte_uchar)
{
	/*Type your code here*/
	  short int str_data=GetSteeringRotation();//storing the data in local variable directly by calling getsteeringrotation
	Byte_uchar[0u]=0xf&(str_data>>8);//storing bit 8th to 11th with the help of shifting and bitwise anding opeator
	Byte_uchar[1u]=0xff&str_data;//storing bit 0 to 7 by bitwise anding operator
	Byte_uchar[2u]=0x0&str_data;//clearing the data by anding with 0

}
int main()
{
    Com_PackSteeringInformation(G_Msg_SteeringInformation_Byte);
    Com_PackEngineInformation(G_Msg_EngineInformation_Byte);
    for(int i=0;i<3;i++)// for printing streeninginformation array
    {
        printf("G_Msg_SteeringInformation_Byte[%d]=0X%X\n",i,G_Msg_SteeringInformation_Byte[i]);
    }
     for(int i=0;i<5;i++)//for printing EngineInformation
    {
        printf("G_Msg_EngineInformation_Byte[%d]=0X%X\n",i,G_Msg_EngineInformation_Byte[i]);
    }
    return 0;
}

