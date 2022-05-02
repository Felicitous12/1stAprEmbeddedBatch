

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
#define _XTAL_FREQ 20000000
#include <xc.h>

/*void main()
{
    GIE=1;
    PEIE=1;
    TRISA=0X00;
    RA0=1;
    RA1=1;
    RA2=0;
    
            
    CANCON=0X00;
    while(1)
    {
            
    if(CANSTAT==0X00)
    {
        BRGCON1=0XC1;
        BRGCON2=0XAE;
        BRGCON3=0X45;   
        break;
    }
    
}
}*/
#include<stdio.h>
#include<stdlib.h>
   
    

void data_pass(void)
{
    if(TXB0CONbits.TXREQ == 0 && CANCON == 0X08)        //to check the transmit bit wheather it is in normal mode or not ,so anding with can control register 
    {
    
    TXB0SIDH=0XCE;                      //setting the transmit buffer register for standard identifier for high bytes
  
    TXB0SIDL=0X00;                   //setting the transmit buffer register for standard identifier for low bytes
   
    TXB0DLC=0X04;                   //setting the register of data length code 
    TXB0D0=0XAA;                    //to set data byte 1  
   
    TXB0D1=0X5A;                    //to set data byte 2
    
    TXB0D2=0XA5;            //to set data byte 3
    
    TXB0D3=0X55;            //to set data byte 4
    TXB0CON=0X08;             // enabling the transmit buffer to normal mode 
    
    }
}
void data_pass1(void)
{
    if(TXB1CONbits.TXREQ == 0 && CANCON == 0X08)        //to check the transmit bit wheather it is in normal mode or not ,so anding with can control register 
    {
    
    TXB1SIDH=0XCE;                      //setting the transmit buffer register for standard identifier for high bytes
  
    TXB1SIDL=0X00;                   //setting the transmit buffer register for standard identifier for low bytes
   
    TXB1DLC=0X04;                   //setting the register of data length code 
    TXB1D0=0XAA;                    //to set data byte 1  
   
    TXB1D1=0X5A;                    //to set data byte 2
    
    TXB1D2=0XA5;            //to set data byte 3
    
    TXB1D3=0X55;            //to set data byte 4
    TXB1CON=0X08;             // enabling the transmit buffer to normal mode 
    
    }
}
void init_can(void)
{
     TRISBbits.RB2=0;           //CAN TX PIN
     TRISBbits.RB3=1;           //CAN RX PIN 
     
    CANCON |= 0X80;             //CONTROL REGISTER ORING WITH VALUE TO READ AND WRITE ,TO SET THE BITS FOR CONFIGURATION  
 
    while(CANSTAT != 0X80)
    {;}     //WHLE LOOP TO CHECK CAN STATUS REGISTER IS  EQUAL TO CANCON  OR NOT  
    /*baud rate vale for 500k */
        BRGCON1=0X80;           //TO set the baud rate register for jump width and  prescale  value   
        BRGCON2=0XAE;            // to set the baud rate register for propagation and phase segment1 time and enable phase segment 2 time 
        BRGCON3=0X43;           // to set the baud rate register for phase 2 segment 
        
     CIOCON=0X20;               //setting input and output pins  
     
     CANCON=0X08;               //setting the bits for normal mode 
    
}

void main()
{
//GIE=1;                  //enable the global interrupt 
//PEIE=1;                 //enable the peripheral  interrupt 
 init_can();              // calling the config function 
    
     while(1)              // enter the while loop 
    {
    
       data_pass();         //calling the function for transmit function 
     __delay_ms(1000);      //time to delay for 1 sec 
     
     data_pass1();         //calling the function for transmit function 
     __delay_ms(1000);      //time to delay for 1 sec 
  
     }
    


}