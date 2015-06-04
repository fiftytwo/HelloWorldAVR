/*
 * HelloWorldAVR.c
 *
 * Created: 03.06.2015 18:51:15
 *  Author: Dmitry Victorov
 */

#define F_CPU    1000000UL  // ATmega16 Internal clock frequency

#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>


int main()
{
    // DDRB register is responsible of port B lines direction.
    // If some of bits equals 1 then corresponding port line is used to output data.
    // Otherwise it is used as input.
    // Here we set 0th port line as output by setting 0th bit to 1.
    DDRB = 0x01;
    
    while (true)
    {
        bool isTwiceSleep;
        
        // If the 1st bit of B port is set to 1 (no contact) set isTwiceSleep to 1
        if (PINB & _BV(PB1))
            isTwiceSleep = true;
        else
            isTwiceSleep = false;
        
        // Set 0th bit of port B to 1 (turn LED on)
        PORTB |= _BV(PB0);
        
        // Wait depending on 1st bit of B port
        if (isTwiceSleep)
            _delay_ms(1000);
        else
            _delay_ms(500);
        
        // Set 0th bit of port B to 0 (turn LED off)
        PORTB &= ~_BV(PB0);
        
        // Wait depending on 1st bit of B port
        if (isTwiceSleep)
            _delay_ms(1000);
        else
            _delay_ms(500);
    }
    
    return 0;
}
