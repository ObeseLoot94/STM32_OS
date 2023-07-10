/*
 * OS.h
 *
 *  Created on: Jun 4, 2022
 *      Author: szuperpeti
 */

#ifndef INC_OS_H_
#define INC_OS_H_

#include "stdint.h"





			/* KERNEL CONFIGS */
#define OVERFLOW_DETECTION_SIZE (5u)
#define MIN_STACK_SIZE			(16u + OVERFLOW_DETECTION_SIZE)
#define MAX_THREADS 			(5u)

// Thread statuses

#define ACTIVE			(1U)
#define INACTIVE		(2U)
#define SUSPENDED		(3U)

#define ENTER_ATOMIC() __disable_irq();
#define EXIT_ATOMIC()  __enable_irq();
#define ATOMIC(x)		__disable_irq();\
						x;\
						__enable_irq();

/*Global Variables*/
typedef struct thread_t
{
	uint32_t *stack_pointer;
	uint32_t *end_of_stack;
	struct thread_t *next;
	struct thread_t *previous;
	uint8_t *name;
	uint8_t tid;
	uint8_t status;
}thread_t;






extern thread_t *current_thread_pt;

void CreateThread(void (*thread_handler)(void), uint32_t stack_size, uint32_t *stack_ptr, uint8_t *thread_name);

void Os_Init(void);

void Kernel_Fault_Handler(uint8_t *error_message);



#endif /* INC_OS_H_ */
