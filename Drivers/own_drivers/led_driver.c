#include "OS.h"
#include "main.h"
#include "syscalls_own.h"
#include "string.h"

extern uint32_t blink2_stack[MIN_STACK_SIZE + 100];

void Blink1(void)
{
	while(1){
		GPIOC->ODR ^= 1<<2;
		Wait(100);

	}
}

void Blink2(void)
{
	for (int i = 0; i < 25; ++i) {
		GPIOC->ODR ^= 1<<3;
		Wait(50);
	}


	while(1){

		GPIOC->ODR ^= 1<<3;
		Wait(500);
	}
}



