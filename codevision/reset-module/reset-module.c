/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
© Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : reset-module
Version : 1.0.0
Date    : 7/5/2017
Author  : melika barzegaran hosseini 9231035 - soroush kavousi 9231077
Company : 
Comments: 
a script to test whether the external reset works correctly


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
1. enable led module (JP1).
2. disable buzzer module (JP2).
3. disable 7segment module (JP3).
4. diable pwm module (JP4).
5. disable analog comparator module (JP5 and JP6).
6. remove the lcd from the board.
*****************************************************/

#include <mega32a.h>

void main(void)
{
    // make the led D1 port output.
    DDRB = 0x01;
    
    // turn the led D1 on.
    PORTB = 0x01;

    // endless loop.
    while (1);
}