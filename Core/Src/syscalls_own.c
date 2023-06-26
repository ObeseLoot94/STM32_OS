#include "main.h"
#include "OS.h"

extern TCB *current_thread_pt;
extern TCB tcb;

uint8_t Get_TID(void)
{
	return current_thread_pt->tid;
}

uint8_t* Get_Name(void)
{
	return current_thread_pt->thread_name;
}

void Suspend_Thread(uint8_t tid)
{
	tcb
}
