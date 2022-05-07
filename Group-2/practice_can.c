/*
 * File:   practice_can.c
 * Author: User
 *
 * Created on May 2, 2022, 5:44 PM
 */


/* 
 * File:   main.c
 * Author: User
 *
 * Created on April 23, 2022, 4:11 PM
 */

// PIC18F458 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config OSCS = OFF       // Oscillator System Clock Switch Enable bit (Oscillator system clock switch option is disabled (main oscillator is source))

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bit (Brown-out Reset enabled)
#pragma config BORV = 25        // Brown-out Reset Voltage bits (VBOR set to 2.5V)

// CONFIG2H
#pragma config WDT = ON         // Watchdog Timer Enable bit (WDT enabled)
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
#define _XTAL_FREQ 20000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>   


#define ENABLE 1;
#define DISABLE 0;

unsigned char can_frame[13];


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


void can_rx_init()
{
    CANCON = 0x0C;                          // 0000 for normal mode for receive buffer0
    
    
     /* ENABLE FILERS *FILTER 0*/
    RXF0SIDH = 0XD0;
    RXF0SIDL = 0X40;
       
 /*ENABLE MASK*/
    RXM0SIDH = 0XFF;    
    RXM0SIDL = 0XC0;

 /* SET RECEICVE MODE FOR BUFFERS */
    RXB0CON = 0X00;
    
}
void can_tx_init()
{
   /* CANCON = 0x80;               CONFIG MODE
    while (CANSTAT != 0x80); */
    
    
    CANCON = 0x08;              /*in normal mode to transmit buffer 0*/ 
    
}
   void can_tx()
{  
    TXB0CON =0X00;       //Set bits for transmit control register 
    TXB0SIDH =0XAC;      //set transmit buffer for standard identifier high byte 
    TXB0SIDL =0X80;   //set transmit buffer for standard identifier low byte 
    TXB0DLC =0X04;       //set transmit buffer for data length code
    TXB0D0 =can_frame[3];        //data to  transmit 
    TXB0D1 =can_frame[4];        //data to  transmit 
    TXB0D2 =can_frame[5];        //data to  transmit 
    TXB0D3 =can_frame[6];        //data to  transmit 
    TXB0CONbits.TXREQ =1;          //setting the buffer to transmit
    if(TXB0D0 == 0x01)
        PORTCbits.RC1=ENABLE;
     __delay_ms(1000);
  
   
   
}

void can_rx()
{   
    /*Checking Receive buffer contains a received message or not*/
    PORTCbits.RC0= DISABLE;
    if (RXB0CONbits.RXB0FUL)
    {
       can_frame[0] = RXB0DLC;  
       can_frame[1] = RXB0SIDL;
       can_frame[2] = RXB0SIDH;
       can_frame[3] = RXB0D0;
       can_frame[4] = RXB0D1;
       can_frame[5] = RXB0D2;
       can_frame[6] = RXB0D3;
       can_frame[7] = RXB0D4;
       can_frame[8] = RXB0D5;
       can_frame[9] = RXB0D6;
       can_frame[10] = RXB0D7;
    }
    
}

void __interrupt() ISR1()
{
   
    if( CANSTAT == 0x0C && PIR3bits.RXB0IF)
    {
      can_rx();
    }
    PORTCbits.RC0= ENABLE;
    can_tx_init();
    
    if(CANCON == 0x08)
    {
      can_tx();
    }
  
        
}
void main() {
    TRISC = 0;      /* making port c output*/
    PORTCbits.RC0= DISABLE;  // LED IS OFF
  
    system_init();
    can_init();
    can_rx_init();
    while(1)
    {   
        
        //PORTCbits.RC0= ENABLE;
        //__delay_ms(1000);
    }
    
    
}

