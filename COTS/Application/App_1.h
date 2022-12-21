
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  APP_1.h
 *       Module:  APP_1
 *
 *  Description:  header file for Application 
 *  
 *********************************************************************************************************************/
#ifndef __APP_1_H__
#define __APP_1_H__

/**********************************************************************************************************************
- * INCLUDES
- *********************************************************************************************************************/

#include "NVIC.h"
#include "PORT.h"
#include "DIO.h"
#include "SYSTICK.h"

#include "LED.h"


/*******************************************************************************
 *                              Extern variabes 		                           *
 *******************************************************************************/
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/******************************************************************************
* \Syntax          :                                    
* \Description     : 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void my_systick_isr(void);


/******************************************************************************
* \Syntax          :                                    
* \Description     : 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Define_Duty(uint32 ON_Timr ,uint32 OFF_Time);

	

#endif  /* APP_1_H */

/**********************************************************************************************************************
 *  END OF FILE: APP_1.h
 *********************************************************************************************************************/