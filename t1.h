/*
 * t1.h
 *
 *   Description: Header file for the timer 1 driver
 *      Author: Ahmed zakria
 */

#ifndef T1_H_
#define T1_H_
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#include "T1_PBcfg.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* timer 1 configurations for  */


#define NULL (void*)0

typedef enum  // Select bite
{
	Normal_PIN,Comapre1A_PIN,Comapre1B_PIN,Caputre_PIN
}Mode_pin;

typedef enum  // Select bite
{
	Normal,PWM_8bit,PWM_9bit,Comapre_mode,Caputre_unit,fast_PWM_IC,/* by use capture unit*/
	fast_PWM__compare/* by use compare mode*/
}Mode_operation;
typedef enum  // Select bite
{
	Normal_port,toggle,set_output_low,set_output_high
}Mode_compare; // for channel a or b
typedef enum  // Select bite
{
	falling_dge , rising_edge
}Input_capture_edge; // for edge select
typedef enum  // Select bite
{
	no_clock,no_prscaling,clock_8,clock_64,clock_256,clock_1024,externalclok_fallingedge,externalclok_risingedge
}clock_select; // for clock source
typedef enum  // Select bite
{
	over_flow, compareA, compareB, caputre
}tmier1_flag; // for clock source
typedef struct
{
	/* Member contains the voltage channel belongs to */
	Mode_operation Mode;

	/* Member contains the result of the Channel is  to where*/
	Mode_compare compare;
	/* Member contains the trigger timer to work on positive edge the Channel is  to where*/
	Input_capture_edge edge;
	clock_select clock;
	tmier1_flag flag;
	uint16 max; // MAX VALUE
	uint16 Dutycycle; // VALUE TO MAKE COMPARE OR DUTY
	uint8 start ; // Initial VALUETO START COUNTING
	Mode_pin PIN;
}timerConfig_type;

/* Extern ADC structures to be used by to initlize adc */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* */
void timer1_init(timerConfig_type * config);

/* to select mode of timer*/

/*
 * Description: Function to set the Call Back function address.
 */
void Icu_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 */
void Icu_setEdgeDetectionType(const Input_capture_edge edgeType);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 Icu_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void Icu_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void Icu_DeInit(void);
/* Extern ADC structures to be used by to initlize adc */

extern const timerConfig_type T1_config;

#endif /* T1_H_ */
