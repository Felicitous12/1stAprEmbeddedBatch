/*AUTHOR NAME: NAVEEN KUMAR, LAKSHMI
DATE : 20/04/2022
PURPOSE : WRITE A PROGRAM TO FIND   ENGINE INFORMATION AND STEERING INFORMATION */

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


void Com_PackEngineInformation(unsigned char *Byte_uchar)
{
	/*Type your code here*/
	unsigned int Eng_info = GetEngineRPM();                          //getEngineRPM value From Eng_info
	Byte_uchar[0u]=0x0000001f & ((Eng_info)>>8);                    //5 bits storing in byte 0 by right shifting 8 times
	Byte_uchar[1u]=0x000000ff & Eng_info;                          // storing 8 bit data in byte 1
	Byte_uchar[2u]=0x00000000 & Eng_info;                         // extra byte for future application
	Byte_uchar[3u]=0x000000ff & GetEngineTemperature() ;         //storing engine temperature value in byte 3
	Byte_uchar[4u]=0x00000000 & Eng_info;                        // extra byte for future application
	for(int i=0;i<5;i++)                                        // rotating for loops 5 times to get engine information
    {
    printf("Engineinformation[%d]=%d\n",i,Byte_uchar[i]);        // printing the engine information
    }
}

void Com_PackSteeringInformation(unsigned char *Byte_uchar)
{
	/*Type your code here*/
	unsigned int Str_eng = GetSteeringRotation();             //get steering rotation info from str_eng
	Byte_uchar[0u]=0x0000000f & ((Str_eng)>>8);               // 4 bits storing in byte 0 by right shifting 8 times
	Byte_uchar[1u]=0x000000ff & Str_eng;                     //storing 8 bit data in byte 1
	Byte_uchar[2u]=0x00000000 & Str_eng;                     //extra byte for future application
	for(int i=0;i<3;i++)                                     //rotating for loops 3 times to get steering rotation information
    {
    printf("Steeringinformation[%d]=%d\n",i,Byte_uchar[i]);    //printing the steering information
    }

}
int main()
{
    Com_PackEngineInformation(G_Msg_EngineInformation_Byte);      // calling engine information  by pack engine information
    Com_PackSteeringInformation(G_Msg_EngineInformation_Byte);    // calling engine information by steering information
}

