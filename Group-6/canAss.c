

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
	unsigned eng_info=GetEngineRPM();//eng_info collects the information of GetEngineRPM
	Byte_uchar[3u]=GetEngineTemperature();//This byte collects the engine temperature
	Byte_uchar[0u]=0X0000000f&((eng_info)>>8);// Byte0 collects the 5-bit data,
	                                          // eng_info will be right shift by 8 times, the reamining 5-bits are stored in byte0
	Byte_uchar[1u]=0X000000ff&eng_info;//after that the remaining 8=bits are stored in byte1
	Byte_uchar[2u]=0X00000000&eng_info;//this is for future purpose
	Byte_uchar[4u]=0X00000000&eng_info;//this is for future purpose
	for(int i=0;i<5;i++)//printing the engine information
    {
        printf("G_Msg_EngineInformation_Byte[%d]=%d\n",i,Byte_uchar[i]);

    }



}

void Com_PackSteeringInformation(unsigned char *Byte_uchar)
{
	/*Type your code here*/
	short int str_data=GetSteeringRotation();//calling the GetSteeringRotation function that collects the value of -60.
	Byte_uchar[0u]=0X00f&(str_data>>8);//In first byte i.e is byte0 collects 4-bit data
                                        //-60 value will be right shift with 8 times then we get remaning 4-bits will be stored in byte 0
	Byte_uchar[1u]=0X0ff&str_data;//The remaining 8-bits are stored in byte1
	Byte_uchar[2u]=0X000&str_data;//byte2 is used for future purpose
	for(int i=0;i<3;i++)//this for printing the values of steering information
    {
        printf("G_Msg_SteeringInformation_Byte[%d]=%d\n",i,Byte_uchar[i]);
    }
}
    int main()
    {
       Com_PackSteeringInformation(G_Msg_SteeringInformation_Byte);//calling that G_Msg_SteeringInformation_Byte
       Com_PackEngineInformation(G_Msg_EngineInformation_Byte);//calling that G_Msg_EngineInformation_Byte
       return 0;
    }
