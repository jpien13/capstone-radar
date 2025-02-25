/*
 * bgt60ltr11_driver.h
 *
 *  Created on: Feb 25, 2025
 *      Author: jasonpien
 */

#ifndef INC_BGT60LTR11_DRIVER_H_
#define INC_BGT60LTR11_DRIVER_H_

#include "stdint.h"
#include "spi.h"


uint8_t BGT60_SPI_Read(uint8_t reg_addr, uint16_t *data);
uint8_t BGT60_SPI_Write(uint8_t reg_addr, uint16_t data);
uint8_t BGT60_HW_Reset(void);
uint8_t BGT60_SoftReset(uint8_t wait);
uint8_t BGT60_PulsedModeInit(void);
uint8_t BGT60_TestComm(void);
uint8_t BGT60_ADCConvert(void);
uint8_t BGT60_ADCStatus(void);
uint8_t BGT60_GetRawData(uint16_t *ifi, uint16_t *ifq);

#endif /* INC_BGT60LTR11_DRIVER_H_ */
