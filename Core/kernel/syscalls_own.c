#include <led_driver.h>
#include "main.h"
#include "OS.h"
#include "syscalls_own.h"
#include "led_driver.h"
#include "stdbool.h"

extern thread_t threads[MAX_THREADS];
extern uint16_t thread_timer;


uint8_t Get_TID(void)
{
	return current_thread_pt->tid;
}

uint8_t* Get_Name(void)
{
	return current_thread_pt->name;
}

void Suspend(uint8_t tid)
{
	if(threads[tid].status == ACTIVE) threads[tid].status = SUSPENDED;
}

void Unsuspend(uint8_t tid)
{
	ENTER_ATOMIC();

	if(threads[tid].status == SUSPENDED){
		threads[tid].status = ACTIVE;
	}

	EXIT_ATOMIC();
}


void Kill(uint8_t tid)
{
	ENTER_ATOMIC();
	threads[tid].status = INACTIVE;
	threads[tid].previous->next = threads[tid].next;
	threads[tid].next->previous = threads[tid].previous;
	EXIT_ATOMIC();
}

/*wait: milliseconds*/
void Wait(uint16_t wait)
{
uint16_t counter = thread_timer;

while((uint16_t)(wait+counter) < thread_timer);
while((uint16_t)(wait+counter) >= thread_timer);
}

void Activate(void (*thread_handler)(void), uint32_t stack_size, uint32_t *stack_ptr, uint8_t *thread_name, uint8_t tid)
{
	ENTER_ATOMIC();
	if(threads[tid].status == INACTIVE){
		bool is_name_valid = false;
		for (int i = 0; i < 20; ++i) {
			if(thread_name[i] == 0){
				threads[tid].name = thread_name;
				is_name_valid = true;
				break;
			}
		}
		if(is_name_valid == false); //TODO: error handling

		threads[tid].end_of_stack = &stack_ptr[0];

		threads[tid].stack_pointer = &stack_ptr[stack_size];										// Over indexing because the stack predecrements


		--threads[tid].stack_pointer;
		*(threads[tid].stack_pointer) = 0;															/*empty register*/
		*(threads[tid].stack_pointer) |= 1<<24;														/*xPSR*/
		*(--threads[tid].stack_pointer) = (uint32_t) thread_handler;								/*PC*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF; 												/*LR*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R12*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R3*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R2*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R1*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;   											/*R0*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R11*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R10*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R9*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R8*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;   											/*R7*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R6*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R5*/
		*(--threads[tid].stack_pointer) = 0xDEADBEEF;												/*R4*/


		/* determined values for stack overflow detection */
		for (uint8_t i = 0; i < OVERFLOW_DETECTION_SIZE; ++i) {
			stack_ptr[i] = 0xDEADFACE;
		}

		threads[tid].next = current_thread_pt->next;
		threads[tid].next->previous = &threads[tid];

		current_thread_pt->next = &threads[tid];
		threads[tid].previous = current_thread_pt;
		threads[tid].status = ACTIVE;
	}
	EXIT_ATOMIC();
}

