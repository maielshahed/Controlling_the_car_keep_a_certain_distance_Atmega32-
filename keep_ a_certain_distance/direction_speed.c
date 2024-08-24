/*
 * direction_speed.c
 *
 * Created: 8/3/2024 5:21:25 PM
 *  Author: Mai El Shahed
 */ 

#include <avr/io.h>

#include "Dio.h"
#include "Std_macros.h"


int x=80;


void motor_vinti(){
DDRB=0XFF;//output motor  left

DDRA=0XFF;// motor output right

//L293D Pin 1 -> En1 -> motor 1

SET_BIT(PORTA,2);
//L293D Pin 9 -> En2 -> motor 2
SET_BIT(PORTA,3);
//L293D Pin 1 -> En1 -> motor 3
SET_BIT(PORTB,2);
//L293D Pin 1 -> En2 -> motor 4
SET_BIT(PORTB,3);

}

		

void left_forword(){
	/*left ROTAT MOTOR CLOCKWISE*/
	
	DIO_vwrite('B',0,1);
	DIO_vwrite('B',5,1);
	
}

void left_backword(){
	
	
	/* left ROTAT MOTOR ANTI-CLOCKWISE*/
	DIO_vwrite('B',1,1);
	DIO_vwrite('B',4,1);
	
	
}


	

	void right_forword(){
		/*right ROTAT MOTOR CLOCKWISE*/
		DIO_vwrite('A',0,1);
		DIO_vwrite('A',5,1);
	
		
	}

	void right_backword(){
		
		/* left ROTAT MOTOR ANTI-CLOCKWISE*/
		DIO_vwrite('A',1,1);
		DIO_vwrite('A',4,1);
	
		
	}
	
	void motor_forword(){
		left_forword();
		right_forword();

		
	}
	
	
		void motor_backword(){
			left_backword();
			right_backword();
	
			
		}
		
		
	void turn_right(){
		left_forword();
		right_backword();
		
	}
	
	void turn_left(){
		left_backword();
		right_forword();
	}
	
	void stop_motor(){

			DIO_vwrite('A',0,0);
			DIO_vwrite('A',5,0);
			DIO_vwrite('B',0,0);
			DIO_vwrite('B',5,0);	
					DIO_vwrite('A',1,0);
					DIO_vwrite('A',4,0);
					DIO_vwrite('B',1,0);
					DIO_vwrite('B',4,0);
	}
	
	