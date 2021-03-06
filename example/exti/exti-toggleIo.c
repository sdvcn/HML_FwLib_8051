/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:a example which shows how to use HML_FwLib_8051 to toggle P10 state when EXTI1 is trigged
 * @Test-board:TS51-V2.0
 * @Test-mcu:STC89C52RC
 * @Version:V0
 */

#include "conf.h"

/*
 * @Prototype:void sys_init(void)
 * @Parameter:
 * @Ret-val:
 * @Note:initial MCU
 */
void sys_init(void)
{
    EXTI_configTypeDef ec;
    
    ec.mode     = EXTI_mode_fallEdge;
    ec.priority = DISABLE;
    EXTI_config(PERIPH_EXTI_1,&ec);
    EXTI_cmd(PERIPH_EXTI_1,ENABLE);
    enableAllInterrupts();
    
    GPIO_configPortValue(PERIPH_GPIO_1,0xFF);
}

/* ----- @main ----- */
void main(void)
{
    sys_init();
    while(true);
}

/*
 * @Prototype:void exti1_isr(void)
 * @Parameter:
 * @Ret-val:
 * @Note:interrupt handle function for EXTI1
 */
void exti1_isr(void) __interrupt IE1_VECTOR
{
    GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_2);
}

