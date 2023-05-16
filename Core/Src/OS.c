
#include <stdint.h>
#include "OS.h"
#include "main.h"
#include "uart_communication.h"


uint8_t thread_counter = 0;
TCB *current_thread_pt;
TCB tcb[MAX_THREADS] = {0};
uint8_t uart_rx_buffer[UART_BUFFER_SIZE] = {0};


void halt_us(uint32_t time)
{
	for (uint32_t i = 0; i < time; ++i) NOP_US;
}

void halt_ms(uint32_t time)
{
	for(uint32_t i = 0; i < time; ++i) {
		for (uint32_t ii = 0; ii < 64; ++ii) {
			NOP_MS;
		}
	}
}



void CreateThread(void (*thread_handler)(void), uint32_t stack_size,
												uint32_t *stack_ptr,
												uint8_t *thread_id,
												uint8_t *function1,
												uint8_t *function2,
												uint8_t *function3)
{
	if(thread_counter < MAX_THREADS)
	{

		tcb[thread_counter].stack_pointer = stack_ptr[stack_size];

		--tcb[thread_counter].stack_pointer; *(tcb[thread_counter].stack_pointer) |= 1<<24;					/*xPSR*/
		*(--tcb[thread_counter].stack_pointer) = (uint32_t) thread_handler;									/*PC*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF; 												/*LR*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R12*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R3*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R2*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R1*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;   												/*R0*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R11*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R10*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R9*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R8*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;   												/*R7*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R6*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R5*/
		*(--tcb[thread_counter].stack_pointer) = 0xDEADBEEF;												/*R4*/

		/* determined values for stack overflow detection */
		for (uint8_t i = 0; i < OVERFLOW_DETECTION_SIZE; ++i) {
			tcb[thread_counter].stack_pointer[i] = 0xDEADFACE;
		}

		++thread_counter;
	}

}

void Os_Init(void)
{
	SysTick_Config(SystemCoreClock/1000);		//Set tick time to 1 ms

	/*Linking the elements of the list*/

	if (thread_counter >= 2) {
		for (uint8_t i = 0; i < thread_counter-1; ++i)	tcb[i].next = &tcb[i+1];
		tcb[thread_counter-1].next = &tcb[0];
	}
	else if(thread_counter == 1) tcb[0].next = &tcb[0];
	else if(thread_counter == 0) System_Fault_Handler("No Threads!");




	/*Choosing the first thread*/

	current_thread_pt = &tcb[0];


	__asm("LDR	R0,=current_thread_pt");			//R0 = &current_thread_pt
	__asm("LDR	R1, [R0]");							//R1 = current_thread_pt
	__asm("LDR	SP, [R1]");							//SP = *current_thread_pt
	__asm("pop	{r0-r12}");
	__asm("add	sp,sp,#4");							//Skip LR register
	__asm("POP	{LR}");								//Load thread address into PC
	__asm("add	sp,sp,#4");							//Skip xPSR register
	__asm("CPSIE	I");							//Enable interrupts and exceptions again
	__asm("bx 	lr");								//Return to 1st thread
}


void System_Fault_Handler(uint8_t *string)
{
	__disable_irq();

	while(true){
		lcd_write(string);
		Halt_ms(1000);
		send_command_to_lcd(0b00000001);
		Halt_ms(1);
		GPIOA->ODR ^= 1<<5;
	}

}








