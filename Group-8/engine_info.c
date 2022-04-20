

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


void Com_PackEngineInformation(unsigned char *Byte_uchar)                       // Engine information function definition.
{
	/*Type your code here*/
	unsigned int Eng_info=GetEngineRPM();                                       //GetEngineRPM data is stored in Eng_info variable.
	Byte_uchar[0u]=0x0000001f&((Eng_info)>>8);                                  //Eng_info(i.e.,Engine RPM) data is right shifted by 8 times &(bitwise and) with 0x1F which is stored in message byte 0.
	Byte_uchar[1u]=0x000000ff&Eng_info;                                         //Eng_info(i.e.,Engine RPM) data is &(bitwise and) with 0xFF result is stored in message byte 1.
	Byte_uchar[2u]=0x00000000&Eng_info;                                         //Empty byte for buffer.
	Byte_uchar[3u]=0x000000ff&GetEngineTemperature();                           //Eng_info(i.e.,Engine Temperature) data is &(bitwise and) with 0xFF which is stored in message byte 4.
	Byte_uchar[4u]=0x00000000&Eng_info;                                         //Empty byte for buffer.

    for(int i=0;i<5;i++)                                                        // for loop for 5 iteration.
        {
            printf("Byte_uchar[%d]=%d\n",i,Byte_uchar[i]);                      // printing Engine information byte by byte.
        }
}

void Com_PackSteeringInformation(unsigned char *Byte_uchar)                     //Steering information function definition.
{
	/*Type your code here*/
	unsigned int str_eng=GetSteeringRotation();                                 //GetSteeringRotation data is stored in str_eng variable.
	Byte_uchar[0u]=0x0000000f&((str_eng)>>8);                                   // str_eng(i.e.,Engine steering rotation) data is right shifted by 8 times &(bitwise and) with 0x0F which is stored in message byte 0.
	Byte_uchar[1u]=0x000000ff&(str_eng);                                        // str_eng(i.e.,Engine steering rotation) data is &(bitwise and) with 0xFF result is stored in message byte 1.
	Byte_uchar[2u]=0x00000000&(str_eng);                                        //Empty byte for buffer.

	for(int i=0;i<3;i++)                                                        // for loop for 3 iteration.
        {
            printf("steering_angle[%d]=%d\n",i,Byte_uchar[i]);                  // printing Engine steering information byte by byte.
        }
}
/* main program  */
int main(){
    Com_PackEngineInformation(G_Msg_EngineInformation_Byte);                    //passing the data(i.e.,G_Msg_EngineInformation_Byte) through Com_PackEngineInformation().
    Com_PackSteeringInformation(G_Msg_SteeringInformation_Byte);                //passing the data(i.e.,G_Msg_SteeringInformation_Byte) through Com_PackSteeringInformation().
}



