/*
 * ReadSend.c
 *
 *  Created on: 07.04.2016
 *      Author: Klaus Jordan
 */

#include "ReadSend.h"
#include "Pwm1.h"
#include "PwmLdd1.h"
#include "LED_GREEN.h"

#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "LED_BLUE.h"

#define BUFFERSIZE 4
#define MAX_VORWAERTS 100
#define MAX_RUECKWAERTS -100

char buffer[BUFFERSIZE];
int head;// Zeigt auf neustes Element
int tail;// Zeigt auf ältestes Element

void read(void){

	while(buffer[head] != -128){

		head = (head+1) % BUFFERSIZE;
		CLS1_ReadChar(buffer[head]);

		if(head==tail){

			tail = (tail+1) % BUFFERSIZE;
		}

	}



}

void datenAuslesen(void){

  if(buffer[tail]==1){//Input Fortbewegung

  		if(buffer[tail+1]>=-90 && buffer[tail+1]<=90 && buffer[tail+2]>= MAX_VORWAERTS && buffer[tail+2]<=MAX_RUECKWAERTS){

	  		inputPosLenkung = buffer[tail+1];
	  		inputGeschwindigkeit = buffer[tail+2];

  		}

  	 }else
	  if(buffer[tail]==2){//Input Start Aufladevorgang


  		if(buffer[tail+1]==0 && buffer[tail+2]==0){

  			//startAufladevorgang
  			LED_GREEN_Neg();

  		}else{

  			//Fehler!
  		}

  }else
	  if(buffer[tail] == 3){//Input Start Abladevorgang


	  		if(buffer[tail+1]==0 && buffer[tail+2]==0){

	  			//startAbladevorgang
	  			LED_BLUE_Neg();


	  		}else{

	  			//Fehler!
	  		}

	  }else{

		  	  //Fehler!
	  }


}

void clearBuffer(void){

	int i;

	for(i;i<BUFFERSIZE;i++){

		buffer[i] = 0;

	}

	tail=0;
	head=0;

}
