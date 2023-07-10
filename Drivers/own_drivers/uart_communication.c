#include "OS.h"
#include "main.h"
#include "uart_communication.h"
#include <stdbool.h>

#include "../../Core/kernel/syscalls_own.h"

static uint8_t uart_rx_buffer[UART_BUFFER_SIZE] = {0};


void Uart_communication(void)
{

	while(true){
		Check_Thread_ID();
	}

}





void Check_Thread_ID(void)
{
	for (int i = 0; (uart_rx_buffer[i] !=0) || (uart_rx_buffer[i] != ';'); ++i) {

	}
}

/*uint8_t Send_Thread_Infos(uint8_t thread_counter, TCB *tcb, UART_HandleTypeDef *huart1)
{
	uint8_t tid_number[3] = {0};

	for(uint8_t i = 0; i < thread_counter; ++i){
		if(tcb[i].thread_name != NULL){
			HAL_UART_Transmit(&huart1, tcb[i].thread_name, strlen(tcb[i].thread_name), 1000);
			sprintf(tid_number, "%d", tcb[i].tid);
			HAL_UART_Transmit(huart1, tid_number, strlen(tid_number), 1000);
			memset(tid_number, '\0', sizeof(tid_number));
		}

		if(tcb[i].attribute1 != NULL) 	HAL_UART_Transmit(&huart1, tcb[i].attribute1, strlen(tcb[i].attribute1), 1000);

		if(tcb[i].attribute2 != NULL) 	HAL_UART_Transmit(&huart1, tcb[i].attribute2, strlen(tcb[i].attribute2), 1000);

		if(tcb[i].attribute3 != NULL)	HAL_UART_Transmit(&huart1, tcb[i].attribute3, strlen(tcb[i].attribute3), 1000);

		if(tcb[i].thread_name != NULL) 	HAL_UART_Transmit(huart1, "NEXT_THREAD", strlen("NEXT_THREAD"), 1000);
	}

	HAL_UART_Transmit(huart1, "END_INFO", strlen("END_INFO"), 1000);


	return 0;
}
*/
