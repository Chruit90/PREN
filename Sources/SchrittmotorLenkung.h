/*
 * SchrittmotorLenkung.h
 *
 *  Created on: 21.03.2016
 *      Author: Klaus Jordan
 */

#ifndef SOURCES_SCHRITTMOTORLENKUNG_H_
#define SOURCES_SCHRITTMOTORLENKUNG_H_
//Initialiserung der Lenkung
void initSMLenkung(void);
/* @brief 	Berechnung Anzahl Änderungssteps und Aufruf der Funktion setWinkel

   @param
   	   	   inputPos: Gewünschte Lenkungsposition in Grad (-90° bis 90°)



*/
int setLenkung(int inputPos);

void setWinkel(int aenderungPos);




#endif /* SOURCES_SCHRITTMOTORLENKUNG_H_ */
