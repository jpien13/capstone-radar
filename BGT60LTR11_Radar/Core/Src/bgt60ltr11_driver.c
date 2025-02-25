/*
 * bgt60ltr11_driver.c
 *
 *  Created on: Feb 25, 2025
 *      Author: jasonpien
 */

#include "bgt60ltr11_driver.h"
#include "main.h"

#define RADAR_CS_PIN	GPIO_PIN_4
#define RADAR_CS_PORT	GPIOA
#define RADAR_TDET_PIN	GPIO_PIN_0
#define RADAR_TDET_PORT	GPIOA
#define RADAR_PDET_PIN	GPIO_PIN_1
#define RADAR_PDET_PORT	GPIOA
// MIGHT NOT NEED PLL
#define RADAR_PLL_TRIG_PIN	GPIO_PIN_1
#define RADAR_PLL_TRIG_PIN	GPIOB
// MIGHT NOT NEED PLL

uint8_t BGT60_SPI_Read(uint8_t reg_addr, uint_16 *data){
	uint8_t tx_data[3];
	uint8_t rx_data[3] = {0, 0, 0};
	/* 	We send the register address from where we want to read
	 * 	and than we read 2 bytes
	 * 	so we need to send 2 dummy bytes
	 * */

	/* Need format address for read operation (LSB=0) */
	tx_data[0] = (uint8_t)((reg_addr << 1) & 0xFE);
	tx_data[1] = 0; /* Dummy byte */
	tx_data[2] = 0; /* Dummy byte */

	// Asset Chip Select
	HAL_GPIO_WritePin(RADAR_CS_PORT, RADAR_CS_PIN, GPIO_PIN_RESET);

	/* Small delay for stability */
	for(volatile int i = 0; i < 10; i++);

	if(HAL_SPI_Transmit(&hspi1, tx_data, sizeof(tx_data), 100) != HAL_OK){
		HAL_GPIO_WritePin(RADAR_CS_PORT, RADAR_CS_PIN, GPIO_PIN_SET);
		return HAL_ERROR;
	}

	/* Small delay before de-assert */
	for(volatile int i = 0; i < 10; i++);

	HAL_GPIO_WritePin(RADAR_CS_PORT, RADAR_CS_PIN, GPIO_PIN_SET);

	return HAL_OK;

}
