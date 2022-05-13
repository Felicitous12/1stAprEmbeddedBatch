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
void init_can(void)
{
	/* CAN_TX = RB2, CAN_RX = RB3 */
	TRISBbits.RB2 = 0;								/* CAN TX */
	TRISBbits.RB3 = 1;								/* CAN RX */

	/* Enter CAN module into config mode   we need to set the values as 80 in cnstat
     *  so we are bitwise oring with 80    why means The CAN module has to be initialized before the
activation. This is only possible if the module is in the
Configuration mode.  */
	CANCON |= 0x80;                       	/* set new mode configuration mode */

	/* Wait untill desired mode is set */
	while (CANSTAT != 0x80);                //1000 for Configuration mode    000 = No interrupt 


	/* Initialize CAN Timing Baud rate setting 250KHZ
     * 
     * Baud rate = bit time * (sync+propogation+phase1+phase2)
     *              
     *              bit time = (2*1)/FOSC  */
  
	BRGCON1 = 0xC1;							/* 1100 0001, SJW=4, TQ, BRP (2*2)/FOSC */
	BRGCON2 = 0xAE;							/* 1010 1110, SEG2PHTS 1 sampled once PS1=6TQ PropagationT 7TQ */
	BRGCON3 = 0x45;							/* 0100 0101, PS2, 6TQ */
    
    
    CIOCON = 0x20;                         /*CAN I/O CONTROL REGISTER */
    
                                            //CANTX pin will drive VDD when recessive 
                                            //can capture bit is disabled.        
/* Enter CAN module into Normal mode */
	CANCON = 0x08;                          // 0000 for normal mode 1000 for transmit buffer

}

void can_transmit(void)
{ 
    if(TXB0CONbits.TXREQ == 0 && CANCON == 0x08) 
    {
    /*given Standard data frame identifier is 0x560 */
    TXB0SIDH = 0xAC;		/* Standard Identifier higher bits D10 to D3 */
	TXB0SIDL = 0x00;		/* Standard Identifier lower bits D2 TO D0 */

	TXB0DLC = 0x04;			/* Data Length Code    4 bytes of length  */ 
   
	TXB0D0 = 0xAA;			/* DataByte 0  //given 4 bytes of data*/
    
    
	TXB0D1 = 0x5A;			/* DataByte 1 */
   
    
	TXB0D2 = 0xA5;			/* DataByte 2 */
    
	TXB0D3 = 0x55;			/* DataByte 3 */
    
    
    TXB0CON = 0x08;         /*message was not aborted,message not lose the arbitration while tx
                            ,bus error did not occur while the message was being sent
                            , Requests sending a message. Clears the TXABT, TXLARB and TXERR bits. 
                                                  , Priority Level 0 (lowest priority                            */

}
}




 
int main(int argc, char** argv) {
 
    init_can();
    
    while(1)
    {
     can_transmit();
     __delay_ms(1000);
    }
      
    return (EXIT_SUCCESS);
}
