/*
 * uart_communication.h
 *
 *  Created on: May 9, 2023
 *      Author: szuperpeti
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

void Check_Thread_ID(void);
void Uart_communication(void);
//uint8_t Send_Thread_Infos(uint8_t thread_counter, TCB *tcb, UART_HandleTypeDef *huart1);

#define UART_BUFFER_SIZE		(20u)

#endif /* INC_UART_COMMUNICATION_H_ */
