/*
 * SchrittmotorLenkung.c
 *
 *  Created on: 21.03.2016
 *      Author: Klaus Jordan
 */
#include "SchrittmotorLenkung.h"
#include "Lenk_STEP.h"
#include "Lenk_DIR.h"
#include "Lenk_MS1.h"
#include "Lenk_MS2.h"
#include "Lenk_MS3.h"
#include "LED_GREEN.h"
#include "LEDpin1.h"
#include "WAIT1.h"

#define UEBERSETZUNG (74/34) // Übersetzung der Zahnräder
#define SCHRITTWINKEL 1.8		// Schrittwinkel Schrittmotor
#define WAITTIME 2 // Wert für WAIT
int aktuellePosStep;
int pos;
void initSMLenkung(void){

	Lenk_STEP_ClrVal(Lenk_STEP_DeviceData);
	Lenk_DIR_SetVal(Lenk_DIR_DeviceData);//Vorwärts Initialisierung
	Lenk_MS1_ClrVal(Lenk_MS1_DeviceData);
	Lenk_MS2_ClrVal(Lenk_MS2_DeviceData);
	Lenk_MS3_ClrVal(Lenk_MS3_DeviceData);
	LED_GREEN_Neg();
}

void setSMLenkung(void){

	for(;;){

	for(pos=0;pos<=10000;pos++){


	WAIT1_WaitOSms(2);
	Lenk_STEP_NegVal(Lenk_STEP_DeviceData);
	WAIT1_WaitOSms(2);
	Lenk_STEP_NegVal(Lenk_STEP_DeviceData);
	LED_GREEN_Neg();

	}
	WAIT1_WaitOSms(2000);
	Lenk_DIR_NegVal(Lenk_DIR_DeviceData);

	for(pos;pos>=0;pos--){

	Lenk_STEP_NegVal(Lenk_STEP_DeviceData);
	WAIT1_WaitOSms(2);
	Lenk_STEP_NegVal(Lenk_STEP_DeviceData);
	WAIT1_WaitOSms(2);
	}
	Lenk_DIR_NegVal(Lenk_DIR_DeviceData);
	}
}

int setLenkung(int inputPos){

	if(inputPos>90 && inputPos<-90){ // Überprüfung, ob inputPos im gültigen Bereich ist

		return -1;

	}

	int8_t inputPosStep = inputPos/(UEBERSETZUNG*SCHRITTWINKEL) ;//intPos umgerechnet in STEPs
	int8_t aenderungStep = aktuellePosStep-inputPosStep;

	if(aenderungStep<0){

		Lenk_DIR_PutVal(Lenk_DIR_DeviceData,0); //Drehrichtung einstellen
		setWinkel(aenderungStep*(-1));// Zahl positiv machen

	}else if(aenderungStep>0){

		Lenk_DIR_PutVal(Lenk_DIR_DeviceData,1); //Drehrichtung einstellen
		setWinkel(aenderungStep);
	}

	aktuellePosStep += aenderungStep;

	return 0;

}

void setWinkel(int steps){


	for(steps;steps>0;steps--){

		WAIT1_WaitOSms(WAITTIME);
		Lenk_STEP_NegVal(Lenk_STEP_DeviceData);
		WAIT1_WaitOSms(WAITTIME);
		Lenk_STEP_NegVal(Lenk_STEP_DeviceData);
		LED_GREEN_Neg();

	}

}
