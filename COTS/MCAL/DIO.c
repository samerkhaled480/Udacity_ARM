/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *
 -------------------------------------------------------------------------------------------------------------------
 *         File: DIO.c
 *       Module: DIO
 *
 *  Description:  Header file Contains all Functions Definitions of DIO Driver
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *                                         INCLUDES
 *********************************************************************************************************************/

#include "MCU_HW.h"
#include "DIO.h"

/**********************************************************************************************************************
 *                                 GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/************************************************************************************
* Service Name: DIO_WriteChannel
* Parameters (in): 	PortId , ChannelId , Level 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void DIO_WriteChannel(DIO_PortType PortID,DIO_ChannelType ChannelId, DIO_LevelType Level)
{
	if(Level == STD_LOW)
	{
		switch(PortID)
		{
		case PORTA: GPIO_DATA(	GPIO_PORTA	) &= (~(1<< ChannelId)); break;
		case PORTB: GPIO_DATA(	GPIO_PORTB	) &= (~(1<< ChannelId)); break;
		case PORTC: GPIO_DATA(	GPIO_PORTC	) &= (~(1<< ChannelId)); break;
		case PORTD: GPIO_DATA(	GPIO_PORTD	) &= (~(1<< ChannelId)); break;
		case PORTE: GPIO_DATA(	GPIO_PORTE	) &= (~(1<< ChannelId)); break;
		case PORTF: GPIO_DATA(	GPIO_PORTF	) &= (~(1<< ChannelId)); break;
		}
	}
	else if(Level == STD_HIGH)
	{
		switch(PortID)
		{
		case PORTA: GPIO_DATA(	GPIO_PORTA	) |= (1<< ChannelId); break;
		case PORTB: GPIO_DATA(	GPIO_PORTB	) |= (1<< ChannelId); break;
		case PORTC: GPIO_DATA(	GPIO_PORTC	) |= (1<< ChannelId); break;
		case PORTD: GPIO_DATA(	GPIO_PORTD	) |= (1<< ChannelId); break;
		case PORTE: GPIO_DATA(	GPIO_PORTE	) |= (1<< ChannelId); break;
		case PORTF: GPIO_DATA(	GPIO_PORTF	) |= (1<< ChannelId); break;
		}
	}
}

/************************************************************************************
* Description       : Function to return the value of the specified DIO channel.
* Parameters (in)   : Port-Id , CH_Id 
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : DIO_LevelType or 0xff incase of wrong port id 
************************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_PortType PortID,DIO_ChannelType ChannelId)
{
	
	switch(PortID)
	{
	case PORTA: return ( (uint8) GPIO_DATA(	GPIO_PORTA	) & (1<< ChannelId));
	case PORTB: return ( (uint8) GPIO_DATA(	GPIO_PORTB	) & (1<< ChannelId));
	case PORTC: return ( (uint8) GPIO_DATA(	GPIO_PORTC	) & (1<< ChannelId));
	case PORTD: return ( (uint8) GPIO_DATA(	GPIO_PORTD	) & (1<< ChannelId));
	case PORTE: return ( (uint8) GPIO_DATA(	GPIO_PORTE	) & (1<< ChannelId));
	case PORTF: return ( (uint8) GPIO_DATA(	GPIO_PORTF	) & (1<< ChannelId));
	}
	return 0xff;
}

/************************************************************************************
* Description       : Function to flip the level of a channel and return the level of the channel after flip.
* Parameters (in)   : Port_d , CH_Id
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : DIO_LevelType
************************************************************************************/
DIO_LevelType DIO_FlipChannel(DIO_PortType PortID,DIO_ChannelType ChannelId)
{
	switch(PortID)
	{
	case PORTA: GPIO_DATA(	GPIO_PORTA	) ^= (1<< ChannelId); break;
	case PORTB: GPIO_DATA(	GPIO_PORTB	) ^= (1<< ChannelId); break;
	case PORTC: GPIO_DATA(	GPIO_PORTC	) ^= (1<< ChannelId); break;
	case PORTD: GPIO_DATA(	GPIO_PORTD	) ^= (1<< ChannelId); break;
	case PORTE: GPIO_DATA(	GPIO_PORTE	) ^= (1<< ChannelId); break;
	case PORTF: GPIO_DATA(	GPIO_PORTF	) ^= (1<< ChannelId); break;
	}
	return DIO_ReadChannel(PortID , ChannelId);
}

/************************************************************************************
* Description       : Function to return the value of the specified DIO Port.
* Parameters (in)   : PortID - ID of DIO Port.
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : DIO_PortLevelType of 0xff incase of wrong PORTID value
************************************************************************************/
DIO_PortLevelType DIO_ReadPort(DIO_PortType PortID)
{
 	switch(PortID)
	{
	case PORTA: return  GPIO_DATA(	GPIO_PORTA	);
	case PORTB: return  GPIO_DATA(	GPIO_PORTB	);
	case PORTC: return  GPIO_DATA(	GPIO_PORTC	);
	case PORTD: return  GPIO_DATA(	GPIO_PORTD	);
	case PORTE: return  GPIO_DATA(	GPIO_PORTE	);
	case PORTF: return  GPIO_DATA(	GPIO_PORTF	);
	}
  return 0xff;  
}

/************************************************************************************
* Description       : Function to set a level of a Port
* Parameters (in)   : PortID - ID of DIO Port.
* Parameters (in)   : Level - Value to be written.
* Parameters (inout): None
* Parameters (out)  : None
* Return value      : None
************************************************************************************/
void DIO_WritePort(DIO_PortType PortID,DIO_PortLevelType Level)
{
	switch(PortID)
	{
	case PORTA: GPIO_DATA(	GPIO_PORTA	) = Level;break;
	case PORTB: GPIO_DATA(	GPIO_PORTB	) = Level;break;
	case PORTC: GPIO_DATA(	GPIO_PORTC	) = Level;break;
	case PORTD: GPIO_DATA(	GPIO_PORTD	) = Level;break;
	case PORTE: GPIO_DATA(	GPIO_PORTE	) = Level;break;
	case PORTF: GPIO_DATA(	GPIO_PORTF	) = Level;break;
	}
    
}


/*

channeltype = pins 
ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7

porttype = port name 
PORTA,B,C,D..

LEVEL_TYPE = high or low

PORT_LEVEL_TYPE = 0:255 per port as port is 8bit register 


*/
/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
