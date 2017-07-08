/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
© Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : buzzer-switch-module
Version : 1.0.0
Date    : 7/5/2017
Author  : melika barzegaran hosseini 9231035 - soroush kavousi 9231077
Company : 
Comments: 
a script to test whether the buzzer module and the switch module work correctly together


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
2. enable buzzer module (JP2).
3. disable 7segment module (JP3).
4. diable pwm module (JP4).
5. disable analog comparator module (JP5 and JP6).
6. remove the lcd from the board.
*****************************************************/

#include <mega32a.h>

interrupt [EXT_INT0] void ext_int0_isr(void)
{
    // turn the buzzer on if it is off.
    // turn the buzzer off if it is on.
    PORTD.6 = !PORTD.6;
}

void main(void)
{
    // make the buzzer BUZZER port output and turn it off.
    DDRD = 0x40;
    PORTD = 0x00;
    
    // make the switch SW1 port input and pull it up.
    DDRD |= 0x00;
    PORTD |= 0x04;

    // enable external interrupt #0.
    GICR = 0x40;
    
    // make the swith sensitive to any level.
    MCUCR = 0x01;

    // enable interrupts.
    #asm("sei")

    // endless loop.
    while (1);
}