/*
 * debug.c
 *
 *  Created on: 1 lis 2022
 *      Author: x300
 */


#include "debug.h"

//needed for printf debug fucnction over stm32 swo

int _write(int file, char *ptr, int len)
{
	for(int i=0; i<len; i++)
	{
		ITM_SendChar((*ptr++));
	}
	return len;
}
