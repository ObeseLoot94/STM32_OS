#include "ethernet.h"


extern SPI_HandleTypeDef hspi1;




uint8_t ethernet_init()
{
	/* Waiting for the system to boot */
	while((read_control_register(ESTAT) & (1<<CLKRDY)) == 0){;}


	/* Setting the receive buffer ... by a user define percentage */
	set_recieve_buffer_by_percent(50);

	/* MAC init */
	set_mac_mii_register_bit(MACON1, MARXEN);
	set_mac_mii_register_bit(MACON1, RXPAUS);
	set_mac_mii_register_bit(MACON1, TXPAUS);
	set_mac_mii_register_bit(MACON3, FULDPX);
	set_mac_mii_register_bit(MACON3, PADCFG0);
	set_mac_mii_register_bit(MACON3, FRMLNEN);
	set_mac_mii_register_bit(MACON4, DEFER);

	/* Here would go to maximum frame length settings */

	write_register_by_byte(MABBIPG, 0x15);
	write_register_by_byte(MAIPGL, 0x12);
	write_register_by_byte(MAIPGL, 0x0C);



	return;
}



uint8_t read_mac_mii_register(uint16_t address)
{
	/* setting the bank number based on the address */
	if((address & 0xFF00) == 0x0000) switch_bank(BANK0);
	if((address & 0xFF00) == 0x0100) switch_bank(BANK1);
	if((address & 0xFF00) == 0x0200) switch_bank(BANK2);
	if((address & 0xFF00) == 0x0300) switch_bank(BANK3);

	uint8_t mac_mii_data[2];
	uint8_t command = (uint8_t) address;

	CS_LOW;
	/* send command to ethernet module*/
	HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
	HAL_SPI_Receive(&hspi1, &mac_mii_data[0], sizeof(mac_mii_data), 1000);
	CS_HIGH;

	return mac_mii_data[1];
}

uint8_t read_control_register(uint16_t address)
{

	/* setting the bank number based on the address */
	if((address & 0xFF00) == 0x0000) switch_bank(BANK0);
	if((address & 0xFF00) == 0x0100) switch_bank(BANK1);
	if((address & 0xFF00) == 0x0200) switch_bank(BANK2);
	if((address & 0xFF00) == 0x0300) switch_bank(BANK3);

	uint8_t control_reg_data = (uint8_t) address;

	CS_LOW;
	/* send command to ethernet module*/
	HAL_SPI_Transmit(&hspi1, &control_reg_data, sizeof(control_reg_data), 1000);
	HAL_SPI_Receive(&hspi1, &control_reg_data, sizeof(control_reg_data), 1000);
	CS_HIGH;

	return control_reg_data;
}


void write_register_by_byte(uint16_t address, uint8_t data)
{

	/* setting the bank number based on the address */
	if((address & 0xFF00) == 0x0000) switch_bank(BANK0);
	if((address & 0xFF00) == 0x0100) switch_bank(BANK1);
	if((address & 0xFF00) == 0x0200) switch_bank(BANK2);
	if((address & 0xFF00) == 0x0300) switch_bank(BANK3);

	uint8_t command[2];
	command[0] = (WCR<<5) | (uint8_t) address;
	command[1] = data;

	CS_LOW;
	HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
	CS_HIGH;
}

void set_control_register_bit(uint16_t address, uint8_t bit)
{
	uint8_t command[2];
	command[0] = (WCR<<5) | (uint8_t) address;
	command[1] = (read_control_register(address)) | (1<<bit);

	CS_LOW;
	HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
	CS_HIGH;
}

void set_mac_mii_register_bit(uint16_t address, uint8_t bit)
{
	uint8_t command[2];
	command[0] = (WCR<<5) | (uint8_t) address;
	command[1] = (read_mac_mii_register(address)) | (1<<bit);

	CS_LOW;
	HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
	CS_HIGH;
}

void clear_control_register_bit(uint16_t address, uint8_t bit)
{
	uint8_t command[2];
	command[0] = (WCR<<5) | (uint8_t) address;
	command[1] = (read_control_register(address)) & ~(1<<bit);

	CS_LOW;
	HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
	CS_HIGH;
}


void clear_mac_mii_register_bit(uint16_t address, uint8_t bit)
{
	uint8_t command[2];
	command[0] = (WCR<<5) | (uint8_t) address;
	command[1] = (read_mac_mii_register(address)) & ~(1<<bit);

	CS_LOW;
	HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
	CS_HIGH;
}

void switch_bank(uint8_t bank)
{
	uint8_t register_value;
	uint8_t command = (WCR<<5) | (uint8_t) ECON1;

	if(bank == BANK0){
		register_value = get_econ1_register_value();
		register_value &= 0b11111000;

		/* sending new value */
		CS_LOW;
		HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
		HAL_SPI_Transmit(&hspi1, &register_value, sizeof(register_value), 1000);
		CS_HIGH;
	}

	else if(bank == BANK1){
		register_value = get_econ1_register_value();
		register_value |= BANK1;

		/* sending new value */
		CS_LOW;
		HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
		HAL_SPI_Transmit(&hspi1, &register_value, sizeof(register_value), 1000);
		CS_HIGH;
	}

	else if(bank == BANK2){
		register_value = get_econ1_register_value();
		register_value |= BANK2;

		/* sending new value */
		CS_LOW;
		HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
		HAL_SPI_Transmit(&hspi1, &register_value, sizeof(register_value), 1000);
		CS_HIGH;
	}

	else if(bank == BANK3){
		register_value = get_econ1_register_value();
		register_value |= BANK3;

		/* sending new value */
		CS_LOW;
		HAL_SPI_Transmit(&hspi1, &command, sizeof(command), 1000);
		HAL_SPI_Transmit(&hspi1, &register_value, sizeof(register_value), 1000);
		CS_HIGH;
	}
}


uint8_t get_econ1_register_value(void)
{
	uint8_t econ1 = (uint8_t) ECON1;

	CS_LOW;
	HAL_SPI_Transmit(&hspi1, &econ1, sizeof(econ1), 1000);
	HAL_SPI_Receive(&hspi1, &econ1, sizeof(econ1), 1000);
	CS_HIGH;

	return econ1;
}


void set_recieve_buffer_by_percent(uint8_t percent)
{
	uint8_t endpointer_value = (0x1FFF*percent)/100;

	/* Setting the starting pointer to 0 */
	write_register_by_byte(ERXSTL, ERXSTL_DATA);
	write_register_by_byte(ERXSTH, ERXSTH_DATA);

	write_register_by_byte(ERXNDL, endpointer_value);
	write_register_by_byte(ERXNDH, endpointer_value>>8);
}








