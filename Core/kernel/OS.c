#include <stdint.h>
#include "OS.h"
#include <stdbool.h>
#include "lcd_driver.h"



thread_t *current_thread_pt = NULL;
uint8_t thread_counter = 0;
thread_t threads[MAX_THREADS] = {0};



void CreateThread(void (*thread_handler)(void), uint32_t stack_size, uint32_t *stack_ptr, uint8_t *thread_name)
{

	threads[thread_counter].tid = thread_counter;
	bool is_name_valid = false;
	for (int i = 0; i < 20; ++i) {
		if(thread_name[i] == 0){
			threads[thread_counter].name = thread_name;
			is_name_valid = true;
			break;
		}
	}
	if(is_name_valid == false); //TODO: error handling

	threads[thread_counter].end_of_stack = &stack_ptr[0];

	if(thread_counter < MAX_THREADS)
	{
		threads[thread_counter].stack_pointer = &stack_ptr[stack_size];											// Over indexing because the stack predecrements

		--threads[thread_counter].stack_pointer; *(threads[thread_counter].stack_pointer) |= 1<<24;				/*xPSR*/
		*(--threads[thread_counter].stack_pointer) = (uint32_t) thread_handler;									/*PC*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF; 												/*LR*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R12*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R3*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R2*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R1*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;   												/*R0*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R11*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R10*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R9*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R8*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;   												/*R7*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R6*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R5*/
		*(--threads[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R4*/


		/* determined values for stack overflow detection */
		for (uint8_t i = 0; i < OVERFLOW_DETECTION_SIZE; ++i) {
			stack_ptr[i] = 0xDEADFACE;
		}

		++thread_counter;
	}

	else; //TODO: error handling
}

void Os_Init(void)
{
	SysTick_Config(SystemCoreClock/1000);		//Set tick time to 1 ms

	/*Linking the elements of the list*/

	if (thread_counter >= 2) {
		for (uint8_t i = 0; i < thread_counter-1; ++i)	threads[i].next = &threads[i+1];
		threads[thread_counter-1].next = &threads[0];


		for (int i = thread_counter-1; i > 0; --i) 		threads[i].previous = &threads[i-1];
		threads[0].previous = &threads[thread_counter-1];
	}

	else if(thread_counter == 1){
		threads[0].next = &threads[0];
		threads[0].previous = &threads[0];
	}
	else if(thread_counter == 0) Kernel_Fault_Handler("No Threads!");

	/*Choosing the first thread*/

	current_thread_pt = &threads[0];

	/*POP context*/

	__asm("LDR	R0, =current_thread_pt");			//R0 = &current_thread_pt
	__asm("LDR	R1, [R0]");							//R1 = current_thread_pt
	__asm("LDR	SP, [R1]");							//SP = *current_thread_pt
	__asm("pop	{r0-r12}");
	__asm("add	sp,sp,#4");							//Skip LR register
	__asm("POP	{LR}");								//Load thread address into PC
	__asm("add	sp,sp,#4");							//Skip xPSR register
	__asm("CPSIE	I");							//Enable interrupts and exceptions again
	__asm("bx 	lr");								//Return to 1st thread
}


void Kernel_Fault_Handler(uint8_t *error_message)
{
	__disable_irq();

	lcd_write(error_message);
	while(true){
		GPIOA->ODR ^= 1<<5;
		HAL_Delay(100);
	}
}











