#include "OS.h"
#include "main.h"
#include "uart_communication.h"

extern uint8_t thread_counter;
extern TCB tcb[MAX_THREADS];
extern UART_HandleTypeDef huart1;





uint8_t Send_Thread_Infos(uint8_t thread_counter, TCB *tcb, UART_HandleTypeDef *huart1)
{
	for(uint8_t i = 0; i < thread_counter; ++i){
		if(tcb[i]->thread_ID != NULL) 			HAL_UART_Transmit(&huart1, tcb[thread_counter]->thread_ID, strlen(tcb[thread_counter]->thread_ID), 1000);

		if(tcb[i]->first_function_ID != NULL) 	HAL_UART_Transmit(&huart1, tcb[thread_counter]->first_function_ID, strlen(tcb[thread_counter]->first_function_ID), 1000);

		if(tcb[i]->second_function_ID != NULL) 	HAL_UART_Transmit(&huart1, tcb[thread_counter]->second_function_ID, strlen(tcb[thread_counter]->second_function_ID), 1000);

		if(tcb[i]->third_function_ID != NULL)	HAL_UART_Transmit(&huart1, tcb[thread_counter]->third_function_ID, strlen(tcb[thread_counter]->third_function_ID), 1000);

		if(tcb[i]->thread_ID != NULL) 			HAL_UART_Transmit(huart1, "NEXT_THREAD", strlen("NEXT_THREAD"), 1000);
	}

	HAL_UART_Transmit(huart1, "END_INFO", strlen("END_INFO"), 1000);


	return 0;
}

