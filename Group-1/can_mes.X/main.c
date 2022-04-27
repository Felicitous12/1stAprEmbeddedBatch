/* Author : Siva, Sharada
   Date : 27-04-2022
   Purpose : tx message */

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

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "main.h"
void sec_delay();
void baud_rate_setting() 
{    
    
    BRGCON1 = 0x80;
    BRGCON2 = 0xB7;
    BRGCON3 = 0x43;
}
void transmit_buffer()
{
    TXB0CON = 0x00;//transmit buffer 0 control register
    TXB0SIDH = 0xAC; //transmit buffer 0  standard identifier high byte registers
    TXB0SIDL = 0x00; //transmit buffer  0 standard identifier low byte registers
    while(1)
    {
       TXB0DLC = 0x04; // transmit buffer 0 data length code ( 4 bytes)
    TXB0D0 = 0xAA;//transmit buffer 0 data field byte 0
    TXB0D1 = 0x5A;//transmit buffer 0 data field byte 1
    TXB0D2 = 0xA5;//transmit buffer 0 data field byte 2
    TXB0D3 = 0x55;//transmit buffer 0 data field byte 3
    TXB0REQ = 1;//Requests sending a message. Clears the TXABT, TXLARB and TXERR bits.
    sec_delay();
    }
    
}

void main(void) {
    GIE = 1;  //enable the global interrupt
    PEIE = 1; // enable the peripheral interrupt
    TRISB =0x00;// setting the port B as a output port
    RB0=1;//setting the pin RB0
    RB3=1;//configured as CAN_RX (input)
    RB2=0;//configured as CAN_TX (output)
    /*//CAN Interrupt Register
    PIR3 = 0xE4;
    PIE3 = 0xE5;
    IPR3 = 0xff;*/
   //configuring the can control register 
    CANCON = 0x80;//configuration mode
    
    while(1)
    {
        if(CANSTAT == 0x80)//condition checks for the can status register
        {
        baud_rate_setting();//call the function to do the baud rate setting
        break;
        }
    }
    CIOCON = 0x20;
    CANCON = 0x08;//normal mode
    while(1)
    {
        if(CANSTAT == 0x08)//condition checks for the can status register
        {
            
        transmit_buffer();//call the function 
        break;
        }
    }
    return;
}

void sec_delay()
{
    
    TRISA=0X00;//  PORTA is configured as output port
    PORTA=0X00;//    clearing the PORTA PIN
    //setting the pre scaler as 16 for 1 sec 
    T2CKPS0=1;
    T2CKPS1=1;
    //setting the post scaler as 1 for 1 sec 
     TOUTPS3 = 0;
     TOUTPS2 = 0;
     TOUTPS1 = 0;
     TOUTPS0 = 0;
     PR2 = 250;// loading the pre load register value with 250
    TMR2IE = 1; //timer interrupt is enabled
    TMR2ON=1;//enabling the timer 2
    TMR2IF = 0; //timer interrupt flag is cleared
    
    while(1)
    {
        ; //interrupt will be called
    }
}