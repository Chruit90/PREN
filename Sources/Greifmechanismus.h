/*
 * Greifmechanismus.h
 *
 *  Created on: 06.04.2016
 *      Author: Klaus Jordan
 */

#ifndef SOURCES_GREIFMECHANISMUS_H_
#define SOURCES_GREIFMECHANISMUS_H_

// Initialisiert den Förderband-Schrittmotor auf default-Werte
void initSMFoerderband(void);

// Start des Aufladevorganges
void startAufladevorgang(void);

// Startet DCMotor des Greifers
void runDCMotor(int dir);


//Startet Förderband-Schrittmotor
void runSMFoerderband(int steps, int dir);



#endif /* SOURCES_GREIFMECHANISMUS_H_ */
