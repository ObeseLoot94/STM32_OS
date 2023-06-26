#include "lcd_driver.h"


void lcd_init(void)
{
	GPIOB->ODR &=	~(1<<RS);
	GPIOB->ODR |= 1<<DATA4 | 1<<DATA5;

	halt_ms(20);
	ENABLE_DATA();

	halt_ms(5);
	ENABLE_DATA();

	halt_ms(2);
	ENABLE_DATA();

	GPIOB->ODR &= ~(1<<DATA4);
	ENABLE_DATA();
	halt_ms(5);

	send_command_to_lcd(0b00101000);	// N=1(2 rows), F=0 (5*8 matrix)
	send_command_to_lcd(0b00001000);	// display off, cursor&blinking off
	send_command_to_lcd(0b00000001);	// clear screen, return cursor home
	send_command_to_lcd(0b00000110);	// inc cursor right when writing, don't shift screen
	send_command_to_lcd(0b00001100);	// display back on
}

void lcd_write(char *s)
{
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

	halt_ms(2);
}

void lcd_string(uint8_t *string)
{
	while(1)
	{
		lcd_write(string);
		Halt_ms(1000);
		send_command_to_lcd(0b00000001);
		Halt_ms(1);
	}
}
