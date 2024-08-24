/*
 * keep__a_certain_distance.c
 *
 * Created: 8/16/2024 2:13:42 PM
 *  Author: RS3
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "Dio.h"
#include "direction_speed.h"
int main(void)
{
	
	unsigned short a,b,high,distance,forword_distance=0,backword_distance=0;
	
	DIO_vsetpindir('D',5,1);//output servo motor
	DIO_vsetpindir('D',7,1);//tr--- PD6 echo 
    while(1)
    {
        //TODO:: Please write your application code 
		
		
		TCCR1A = 0;
		TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
		DIO_vwrite('D',7,1);
		_delay_us(50);
		DIO_vwrite('D',7,0);
		
		TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
		while ((TIFR&(1<<ICF1)) == 0);
		a = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
		while ((TIFR&(1<<ICF1)) == 0);
		b = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		TCNT1=0;
		TCCR1B = 0;  		/* Stop the timer */
		high=b-a;
		distance=((high*34600)/(F_CPU*2)) ;
		
		
		if (distance>=15 && distance<=20)
		{
			stop_motor();
		} 
		else if(distance>20)
		{
			motor_forword();
		}else if (distance<15)
		{
			motor_backword();
					}
		
		

    }
}