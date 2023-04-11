#include "OS.h"

void Blink1(void)
{
	while(1){
		GPIOC->ODR ^= 1<<2;
		halt_ms(200);
	}
}

void Blink2(void)
{
	while(1){

		GPIOC->ODR ^= 1<<3;
		halt_ms(50);
	}
}
