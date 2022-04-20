
/*
Author name:yugadharshini,kathirvannan
Date :20-04-2022
Purpose: getting streeing and engine info storing in byte and arranging in bit values*/




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

void main()
{
    Com_PackEngineInformation(G_Msg_EngineInformation_Byte);//call the function and passing engine info
    Com_PackSteeringInformation(G_Msg_SteeringInformation_Byte);//call the function and passing steering info
}
void Com_PackEngineInformation(unsigned char *Byte_uchar)
{
    /*Type your code here*/
	//Byte_uchar=&G_Msg_EngineInformation_Byte;
    G_Msg_EngineInformation_Byte[0]=0x1f&(G_Eng_EngineRpm_uint>>8);//pushing last 4 byte values using right shift operator in array
    G_Msg_EngineInformation_Byte[1]=0xff&(G_Eng_EngineRpm_uint);//storing the 8 bits from LSB in the array
    G_Msg_EngineInformation_Byte[2]=0x00;                       //reserved for the future purpose
    G_Msg_EngineInformation_Byte[3]=( G_Eng_EngineTemperature_uchar);//storing engine temperature binary value in array

    printf("EngineInformation\n");
    for(int i =0;i<5;i++)           //iterating for byte array size times
    {
        printf("Byte[%d]=%d",i,Byte_uchar[i]);     //printing value stored in array
        for(int j=7;j>=0;j--)                      //iterating for the binary value to print
        printf(" %d ",Byte_uchar[i]>>j&0x01);      //printing the binary of value using exp
        printf("\n");
    }

}

void Com_PackSteeringInformation(unsigned char *Byte_uchar)
{
	/*Type your code here*/
	//Byte_uchar=&G_Msg_SteeringInformation_Byte;
	G_Msg_SteeringInformation_Byte[0]=0xf&(G_Str_SteeringAngle_sint >>8); //pushing last 4 byte values using right shift operator in array
	G_Msg_SteeringInformation_Byte[1]=0xff&(G_Str_SteeringAngle_sint );//storing the 8 bits from LSB in the array

    printf("SteeringInformation\n");

    for(int i =0;i<3;i++)             //iterating for byte array size times
    {
        printf("Byte[%d]=%d",i,Byte_uchar[i]);      //printing value stored in array
        for(int j=7;j>=0;j--)                       //iterating for the binary value to print
        printf(" %d ",Byte_uchar[i]>>j&0x01);       //printing the binary of value using exp
        printf("\n");
    }

}

