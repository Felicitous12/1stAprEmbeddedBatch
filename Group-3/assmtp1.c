


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


void Com_PackEngineInformation(unsigned char *Byte_uchar)//creat a function  for engine information
{
	unsigned eng_info=GetEngineRPM();
	Byte_uchar[3u]=GetEngineTemperature();
	Byte_uchar[0u]=0xff&((eng_info)>>8);//using shifting operation
	Byte_uchar[1u]=0x1f&(eng_info);
	Byte_uchar[2u]=0Xff&(eng_info);
	Byte_uchar[4u]=0x0&(eng_info);




}

void Com_PackSteeringInformation(unsigned char *Byte_uchar)//create one function for steeringinformation
	short int str_data=GetSteeringRotation();   // for steering rotation
	Byte_uchar[0u]=0xf&(str_data>>8);           //shifting 8 times
	Byte_uchar[1u]=0xff&str_data;
	Byte_uchar[2u]=0x0&str_data;


}
int main()
{


Com_PackSteeringInformation(G_Msg_SteeringInformation_Byte);  //function call
Com_PackEngineInformation(G_Msg_EngineInformation_Byte);      //
for(int i=0;i<3;i++)
    {

        printf("msg engine informatin byte [%d]=0X%X\n",i,G_Msg_SteeringInformation_Byte[i]);//printing engine information

    }
    for(int i=0;i<5;i++)
    {
        printf("msg steeringinformation byte [[%d]=0X%X\n",i,G_Msg_EngineInformation_Byte[i]);//printing steering information using loop


    }
}
