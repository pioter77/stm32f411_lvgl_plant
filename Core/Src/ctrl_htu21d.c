/*
 * ctrl_htu21d.c
 *
 *  Created on: Feb 8, 2023
 *      Author: x300
 */

#include "ctrl_htu21d.h"

//  HAL_I2C_Master_Transmit_IT(htu->hi2c, 0x80, &HTU21D_Temp_Cmd, 1);
//  HAL_Delay(500);
//  HAL_I2C_Master_Transmit_IT(&hi2c1, 0x80, &HTU21D_Humi_Cmd, 1);
//  HAL_Delay(500);



HTU21D_t HTU21D={

		.hi2c = &hi2c1,
		.state = htu21d_state_NOT_INITIALIZED,

		.HTU21D_Temp_Cmd= HTU21D_ADR_TEMP_START_CNV,
		.HTU21D_Humi_Cmd= HTU21D_ADR_HUMI_START_CNV,
		.HTU21D_Temp_Adr= HTU21D_ADR_TEMP_GETVAL,
		.HTU21D_Humi_Adr= HTU21D_ADR_HUMI_GETVAL,
};



//void htu21d_init(HTU21D_t *htu)
//{
//
////	htu->hi2c = i2c_handlPtr;
//
//	  HAL_I2C_Master_Transmit_IT(htu->hi2c, HTU21D_DEV_ADR_WRITE, &htu->HTU21D_Temp_Cmd, 1);
//	  HAL_Delay(500);
//	  HAL_I2C_Master_Transmit_IT(htu->hi2c, HTU21D_DEV_ADR_WRITE, &htu->HTU21D_Humi_Cmd, 1);
//	  HAL_Delay(500);
//}
//void htu21d_readHumi(HTU21D_t *htu)
//{
//	  HAL_I2C_Master_Transmit_IT(htu->hi2c, HTU21D_DEV_ADR_READ, &htu->HTU21D_Humi_Adr, 1);
//	  while(HAL_I2C_Master_Receive_IT(htu->hi2c, HTU21D_DEV_ADR_READ, (uint8_t *)htu->HTU21D_RX_Data_2, 3) != HAL_OK)
//	  {
//		  //wait for rec data
//	  }
//	//	  HAL_I2C_Mem_Read_IT(&hi2c2, (uint16_t)0x40 << 1 , HTU21D_Temp_Cmd, I2C_MEMADD_SIZE_8BIT, (uint8_t *)HTU21D_RX_Data_1, 2);
//	  htu->HTU21D_ADC_Raw_humi = (uint16_t)(htu->HTU21D_RX_Data_2[0] << 8) | (uint16_t)(htu->HTU21D_RX_Data_2[1] & 0xFC);
//	  htu->HTU21_humidity = (float)(htu->HTU21D_ADC_Raw_humi * 125.00/ 65536.00) - 6.00;
//	  HAL_Delay(200);
//}
//void htu21d_readTemp(HTU21D_t *htu)
//{
//	  HAL_I2C_Master_Transmit_IT(htu->hi2c, HTU21D_DEV_ADR_READ, &htu->HTU21D_Temp_Adr, 1);
//	  while(HAL_I2C_Master_Receive_IT(htu->hi2c, HTU21D_DEV_ADR_READ, (uint8_t *)htu->HTU21D_RX_Data_1, 3) != HAL_OK)
//	  {
//		  //wait for rec data
//	  }
//	//	  HAL_I2C_Mem_Read_IT(&hi2c2, (uint16_t)0x40 << 1 , HTU21D_Temp_Cmd, I2C_MEMADD_SIZE_8BIT, (uint8_t *)HTU21D_RX_Data_1, 2);
//	  htu->HTU21D_ADC_Raw_temp = (uint16_t)(htu->HTU21D_RX_Data_1[0] << 8) | (uint16_t)(htu->HTU21D_RX_Data_1[1] & 0xFC);
//	  htu->HTU21_temperature = (float)(htu->HTU21D_ADC_Raw_temp * 175.72/ 65536.00) - 45.85;
//	  HAL_Delay(200);
//}

static void htu21_init_humi(HTU21D_t *htu)
{
	if(HAL_I2C_Master_Transmit_IT(htu->hi2c, HTU21D_DEV_ADR_WRITE, &htu->HTU21D_Humi_Cmd, 1) == HAL_OK) htu->state= htu21d_state_INITIALIZED_HUMI;
	else{
		//do nothing becouse busy or some errors in transmission
	}
}

static void htu21_init_temp(HTU21D_t *htu)
{
  if(HAL_I2C_Master_Transmit_IT(htu->hi2c, HTU21D_DEV_ADR_WRITE, &htu->HTU21D_Temp_Cmd, 1) == HAL_OK) htu->state= htu21d_state_INITIALIZED_TEMP;
  else{
	  //do nothing becouse busy or some errors in transmission
  }
}

static void htu21_read_humi(HTU21D_t *htu)
{
  HAL_I2C_Master_Transmit_IT(htu->hi2c, HTU21D_DEV_ADR_READ, &htu->HTU21D_Humi_Adr, 1);
  while(HAL_I2C_Master_Receive_IT(htu->hi2c, HTU21D_DEV_ADR_READ, (uint8_t *)htu->HTU21D_RX_Data_2, 3) != HAL_OK)
  {
	  //wait for rec data
  }
  htu->HTU21D_ADC_Raw_humi = (uint16_t)(htu->HTU21D_RX_Data_2[0] << 8) | (uint16_t)(htu->HTU21D_RX_Data_2[1] & 0xFC);
  htu->HTU21_humidity = (float)(htu->HTU21D_ADC_Raw_humi * 125.00/ 65536.00) - 6.00;
//  HAL_Delay(200);
}

static void htu21_read_temp(HTU21D_t *htu)
{
  HAL_I2C_Master_Transmit_IT(htu->hi2c, HTU21D_DEV_ADR_READ, &htu->HTU21D_Temp_Adr, 1);
  while(HAL_I2C_Master_Receive_IT(htu->hi2c, HTU21D_DEV_ADR_READ, (uint8_t *)htu->HTU21D_RX_Data_1, 3) != HAL_OK)
  {
	  //wait for rec data
  }
  htu->HTU21D_ADC_Raw_temp = (uint16_t)(htu->HTU21D_RX_Data_1[0] << 8) | (uint16_t)(htu->HTU21D_RX_Data_1[1] & 0xFC);
  htu->HTU21_temperature = (float)(htu->HTU21D_ADC_Raw_temp * 175.72/ 65536.00) - 45.85;
//  HAL_Delay(200);
}

void ctrl_htu21d(HTU21D_t *htu)
{
	switch(htu->state)
	{
		case htu21d_state_NOT_INITIALIZED:

			break;
		case htu21d_state_INITIALIZING_HUMI:

			break;
		case htu21d_state_INITIALIZED_HUMI:

			break;
		case htu21d_state_INITIALIZING_TEMP:

			break;
		case htu21d_state_INITIALIZED_TEMP:

			break;
		case htu21d_state_LOOP_START:

			break;
		case htu21d_state_READING_HUMIDITY:

			break;
		case htu21d_state_HUMIDIDY_OK:

			break;
		case htu21d_state_READING_TEMPERATURE:

			break;
		case htu21d_state_TEMPERATURE_OK:

			break;
		case htu21d_state_LOOP_END:

			break;

	}
}
