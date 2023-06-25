//STM32F411 Nucleo Board

//PA2 -> USART2 Tx
//PA3 -> USART2 Rx
//PA2 & PA3 -> AF07 (GPIO Alternate Function)
#include <stdio.h>
#include <stdint.h>
#include <stm32f4xx.h>
#include <uart.h>
#include <adc.h>


uint32_t sensor_value;

int main(void)
{

	uart2_tx_init();
	adc_init();


	while(1)
	{
		start_conversion();
		sensor_value = adc_read();
		printf("Sensor value: %d \n\r",(int)sensor_value);

	}

}

