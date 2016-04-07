/*
 * Greifmechanismus.c

 *
 *  Created on: 06.04.2016
 *      Author: Klaus Jordan
 */
#include "Greifmechanismus.h"
#include "Band_STEP.h"
#include "Band_DIR.h"
#include "Band_MS1.h"
#include "Band_MS2.h"
#include "Band_MS3.h"
#include "DCMotor.h"
#include "PwmLdd2.h"
#include "TU2.h"
#include "WAIT1.h"

#define STEPS_AUFLADEN 1000
#define STEPS_ENTLADEN 1200
#define ZU 1
#define AUF 2
#define HINAUF 1
#define HINUNTER 2
#define WAITTIME 2

void initSMFoerderband(void){

	Band_STEP_ClrVal(Band_STEP_DeviceData);
	Band_DIR_SetVal(Band_DIR_DeviceData);
	Band_MS1_ClrVal(Band_MS1_DeviceData);
	Band_MS2_ClrVal(Band_MS2_DeviceData);
	Band_MS3_ClrVal(Band_MS3_DeviceData);

}

void startAufladevorgang(void){

	runDCMotor(ZU);
	WAIT1_WaitOSms(3000);

	runSMFoerderband(STEPS_AUFLADEN,HINAUF);
	WAIT1_WaitOSms(3000);

	runSMFoerderband(STEPS_AUFLADEN,HINUNTER);
	WAIT1_WaitOSms(3000);

	runDCMotor(AUF);



}


void runDCMotor(int dir){//1 = zu; 2 = auf
	int i = 0;

	if(dir == ZU){
//Anzupassen!!!
	for(i=255;i>=0;i--){

		DCMotor_SetRatio8(i);
		WAIT1_WaitOSms(100);

		}

	}

	else if (dir == AUF){

	}

}

void runSMFoerderband(int steps, int dir){

	if(dir == HINAUF){

		Band_DIR_SetVal(Band_DIR_DeviceData);

	}else{

		Band_DIR_ClrVal(Band_DIR_DeviceData);

	}

	for(steps;steps>0;steps--){

		WAIT1_WaitOSms(WAITTIME);
		Band_STEP_NegVal(Band_STEP_DeviceData);
		WAIT1_WaitOSms(WAITTIME);
		Band_STEP_NegVal(Band_STEP_DeviceData);
		LED_GREEN_Neg();

	}



}






