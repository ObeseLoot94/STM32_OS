#include "lcd_driver.h"
#include "syscalls_own.h"


void lcd_init(void)
{
	GPIOB->ODR &=	~(1<<RS);
	GPIOB->ODR |= 1<<DATA4 | 1<<DATA5;

	HAL_Delay(20);
	ENABLE_DATA();

	HAL_Delay(5);
	ENABLE_DATA();

	HAL_Delay(2);
	ENABLE_DATA();

	GPIOB->ODR &= ~(1<<DATA4);
	ENABLE_DATA();
	HAL_Delay(5);

	send_command_to_lcd(0b00101000);	// N=1(2 rows), F=0 (5*8 matrix)
	send_command_to_lcd(0b00001000);	// display off, cursor&blinking off
	send_command_to_lcd(0b00000001);	// clear screen, return cursor home
	send_command_to_lcd(0b00000110);	// inc cursor right when writing, don't shift screen
	send_command_to_lcd(0b00001100);	// display back on
}

void lcd_write(char *s)
{
	send_command_to_lcd(0b00000001);

	GPIOB->ODR |= 1<<RS;

	while(*s != 0){
		GPIOB->ODR &= 0x0FFF;
		GPIOB->ODR |= ((*s & 0xF0)<<8);
		ENABLE_DATA();

		GPIOB->ODR &= 0x0FFF;
		GPIOB->ODR |= (((*s<<4) & 0xF0)<<8);
		ENABLE_DATA();
		++s;
	}

	Wait(1);
}

void send_command_to_lcd(uint8_t command)
{
	GPIOB->ODR &= ~(1<<RS);
	GPIOB->ODR &= 0x0FFF;
	GPIOB->ODR |= ((command & 0xF0)<<8);
	ENABLE_DATA();

	GPIOB->ODR &= 0x0FFF;
	GPIOB->ODR |= (((command<<4) & 0xF0)<<8);
	ENABLE_DATA();

	HAL_Delay(2);
}


