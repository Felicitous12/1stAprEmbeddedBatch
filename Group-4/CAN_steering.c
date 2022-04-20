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
    int i;
	/*Type your code here*/
	unsigned int Eng_info=GetEngineRPM();    //function call
	Byte_uchar[0u]=0x1f&((Eng_info)>>8);      //right shifting 8 times
	Byte_uchar[1u]=0xff&Eng_info;             //ff is (&) with eng_info
	Byte_uchar[2u]=0x0&Eng_info;
	Byte_uchar[3u]=0xff&GetEngineTemperature();   //ff is (&) with func call of getengine tempr
	Byte_uchar[4u]=0x0&Eng_info;
    for(i=0;i<5;i++){                            // rotating loop for 5 times from 0 to 4 then we byte_uchar values
        printf("[%d]=%d\n",i,Byte_uchar[i]);     // printing
    }
}

void Com_PackSteeringInformation(unsigned char *Byte_uchar)
{
    int i;
	/*Type your code here*/
	unsigned int G_Str_SteeringAngle_sint=GetSteeringRotation(); //storing the streeing angle in variable
	Byte_uchar[0u]=0xf&((G_Str_SteeringAngle_sint)>>8); //push the msb to lsb
	Byte_uchar[1u]=0xff&G_Str_SteeringAngle_sint ; //storing the streeingangle
	Byte_uchar[2u]=0x0&G_Str_SteeringAngle_sint;  //reserved bit
	for(i=0;i<3;i++){                                //rotating loop 3 times
    printf("[%d]=%d\n",i,Byte_uchar[i]);             //printing
	}
}
int main()
{
     Com_PackEngineInformation(G_Msg_EngineInformation_Byte); //calling the func in the main

     Com_PackSteeringInformation(G_Msg_EngineInformation_Byte);  //calling the func in the main

}

