/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
© Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : matrix-keyboard-7segment-module
Version : 1.0.0
Date    : 7/5/2017
Author  : melika barzegaran hosseini 9231035 - soroush kavousi 9231077
Company : 
Comments: 
a script to test whether the interrupt-based matrix keyboard and the 7segment module work correctly together


Chip type               : ATmega32A
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/

/*****************************************************
instructions:
0. fuse bit setup:
    - CKSEL[3:0] = 0001
    - CKOPT = 1
    - SUT[1:0] = 10
1. disable led module (JP1).
2. disable buzzer module (JP2).
3. enable 7segment module (JP3).
4. diable pwm module (JP4).
5. disable analog comparator module (JP5 and JP6). 
6. remove the lcd from the board.
*****************************************************/

#include <mega32a.h>
#include <delay.h>

void delay();
void show(int number);

//define an array to hold bits to show numbers in a common-anode 7segment.
unsigned char symbols[16] = {0xC0, 0xCF, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0x9E, 0xA1, 0x86, 0x8E};

interrupt [EXT_INT1] void ext_int1_isr(void)
{
    //pull up all the rows except the first row.
    //if the first row is the target, find the target column and show the number.
	PORTA = 0b11101111;
    delay();
    if(PINA.0 == 0) show(0);
    if(PINA.1 == 0) show(1);
    if(PINA.2 == 0) show(2);
    if(PINA.3 == 0) show(3);
	
    //pull up all the rows except the second row.
    //if the second row is the target, find the target column and show the number.
	PORTA = 0b11011111;
    delay();
    if(PINA.0 == 0) show(4);
    if(PINA.1 == 0) show(5);
    if(PINA.2 == 0) show(6);
    if(PINA.3 == 0) show(7);
    
    //pull up all the rows except the third row.
    //if the third row is the target, find the target column and show the number.
    PORTA = 0b10111111;
    delay();
    if(PINA.0 == 0) show(8);
    if(PINA.1 == 0) show(9);
    if(PINA.2 == 0) show(10);
    if(PINA.3 == 0) show(11);
    
    //pull up all the rows except the fourth row.
    //if the fourth row is the target, find the target column and show the number.
    PORTA = 0b01111111;
    delay();
    if(PINA.0 == 0) show(12);
    if(PINA.1 == 0) show(13);
    if(PINA.2 == 0) show(14);
    if(PINA.3 == 0) show(15);
    
    // change configurations to normal.
    PORTA = 0x0F;
}

void delay()
{
    // make a delay so that the microcontroller syncs between PIN and PORT registers.
    delay_ms(1);
}

void show(int number)
{
    // show the number on the 7segment.
    PORTB = symbols[number];
}

void main(void)
{
    // define columns as input and rows as output.
    // pull up columns and pull down rows.
    DDRA = 0xF0;
    PORTA = 0x0F;
    
    // make 7segment ports output.
    // turn the 7segment off.
    DDRB = 0xFF;
    PORTB = 0xFF;
    
    // define external interrupt #0 output and pull it up.
    // it is so important to pull this pin. if it is not pulled up, no interrupt
    // would be generated whenever a switch is pressed.
    DDRD = 0x00;
    PORTD = 0x08;

    // enable external interrupt #1.
    GICR = 0x80;
    
    // make the switches sensitive to low level.
    MCUCR = 0x00;

    // enable interrupts.
    #asm("sei")

    // endless loop.
    while (1);
}