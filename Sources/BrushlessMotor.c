/*
 * BrushlessMotor.c
 *
 *  Created on: 21.03.2016
 *      Author: Klaus Jordan
 */

#include "BrushlessMotor.h"
#include "WAIT1.h"
#include "BLDC.h"
#include "LED_BLUE.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"

void runBLDC(void){
	uint8_t pos;
	int a;
	int b;

	//BLDC_SetPos(0);
	//WAIT1_Waitms(7000);
	//LED_BLUE_Neg();

	BLDC_SetPos(127);
	WAIT1_Waitms(3000);
	LED_BLUE_Neg();

	//BLDC_SetPos(255);
	//WAIT1_Waitms(3000);
	//LED_BLUE_Neg();

	//BLDC_SetPos(0);
	//WAIT1_Waitms(3000);
	//LED_BLUE_Neg();

	BLDC_SetPos(170);
	WAIT1_Waitms(30);
	LED_BLUE_Neg();

	//BLDC_SetPos(158);
	//WAIT1_Waitms(3000);
	//LED_BLUE_Neg();

	//BLDC_SetPos(159);
	//WAIT1_Waitms(3000);
	//LED_BLUE_Neg();

	for(pos=159;pos<=255;pos+=5){//60 Anfahren, 50 Nullposition
			BLDC_SetPos(170);
			WAIT1_Waitms(3000);
			LED_BLUE_Neg();


	}

	for(;;){};
	//Rückwärts

	BLDC_SetPos(0);
	WAIT1_Waitms(500);
	LED_BLUE_Neg();

	BLDC_SetPos(127);
	WAIT1_Waitms(500);
	LED_BLUE_Neg();






	for(pos=100;pos>=0;pos-=10){//60 Anfahren, 50 Nullposition
			BLDC_SetPos(pos);
			WAIT1_Waitms(1000);
			LED_BLUE_Neg();


	}

	for(;;){};



	for(;;){};



	LED_BLUE_Neg();

	for(;;){};

	//BLDC_SetPos(200);
	//WAIT1_Waitms(10000);
	//LED_BLUE_Neg();

	//BLDC_SetPos(0);
	//WAIT1_Waitms(5000);
	//LED_BLUE_Neg();
	for(;;){

	//BLDC_SetPos(0);
	//WAIT1_Waitms(500);


	//for(pos=50;pos>=10;pos--){//60 Anfahren, 50 Nullposition
	//		BLDC_SetPos(pos);
	//		WAIT1_Waitms(500);
	//}
	LED_BLUE_Neg();



	}


}

