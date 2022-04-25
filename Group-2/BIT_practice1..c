
/*
Author name:yugadharshini,kathirvannan
Date :20-04-2022
Purpose: getting streeing and engine info storing in byte and arranging in bit values*/



///////////////////////////////////////// INPUT //////////////////////////////////////////////////////////////
/*Information*/
unsigned char G_Eng_EngineTemperature_uchar = 50u ;
unsigned int G_Eng_EngineRpm_uint = 1000u;
signed int G_Str_SteeringAngle_sint = 587u;

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
void main()
{
    Com_PackSteeringInformation(G_Msg_SteeringInformation_Byte);
}
void Com_PackSteeringInformation(unsigned char *Byte_uchar)
{
	//Type your code here
	//Byte_uchar=&G_Msg_SteeringInformation_Byte;
	G_Msg_SteeringInformation_Byte[0]=0x4B& (G_Str_SteeringAngle_sint); //pushing last 4 byte values using right shift operator in array
	G_Msg_SteeringInformation_Byte[1]=0x04& (G_Str_SteeringAngle_sint >>7);//storing the 8 bits from LSB in the array
	G_Msg_SteeringInformation_Byte[2]=0x12 & (G_Str_SteeringAngle_sint >>5); //pushing last 4 byte values using right shift operator in array

    printf("SteeringInformation\n");

    for(int i =0;i<3;i++)             //iterating for byte array size times
    {
        printf("Byte[%d]=%d",i,Byte_uchar[i]);      //printing value stored in array
        for(int j=7;j>=0;j--)                       //iterating for the binary value to print
        printf(" %d ",Byte_uchar[i]>>j&1);       //printing the binary of value using exp
        printf("\n");
    }

}

