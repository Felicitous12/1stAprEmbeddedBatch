
/*
  * File: led_bling.c
 * Author: 1) Chandrashekhar 
 *         2) Manish 
 *         3) Naresh
 *         4) Niranjan
 *         5) shiva 
 * Date: 14/05/2022
 * description: This node has to receive different id's and transmit 2 id's 1)0x720 2)0x001,
 * based on different id data we have to set bytes in id 0x720 and transmit . 
 */
// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config OSCS = OFF       // Oscillator System Clock Switch Enable bit (Oscillator system clock switch option is disabled (main oscillator is source))

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bit (Brown-out Reset enabled)
#pragma config BORV = 25        // Brown-out Reset Voltage bits (VBOR set to 2.5V)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 128      // Watchdog Timer Postscale Select bits (1:128)

// CONFIG4L
#pragma config STVR = ON        // Stack Full/Underflow Reset Enable bit (Stack Full/Underflow will cause Reset)
#pragma config LVP = ON         // Low-Voltage ICSP Enable bit (Low-Voltage ICSP enabled)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000200-001FFFh) not code protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0001FFh) not code protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000200-001FFFh) not write protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0001FFh) not write protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000200-001FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from Table Reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from Table Reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0001FFh) not protected from Table Reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

//#define _XTAL_FREQ 20000000
#define ENABLE 1
#define DISABLE 0
static unsigned char DataByte_au8[10u];
static unsigned char DataLength_u8;
static unsigned short int CanId_u16;
unsigned char TestVar_u8;
unsigned long long int speed = 0;
unsigned char data[8];
unsigned char led_delay = 0;
unsigned char Counter701_u8;
unsigned char Counter702_u8;
unsigned char Counter703_u8;
unsigned char Counter704_u8;
unsigned char Counter705_u8;
unsigned char Counter706_u8;

void Can_SetRcvRuleBuf0()
{
    RXM0SIDH = 0X00;    
    RXM0SIDL = 0X00;
     /* ENABLE FILERS *FILTER 0*/
    RXF0SIDH = 0X00;
    RXF0SIDL = 0X20;
         /* ENABLE FILERS *FILTER 0*/
    RXF1SIDH = 0X00;
    RXF1SIDL = 0X20;
    /*ENAB RXF0SIDHLE MASK*/
//    RXM0SIDH = 0X11;    
//    RXM0SIDL = 0X20;
    /* SET RECEICVE MODE FOR BUFFERS */
    RXB0CON = 0X00;
}

void can_tx1(void)
{
    /* transmitting id 0x720 */
    if(TXB0CONbits.TXREQ == 0)
    {
    CANCON = 0x08;
    TXB0CON =0X00;       //Set bits for transmit control register 
    TXB0SIDH =0XE4;      //set transmit buffer for standard identifier high byte 
    TXB0SIDL =0X00;   //set transmit buffer for standard identifier low byte 
    TXB0DLC =0X08;       //set transmit buffer for data length code
    TXB0D0 = data[0];        //data to  transmit 
    TXB0D1 = 0x00;        //data to  transmit 
    TXB0D2 = 0x00;        //data to  transmit 
    TXB0D3 = 0x00;        //data to  transmit
    TXB0D4 = 0x00;        //data to  transmit
    TXB0D5 = data[5];        //data to  transmit
    TXB0D6 = data[6];        //data to  transmit
    TXB0D7 = data[7];        //data to  transmit
    TXB0CONbits.TXREQ =1;          //setting the buffer to transmit
    }
}
void send_tx_for_led_1sec(void)
{
    /*  transmitting id 0x001 to other node for led ON - OFF delay loop*/
    CANCON = 0x08;
    TXB0CON =0X00;       //Set bits for transmit control register 
    TXB0SIDH =0X00;      //set transmit buffer for standard identifier high byte 
    TXB0SIDL =0X20;   //set transmit buffer for standard identifier low byte 
    TXB0DLC =0X08;       //set transmit buffer for data length code
    TXB0D0 = led_delay;        //data to  transmit 
    TXB0D1 = 0;        //data to  transmit 
    TXB0D2 = 0;        //data to  transmit 
    TXB0D3 = 0;        //data to  transmit
    TXB0D4 = 0;        //data to  transmit
    TXB0D5 = 0;        //data to  transmit
    TXB0D6 = 0;        //data to  transmit
    TXB0D7 = 0;        //data to  transmit
    TXB0CONbits.TXREQ =1;          //setting the buffer to transmit
    RXB0CON = 0x00;
    
}

void ReadRxBuffer0(void)
{
    /* storing the received data in char array */
    unsigned short int TempLId_u16;
    unsigned short int TempHId_u16;
    CANCON = ((CANCON & 0xF1) | (CANSTAT & 0x0E));
    TestVar_u8 = CANSTAT;
    
    TempHId_u16 = RXB0SIDH & 0xFF;
    TempLId_u16 = RXB0SIDL & 0xFF;
    CanId_u16 = 0x07FF & ((TempHId_u16<<3)|( TempLId_u16>>5)); /* storing the id of received id in short integer variable */
    

    
    DataLength_u8 = 0x0F & RXB0DLC ;
    DataByte_au8[0] = RXB0D0;
    DataByte_au8[1] = RXB0D1;
    DataByte_au8[2] = RXB0D2;
    DataByte_au8[3] = RXB0D3;
    DataByte_au8[4] = RXB0D4;
    DataByte_au8[5] = RXB0D5;
    DataByte_au8[6] = RXB0D6;
    DataByte_au8[7] = RXB0D7;
    DataByte_au8[8] = RXB0SIDH;
    DataByte_au8[9] = RXB0SIDL;
    RXB0CONbits.RXB0FUL = 0;   
    {
 
        /* checking the requirement with respect to id's*/ 
        {       /* id 0x100 and id 0x555 */
                if(( DataByte_au8[8] == 0x20 && DataByte_au8[9] == 0x00 ) || ( DataByte_au8[8] == 0xAA && DataByte_au8[9] == 0xA0))
                {
                    if(DataByte_au8[8] == 0x20 && DataByte_au8[9] == 0x00)
                    {
                        if((DataByte_au8[6] & 0x03) > 0 )
                        {
                            PORTBbits.RB1 = 1;
                        }
                        else
                        {
                            PORTBbits.RB1 = 0;
                        }
                        if(DataByte_au8[7] & 0x01)
                        {
                            data[7] = 0x03;
                            PORTBbits.RB0 = 1;
                        }
                    }
                    else 
                    {
                         if (DataByte_au8[0] & 0x01)
                        {
                            data[7] = 0x03;
                            PORTBbits.RB0 = 1;
                        }
                    }
                }
                /* id 0x153 and id ox701 */
                else if(( DataByte_au8[8] == 0x2A && DataByte_au8[9] == 0x60 ) || ( DataByte_au8[8] == 0xE0 && DataByte_au8[9] == 0x20))
                {
                    if( DataByte_au8[8] == 0x2A && DataByte_au8[9] == 0x60 )
                    {
                        if(DataByte_au8[0] & 0x01)
                        {
                            data[7] = 0x01;
                            led_delay = 0x02;
                            send_tx_for_led_1sec();
                        }
                    }
                    else 
                    {
                           if(DataByte_au8[4] & 0x01)
                        {
                            data[7] = 0x01;
                            led_delay = 0x02;
                            send_tx_for_led_1sec();
                        }
                    }
                }
                /* id 0x705  and id 0x265 */
                else if(( DataByte_au8[8] == 0xE0 && DataByte_au8[9] == 0xA0 ) || ( DataByte_au8[8] == 0x4C && DataByte_au8[9] == 0xA0))
                {
                    if( DataByte_au8[8] == 0xE0 && DataByte_au8[9] == 0xA0 )
                    { 
                        if(DataByte_au8[1] & 0x01)
                        {
                            data[7] = 0x02;
                            led_delay = 0x01;
                            send_tx_for_led_1sec();
                        }
                    }
                    else 
                    {
                        if(DataByte_au8[2] & 0x01)
                        {
                            data[7] = 0x02;
                     
                            led_delay = 0x01;
                            send_tx_for_led_1sec();
                        }
                    }
                }
                else
                {
                    // nothing in else 
                } 
                /* checking id 0x042 */
                    if( DataByte_au8[8] == 0x08 && DataByte_au8[9] == 0x40 )
                        {
                                speed = DataByte_au8[5];
                                speed = speed | DataByte_au8[6] << 8;
                                speed = speed | DataByte_au8[8] << 16;  /* storing the three bytes speed data into one variable*/
                            if(speed > 100)  /* comparing speed with 100 */  
                            {
                                data[5] = 0x01;
                            }
                        }
                /* checking id 0x069 */
                    if( DataByte_au8[8] == 0x0D && DataByte_au8[9] == 0x20 )
                        {
                            if(DataByte_au8[0] > 50 )/* comparing temperature with 50*/
                            {
                                data[6] = 0x01;
                            }
                        }
               
        }
    
    }
    
    
    
    
    
}

void system_init()
{
    /* CAN_TX = RB2, CAN_RX = RB3 */
	TRISBbits.RB2 = DISABLE;				/* CAN TX */
	TRISBbits.RB3 = ENABLE;					/* CAN RX */
    /*CONFIG THE GENERAL INTERUPPT*/
    GIE = ENABLE;
    PEIE = ENABLE;
    /*CONFIG THE CAN INTERUPPT*/
    PIE3bits.RXB0IE = ENABLE;
    IPR3bits.RXB0IP = ENABLE;
    /*CONFIG THE CAN INTERUPPT*/
    PIE3bits.RXB1IE = ENABLE;
    IPR3bits.RXB1IP = ENABLE;
}
void can_init()
{
	CANCON = 0x80;                       	/* set new mode configuration mode */

	/* Wait untill desired mode is set */
	while (CANSTAT != 0x80);                //1000 for Configuration mode    000 = No interrupt 

	BRGCON1 = 0xC1;							/* 1100 0001  */
	BRGCON2 = 0xAE;							/* 1010 1110   */
	BRGCON3 = 0x45;							/* 0100 0101  */
    
    CIOCON = 0x20;                         /*CAN I/O CONTROL REGISTER */
    
/* Enter CAN module into Normal mode */
	CANCON = 0x00;                          // 0000 for normal mode
    
}

void __interrupt() ISR1()
{

    if(1 == PIR3bits.RXB0IF)
    {
        PIR3bits.RXB0IF = 0; /* clearing interrupt flag */
        if(RXB0CONbits.RXB0FUL == 1)
        {
            
        }
        CANCON = 0x0C;   
        ReadRxBuffer0(); /* calling the function to reading the received message */ 
        can_tx1(); /* calling the function to transmit the data*/ 
    }
}
void main(void) {
    TRISBbits.RB0=0;
    PORTBbits.RB0=0;
//    unsigned long int DelayCounter_u32;
    system_init();
    can_init();
    Can_SetRcvRuleBuf0();
    while(1u)
    {
/* super loop */
    }
    return;
}
