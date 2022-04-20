#include<stdio.h>
///////////////////////////////////////// INPUT //////////////////////////////////////////////////////////////
/*Information*/
unsigned char G_Eng_EngineTemperature_uchar = 50u ;
unsigned int G_Eng_EngineRpm_uint = 1000u;
signed int G_Str_SteeringAngle_sint = -60;



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



void main()
{
    int i, j;//declaration of variables
    Com_PackSteeringInformation(G_Msg_SteeringInformation_Byte);//function call to arrange the steering angle information
    Com_PackEngineInformation(G_Msg_EngineInformation_Byte);//function call to arrange engine information
    printf("Steering Information\n");
    for(i = 0;i < 3;i++)//iterate over number of array elements
    {
        printf("Byte[%d] = ",i);
        for(j=7;j>=0;j--)//iterate over number of bits to print the values bit by bit
           printf("%d ",G_Msg_SteeringInformation_Byte[i] >> j & 0x01);
        printf("\n");
    }
         printf("EngineInformation\n");
    for(i = 0;i<5;i++)//iterate over number of array elements
    {
        printf("Byte[%d] = ",i);
        for(j=7;j>=0;j--)//iterate over number of bits to print the values bit by bit
            printf("%d ",G_Msg_EngineInformation_Byte[i] >> j & 0x01);
        printf("\n");
    }

}
void Com_PackEngineInformation(unsigned char *Byte_uchar)
{
    unsigned int rpm = GetEngineRPM();//function is called and value is returned
    unsigned char temp = GetEngineTemperature();//function is called and value is returned

	 Byte_uchar[0] = 0x1f & (rpm >> 8);//to fetch bit 4 to bit 0
	 Byte_uchar[1] = 0xff & rpm;//to fetch bit 7 to bit 0
	 Byte_uchar[3] = 0xff & temp;//to fetch bit 7 to bit 0

}

void Com_PackSteeringInformation(unsigned char *Byte_uchar)
{
    signed int angle = GetSteeringRotation();//function is called and value is returned
	Byte_uchar[0] = 0x0f & ( angle >> 8);//to fetch bit 3 to bit 0
	Byte_uchar[1] = 0xff & angle;//to fetch bit 7 to bit 0


}

