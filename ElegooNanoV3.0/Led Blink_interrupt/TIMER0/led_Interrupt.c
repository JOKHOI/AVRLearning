#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
int extraTime =0;
int main(void){
     
     DDRD = 0x01; //set PORT D2 as an output
     TCCR0A = (1<<WGM01); //set timer 0 to CTC mode
     OCR0A = 156; //set CTC compare value to 156
     TIMSK0 = (1<<OCIE0A); //enable CTC interrupt
     sei(); //enable global interrupts 
     TCCR0B = (1<<CS02) | (1<<CS00); //set timer 0 prescaler to 1024  AND STARTS THE TIMER !!!! 
   
    //loop*(forever)
    while(1)
        {
        
            


        }
}   

ISR(TIMER0_COMPA_vect){
    extraTime++;
    if(extraTime>100)
    {
        PORTD ^= (1<<PORTD2); //toggle PORT D2
        extraTime = 0;
    }

}