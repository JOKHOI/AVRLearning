#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
double dutyCycle = 0; // 50% duty cycle
int main(void){

    DDRD = (1<<PORTD6); //turn on port D6 as output
    TCCR0A = (1<<COM0A1 ) | (1<<WGM00) | (1<<WGM01);; // COMPARE MATCH OUTPUT A MODE
    TIMSK0 = (1<<TOIE0); // tTimer counter 0 overflow interrupt Enable
    
    OCR0A = (dutyCycle/100 )*255.0; // conctol the PMW
    sei(); // Enable global interrupts FORGOT IT LAST TIME SO THE INTERRUPT DIDN'T WORK
    TCCR0B = (1<<CS00) | (1<<CS02);//Set prescaler to 1 AND START TIMER
    while(1)
    {
        _delay_ms(100);
        dutyCycle +=10;
        if(dutyCycle>100)
        {
            dutyCycle = 0;
        }
    }

}

/*The ISR function is called when the specified vector occurs. In this case, the ISR is 
run when Timer0 overflows. In the function you put code that is necessary to be run when the interrupt occurs. 
It's really applications specific, but you generally want to keep is small and concise. When the interrupt occurs, the code address 
where the program just was is stored, so after the ISR, the program just jumps back to that point.*/ 
ISR(TIMER0_OVF_vect)
{
    OCR0A = (dutyCycle/100 )*255; // recalculates the duty cycle during interrupt
}