
#include "motor_control.h"
#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define SUCCESS (0u)
#define FAILURE (1u)

#define TRUE (1u)
#define FALSE (0u)

#define NaN_STRING_CODE (0x004e614eul)
#define nan_STRING_CODE (0x006e616eul)

#define Inf_STRING_CODE (0x00666E49ul)
#define inf_STRING_CODE (0x00666E69ul)

extern UART_HandleTypeDef huart1;




int32_t str2float(char *s, float *n);


void motor_control(void)
{
	char uart_data[9] = {0};
	uint8_t data_index = 0;
	bool ready_to_convert = false;
	float recent_coordinate;
	float previous_coordinates;

	while(ready_to_convert == false){
		if(huart1.Instance->SR & (1<<DR_NOT_EMPTY)){
			uart_data[data_index] = huart1.Instance->DR;
			++data_index;
			if(data_index == 8) ready_to_convert = true;
		}
	}
	str2float(uart_data, &recent_coordinate);
	previous_coordinates = recent_coordinate;

	while(7)
	{
		while(ready_to_convert == false){
			if(huart1.Instance->SR & (1<<DR_NOT_EMPTY)){
				uart_data[data_index] = huart1.Instance->DR;
				++data_index;
				if(data_index == 8) ready_to_convert = true;
			}
		}
		str2float(uart_data, &recent_coordinate);

		/*motor control function goes here*/

		previous_coordinates = recent_coordinate;
	}


}


int32_t str2float(char *s, float *n)
{
    *n = 0.0f;
    uint32_t is_negative = FALSE;
    if(*s == '-'){
        is_negative = TRUE;
        ++s;
    }
    else if(*s == '+') ++s;
    else if(*(uint32_t *)s == NaN_STRING_CODE){
        *n = NAN;
        return SUCCESS;
    }
    else if(*(uint32_t *)s == nan_STRING_CODE){
        *n = NAN;
        return SUCCESS;
    }
    else if(*(uint32_t *)s == Inf_STRING_CODE){
        *n = INFINITY;
        return SUCCESS;
    }
    else if(*(uint32_t *)s == inf_STRING_CODE){
        *n = INFINITY;
        return SUCCESS;
    }
    else if(*s > '9' || *s < '0'){
        *n = 0.0f;
        return FAILURE;
    }
    else{
        *n += *s - '0';
        ++s;
    }

    while(*s){
        if(*s <= '9' && *s >= '0'){
            *n *= 10;
            *n += *s - '0';
        }
        else if(*s == '.'){
            ++s;
            float f_temp = 0.0f;
            uint32_t i = 0;
            for(i = 0; *s <= '9' && *s >= '0'; ++i, ++s){
                f_temp += *s - '0';
                f_temp *= 10;
            }
            if(*s != 0 && *s != 'e' && *s != 'E'){
                *n = 0.0f;
                return FAILURE;
            }
            f_temp /= 10;
            for(; i; --i) f_temp /= 10;
            *n += f_temp;
            --s;
        }
        else if(*s == 'e' || *s == 'E'){
            uint32_t tmp = 0;
            ++s;
            if(*s <= '9' && *s >= '0'){
                while(*s <= '9' && *s >= '0'){
                    tmp += *s -'0';
                    tmp *= 10;
                    ++s;
                }
                tmp /= 10;
                if(*s == 0){
                    for(uint32_t iteration = tmp/4; iteration; --iteration) *n *= 10000;
                    for(uint32_t iteration = tmp%4; iteration; --iteration) *n *= 10;
                }
                else{
                    *n = 0.0f;
                    return FAILURE;
                }
                --s;
            }
            else if(*s == '-'){
                ++s;
                while(*s <= '9' && *s >= '0'){
                    tmp += *s -'0';
                    tmp *= 10;
                    ++s;
                }
                tmp /= 10;
                if(*s == 0){
                    for(uint32_t iteration = tmp/4; iteration; --iteration) *n /= 10000;
                    for(uint32_t iteration = tmp%4; iteration; --iteration) *n /= 10;
                }
                else{
                    *n = 0.0f;
                    return FAILURE;
                }
                --s;
            }
            else{
                *n = 0.0f;
                return FAILURE;
            }
        }
        else{
            *n = 0.0f;
            return FAILURE;
        }
        ++s;
    }
    if(is_negative) *n = *n*(-1);
    return SUCCESS;
}
