
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





#define _XTAL_FREQ 20000000
#define ENABLE 1
#define DISABLE 0
#include <xc.h>
unsigned char can_frame[13];
static void init_can(void)
{
    
    TRISBbits.RB3 = 1;/*configured as CAN_RX (input)*/
    TRISBbits.RB2 = 0;/*configured as CAN_TX (output)*/
    
    CANCON = 0x80;/*requests configuration mode*/
    while(CANSTAT != 0x80);/*condition checks for configuration mode*/
    /* Baud rate is 250kHz*/    
    BRGCON1 = 0xC1;/*Sync Jump Width = 4;Baud Rate Pre scaler bits = 4*/
    BRGCON2 = 0xAE;/*Phase Segment 1 Time = 6, Propagation Time = 7*/
    BRGCON3 = 0x45;/*Phase Segment 2 Time = 6*/
    
    CIOCON = 0x20;  /*CANTX pin will drive VDD when recessive*/
    CANCON = 0x00;/*requests normal mode*/
}
static void can_tx_init(void)
{
    CANCON = 0x08;/*requests normal mode and transmit buffer 0*/
}
static void can_tx_1(void)
{
    /*Condition checks for Automatically cleared when the message is successfully sent
     requests normal mode and transmit buffer 0*/
    if(TXB0CONbits.TXREQ == 0 && CANCON == 0x08) 
    {
    /*given Standard data frame identifier is 0x100 */
    TXB0SIDH = 0x20;		/* Standard Identifier higher bits D10 to D3 */
	TXB0SIDL = 0x00;		/* Standard Identifier lower bits D2 TO D0 */
	TXB0DLC = 0x08;			/* Data Length Code    8 bytes of length  */ 
	TXB0D0 = 'k';			/* DataByte 0  */
	TXB0D1 = 'u';			/* DataByte 1 */
	TXB0D2 = 's';			/* DataByte 2 */
	TXB0D3 = 'u';			/* DataByte 3 */
    TXB0D4 = 'm';      /* DataByte 4 */
    TXB0D5 = 'l';/* DataByte 5 */
    TXB0D6 = 'u';/* DataByte 6 */
    TXB0D7 = 'v';/* DataByte 7 */
    TXB0CON = 0x08;         /*message was not aborted,message not lose the arbitration while tx
                            ,bus error did not occur while the message was being sent
                            , Requests sending a message. Clears the TXABT, TXLARB and TXERR bits. 
                                                  , Priority Level 0 (lowest priority                            */
    }
    
}

static void can_tx_2(void)
{
    /*Condition checks for Automatically cleared when the message is successfully sent
     requests normal mode and transmit buffer 0*/
    if(TXB0CONbits.TXREQ == 0 && CANCON == 0x08) 
    {
    /*given Standard data frame identifier is 0x100 */
    TXB0SIDH = 0x40;		/* Standard Identifier higher bits D10 to D3 */
	TXB0SIDL = 0x00;		/* Standard Identifier lower bits D2 TO D0 */
	TXB0DLC = 0x08;			/* Data Length Code    8 bytes of length  */ 
	TXB0D0 = 'v';			/* DataByte 0  */
	TXB0D1 = 'i';			/* DataByte 1 */
	TXB0D2 = 's';			/* DataByte 2 */
	TXB0D3 = 'h';			/* DataByte 3 */
    TXB0D4 = 'a';      /* DataByte 4 */
    TXB0D5 = 'l';/* DataByte 5 */
    TXB0D6 = 's';/* DataByte 6 */
    TXB0D7 = 'g';/* DataByte 7 */
    TXB0CON = 0x08;         /*message was not aborted,message not lose the arbitration while tx
                            ,bus error did not occur while the message was being sent
                            , Requests sending a message. Clears the TXABT, TXLARB and TXERR bits. 
                                                  , Priority Level 0 (lowest priority                            */
    }
    
}


  
  
  
void main(void)
{
    TRISA=0x00;/*Port A is Configured as output port*/
    TRISAbits.RA0 = DISABLE;/*led is initialized to off state*/
    init_can();/*function call*/
    can_tx_init();
    for(int i = 0 ; i < 5 ; i++)
    {
        can_tx_1();
    __delay_ms(1000);
    }
    
    while(1)
    {
    can_tx_2();
     __delay_ms(1000);
    TRISAbits.RA0 = ENABLE;
    }
    
        
    }