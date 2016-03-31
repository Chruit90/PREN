/* ###################################################################
**     Filename    : main.c
**     Project     : OSs
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-02-17, 18:20, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "LED_BLUE.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "Lenk_STEP.h"
#include "Lenk_DIR.h"
#include "Lenk_MS1.h"
#include "Lenk_MS2.h"
#include "Lenk_MS3.h"
#include "DCMotor.h"
#include "PwmLdd2.h"
#include "TU2.h"
#include "WAIT1.h"
#include "FRTOS1.h"
#include "Pwm1.h"
#include "PwmLdd1.h"
#include "LED_GREEN.h"
#include "TU1.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "BLDC.h"
#include "CS1.h"
#include "CLS1.h"
#include "KSDK1.h"
#include "UTIL1.h"
#include "BrushlessMotor.h"
#include "SchrittmotorLenkung.h"
#include "GreiferMotor.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

#include "RTOS.h"
uint8_t c1 = 0;
uint8_t c2 = 0;
uint8_t a1 = 0;
uint8_t a2 = 0;


/*
 * TASKS IMPLEMENTIEREN
 * */
void rTask(void* parameters)
{
	for (;;)
	{
		LED_GREEN_Neg();
		RTOS_Wait(500);
	}
}
void gTask(void* parameters)
{
	for (;;)
	{ for(c2;c2>=0;c2--){
		//LED_GREEN_Neg();
		RTOS_Wait(500);
	}
	}
}
void bTask(void* parameters)
{
	for (;;){

		for(c1;c1 >=0;c1--){
		//LED_BLUE_Neg();
		RTOS_Wait(500);

		}
	}
}

void writeTask(void* parameters){
	  CLS1_Init();
	  LED_GREEN_Neg();
	  for(;;){

		  CLS1_ReadChar(&c1);

		  if(c1!=0){
			  CLS1_SendNum8u(c1,CLS1_GetStdio()->stdOut);
		  CLS1_ReadChar(&c2);

		  if(c1==1){
			  CLS1_SendNum8u(c2+1,CLS1_GetStdio()->stdOut);

			  }


		  else if (c1==2){
			  CLS1_SendNum8u(c2+2,CLS1_GetStdio()->stdOut);

		  	  }
		  }

	  c1 =0;
	  }

	  }
	 // for(;;){
	  //uint8_t i = 0;

		// for(i=0;i<20;i++){
			 // CLS1_SendNum8u(i, CLS1_GetStdio()->stdOut);
			 // WAIT1_WaitOSms(1000);
			 // LED_GREEN_Neg();
		 // }

		 //for(i=20;i>0;i--){

			 // CLS1_SendNum8u(i, CLS1_GetStdio()->stdOut);
			 // WAIT1_WaitOSms(1000);
			 // LED_BLUE_Neg();

		  		 // }

	 // }


/*
 * RTOS FUEGT TASKS IN SCHEDULER EIN
 * */
void init(void)
{

	//RTOS_AddTask(rTask, "rTask");
	//WAIT1_Waitms(100);
	//RTOS_AddTask(gTask, "gTask");
	//RTOS_AddTask(bTask, "bTask");
	RTOS_AddTask(writeTask,"writeTask");
	RTOS_Init();

}


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  	 // init();


	//runDCMotor();
	//initSMLenkung();
  	 runBLDC();
	//setSMLenkung();




  //WAIT1_Waitms(100);

 // RTOS_AddTask(gTask, "gTask");



  while (1)
  {
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
