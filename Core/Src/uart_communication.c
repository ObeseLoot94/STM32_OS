#include "OS.h"
#include "main.h"
#include "uart_communication.h"
#include "syscalls_own.h"

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
