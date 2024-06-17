#include <avr/io.h>
#include <util/delay.h>

int main(void)
{   //set PORT D2 as an output
    DDRB = DDRB | (1<< DDD2);
    //set timer 0 prescaler to 1024
    //loop*(forever)
    while(1)
        {
            //SET PORT D2 
            PORTD = PORTD | (1<<PORTD2);
            //wait
            _delay_ms(500);
            //unset PORT D2
            PORTD = PORTD & ~(1<<PORTD2);
            //wait
            _delay_ms(500); // Add the delay time in milliseconds


        }
}   
