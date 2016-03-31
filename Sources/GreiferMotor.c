/*
 * GreiferMotor.c
 *
 *  Created on: 21.03.2016
 *      Author: Klaus Jordan
 */
#include "GreiferMotor.h"
#include "DCMotor.h"
#include "PwmLdd2.h"
#include "TU2.h"
#include "WAIT1.h"

void runDCMotor(void){
	int i = 0;


	for(i=255;i>=0;i--){

		DCMotor_SetRatio8(i);
		WAIT1_WaitOSms(100);

	}

	for(;;){}


}

