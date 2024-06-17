#include <avr/io.h>
#include <util/delay.h>

//The following code examples show how to do an atomic read of the TCNT1 register contents. Reading any of the OCR1A/B (timer/counter 1 register)
//or ICR1 registers can be done by using the same principle.
unsigned int TIM16_ReadTCNT1 (void)
{
    unsigned char sreg;
    unsigned int i;
    /*Save global interrupt flag*/
    /*NOTE:SREG is the flag register */ 
    sreg = SREG;
    /*Disable interrupts */
    _CLI();
    /* Read TCNT1 into i */
    i = TCNT1;
    /* Restore global interrupt flag */
    SREG = sreg;
    return i;
}


int main(void)
{   //set PORT D2 as an output
    DDRB = DDRB | (1<< DDD2);
    //set timer 0 prescaler to 1024
    TCCR0A = TCCR0A | (1<<CS00) | (1<<CS02);
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