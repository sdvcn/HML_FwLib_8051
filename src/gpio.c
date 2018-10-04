/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operate on-chip GPIO module
 * @Required-compiler:SDCC
 * @Support-mcu:Intel MCS-51 based microprocessors
 * @Version:V0
 */

#include "gpio.h"

#ifdef ___COMPILE_GPIO___

/*
 * @Prototype:void GPIO_configBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin,FunctionalState f)
 * @Parameter:
 *  (1)gpio:target GPIO port
 *  (2)pin:target GPIO pin
 *  (3)f:expected level state
 * @Ret-val:
 * @Note:configure specified pin as expected state
 */
void GPIO_configBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin,FunctionalState f)
{
	if(f == RESET)
	{
		GPIO_resetBitValue(gpio,pin);
	}
	else
	{
		GPIO_setBitValue(gpio,pin);
	}
}

/*
 * @Prototype:void GPIO_configPort(PERIPH_GPIO gpio,byte val)
 * @Parameter:
 *  (1)gpio:target GPIO port
 *  (2)val:expected port value
 * @Ret-val:
 * @Note:configure port value
 */
void GPIO_configPort(PERIPH_GPIO gpio,byte val)
{
	switch(gpio)
	{
		case PERIPH_GPIO_0:P0 = val;break;
		case PERIPH_GPIO_1:P1 = val;break;
		case PERIPH_GPIO_2:P2 = val;break;
		case PERIPH_GPIO_3:P3 = val;break;
		default:break;
	}
}

/*
 * @Prototype:FunctionalState GPIO_getBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
 * @Parameter:
 *  (1)gpio:target GPIO port
 *  (2)pin:target GPIO pin
 * @Ret-val:
 * @Note:get value of target pin
 */
FunctionalState GPIO_getBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
{
	switch(gpio)
	{
		case PERIPH_GPIO_0:return (P0 & pin);break;
		case PERIPH_GPIO_1:return (P1 & pin);break;
		case PERIPH_GPIO_2:return (P2 & pin);break;
		case PERIPH_GPIO_3:return (P3 & pin);break;
	}
	
	return RESET;
}

/*
 * @Prototype:unsigned char GPIO_getPortValue(PERIPH_GPIO gpio)
 * @Parameter:
 *  (1)gpio:target GPIO port
 * @Ret-val:
 * @Note:get value of target port
 */
unsigned char GPIO_getPortValue(PERIPH_GPIO gpio)
{
	switch(gpio)
	{
		case PERIPH_GPIO_0:return P0;break;
		case PERIPH_GPIO_1:return P1;break;
		case PERIPH_GPIO_2:return P2;break;
		case PERIPH_GPIO_3:return P3;break;
	}
	
	return 0x00;
}

/*
 * @Prototype:void GPIO_resetBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
 * @Parameter:
 *  (1)gpio:target GPIO port
 *  (2)pin:target pin
 * @Ret-val:
 * @Note:reset value of target pin
 */
void GPIO_resetBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
{
	switch(gpio)
	{
		case PERIPH_GPIO_0:P0 = P0 & (~pin);break;
		case PERIPH_GPIO_1:P1 = P1 & (~pin);break;
		case PERIPH_GPIO_2:P2 = P2 & (~pin);break;
		case PERIPH_GPIO_3:P3 = P3 & (~pin);break;
		default:break;
	}
}

/*
 * @Prototype:void GPIO_setBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
 * @Parameter:
 *  (1)gpio:target GPIO port
 *  (2)pin:target pin
 * @Ret-val:
 * @Note:set value of target pin
 */
void GPIO_setBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
{
	switch(gpio)
	{
		case PERIPH_GPIO_0:P0 = P0 | pin;break;
		case PERIPH_GPIO_1:P1 = P1 | pin;break;
		case PERIPH_GPIO_2:P2 = P2 | pin;break;
		case PERIPH_GPIO_3:P3 = P3 | pin;break;
		default:break;
	}
}

/*
 * @Prototype:void GPIO_toggleBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
 * @Parameter:
 *  (1)gpio:target GPIO port
 *  (2)pin:target pin
 * @Ret-val:
 * @Note:change value of target pin into opposite state
 */
void GPIO_toggleBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin)
{
	switch(gpio)
	{
		case PERIPH_GPIO_0:P0 = (P0 & (~pin)) | ((~P0) & pin);break;
		case PERIPH_GPIO_1:P1 = (P1 & (~pin)) | ((~P1) & pin);break;
		case PERIPH_GPIO_2:P2 = (P2 & (~pin)) | ((~P2) & pin);break;
		case PERIPH_GPIO_3:P3 = (P3 & (~pin)) | ((~P3) & pin);break;
		default:break;
	}
}

#endif