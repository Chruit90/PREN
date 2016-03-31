/*
 * RTOS.h
 *
 *  Created on: 18.02.2016
 *      Author: Philipp
 */

#ifndef RTOS_H_
#define RTOS_H_

#include "FRTOS1.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"

#define RTOS_QUEUE_LENGTH	16 /* items in queue, that's my buffer size */
#define RTOS_QUEUE_ITEM_SIZE	32/8 /* 4 bytes for 32bits, because FRTOS has a 32 bit processor and one address will be 32bits long */

/*! \brief Initializes the RTOS and starts the first task. */
void RTOS_Init(void);

void RTOS_AddTask(void (*)(void*), signed char*);

xQueueHandle RTOS_CreateQueue(void);

void RTOS_EnqueueString(xQueueHandle, unsigned char*);

/*! \brief Never forget to use vPortFree after using the string received by this function! */
char* RTOS_DequeueString(xQueueHandle);

void RTOS_Wait(int);

#endif /* SOURCES_RTOS_H_ */
