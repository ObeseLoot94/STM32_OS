

#ifndef INC_SYSCALLS_H_
#define INC_SYSCALLS_H_

uint8_t Get_TID(void);

void Wait(uint16_t wait);
void Kill(uint8_t tid);
void Activate(void (*thread_handler)(void), uint32_t stack_size, uint32_t *stack_ptr, uint8_t *thread_name, uint8_t tid);
void Suspend(uint8_t tid);
void Unsuspend(uint8_t tid);


uint8_t* Get_Name(void);
uint8_t Get_TID(void);

#endif /* INC_SYSCALLS_H_ */
