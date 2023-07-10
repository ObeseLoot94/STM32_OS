
#ifndef INC_LCD_DRIVER_H_
#define INC_LCD_DRIVER_H_
#include "main.h"
#include "OS.h"

#define ENABLE_DATA()			GPIOB->ODR |= 1<<ENABLE; \
								HAL_Delay(1);\
								GPIOB->ODR &= ~(1<<ENABLE);

#define DATA7	(15U)
#define DATA6	(14U)
#define DATA5	(13U)
#define DATA4	(12U)
#define RS		(2U)
#define ENABLE	(1U)

void lcd_write(char *s);
void send_command_to_lcd(uint8_t command);
void lcd_init(void);


#endif /* INC_LCD_DRIVER_H_ */
