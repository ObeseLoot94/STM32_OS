/*
 * OS.h
 *
 *  Created on: Jun 4, 2022
 *      Author: szuperpeti
 */

#ifndef INC_OS_H_
#define INC_OS_H_
#include "main.h"

			/*Macros*/
#define STACK_SIZE	(80u)
#define MAX_THREADS (5u)




			/*Global Variables*/
typedef struct{
	uint32_t *stack_pointer;
	struct TCB *next;
	uint32_t stack[STACK_SIZE];
}TCB;


extern TCB *current_thread_pt;


			/*Function declarations*/
void create_thread(void (*thread_handler)(void));
void halt_us(volatile uint32_t time);
void halt_ms(volatile uint32_t time);
void blink1(void);
void blink2(void);

void os_init(void);
void system_fault_handler(void);





#define NOP_US __asm(  			\
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
);

#define NOP_MS __asm(			\
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
			"nop\n"             \
);



#endif /* INC_OS_H_ */