/*
 * ctrl_htu21d.h
 *
 *  Created on: Feb 8, 2023
 *      Author: x300
 */

#ifndef INC_CTRL_HTU21D_H_
#define INC_CTRL_HTU21D_H_


#include "main.h"
#include "i2c.h"


#define HTU21D_DEV_ADR_READ    						(uint8_t)0x81
#define HTU21D_DEV_ADR_WRITE    					(uint8_t)0x80
//adr write to this in order to start conversions then wait a while and read conversions form sensor
#define HTU21D_ADR_TEMP_START_CNV 					(uint8_t)0xF3
#define HTU21D_ADR_HUMI_START_CNV 					(uint8_t)0xF5
//read from this registers
#define HTU21D_ADR_TEMP_GETVAL 						(uint8_t)0xE3
#define HTU21D_ADR_HUMI_GETVAL 						(uint8_t)0xE5

typedef enum {	htu21d_state_NOT_INITIALIZED= 0,
				htu21d_state_INITIALIZING_HUMI,
				htu21d_state_INITIALIZED_HUMI,
				htu21d_state_INITIALIZING_TEMP,
				htu21d_state_INITIALIZED_TEMP,

				htu21d_state_LOOP_START,
				htu21d_state_READING_HUMIDITY,
				htu21d_state_HUMIDIDY_OK,
				htu21d_state_READING_TEMPERATURE,
				htu21d_state_TEMPERATURE_OK,
				htu21d_state_LOOP_END} htu21d_state_t;

typedef struct HTU21D_T{
	//hal handlers:
	I2C_HandleTypeDef *hi2c;

	htu21d_state_t state;			//main loop control variable

	uint8_t HTU21D_RX_Data_1[3];
	uint8_t HTU21D_RX_Data_2[3];
	uint16_t HTU21D_ADC_Raw_temp;
	uint16_t HTU21D_ADC_Raw_humi;
	float HTU21_temperature;			//calculated values and filtered
	float HTU21_humidity;				//calculated values and filtered
	uint8_t HTU21D_Temp_Cmd;		//write to those registers starts tmep/humi conversions
	uint8_t HTU21D_Humi_Cmd;

	uint8_t HTU21D_Temp_Adr;		//read from this registers returns valeues from sensor
	uint8_t HTU21D_Humi_Adr;
}HTU21D_t;

extern HTU21D_t HTU21D;


void htu21d_init(HTU21D_t *htu);
void htu21d_readHumi(HTU21D_t *htu);
void htu21d_readTemp(HTU21D_t *htu);


void ctrl_htu21d(HTU21D_t *htu);
#endif /* INC_CTRL_HTU21D_H_ */
