#include "OS.h"
#include "main.h"
//#include "stdio.h"
#include "string.h"


uint8_t uart_buffer[20] = {0};

void UartComm(void){

	while(1){

		HAL_UARTEx_ReceiveToIdle_DMA(huart, uart_buffer, sizeof(uart_buffer));
		lcd_write(uart_buffer);
		strcpy(uart_buffer, "");

	}

}
