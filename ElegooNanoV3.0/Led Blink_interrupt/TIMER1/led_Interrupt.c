#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRD = 0X00;
    TCCR1B = (1<< WGM12); // set timer 1 to CTC mode
    OCR1A = 15625;
    TIMSK1 = (1<<OCIE1A); // Enable CTC interrupt AT THE OCR1A VALUE
    sei(); // Enable global interrupts
    TCCR1B = (1<<CS12) | (1<<CS10); // set timer 1 prescaler to 1024
    while(1)
    {

    }

}

ISR(TIMER1_COMPA_vect)
{
    PORTD ^= (1<<PORTD2); // toggle PORT D2
    
}