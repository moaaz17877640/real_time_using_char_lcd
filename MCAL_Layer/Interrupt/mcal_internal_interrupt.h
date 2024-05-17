/* 
 * File:   mcal_internal_interrupt.h
 * Author:Moaaz elmahi
 *
 * Created on 02 August 2023, 20:25
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/************************ Includes ************************/
#include "mcal_interrupt_config.h"

/************************  Macro Declaration ************************/
 

/************************  Macro Function Declaration ************************/
#if ADC_INTERRUPT_FEATURE_ENABLE_CFG == INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the ADC module */
#define ADC_Interrupt_Disable()             (PIE1bits.ADIE = 0)
/* this routine sets interrupt enable for the ADC module */
#define ADC_Interrupt_Enable()              (PIE1bits.ADIE = 1)
/* this routine clear interrupt flag for the ADC module */
#define ADC_Interrupt_Flag_Clear()          (PIR1bits.ADIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the ADC interrupt priority to be high priority */
#define ADC_HighPrioritySet()      (IPR1bits.ADIP = 1)
/* this routine set the ADC interrupt priority to be low priority */
#define ADC_LowPrioritySet()       (IPR1bits.ADIP = 0)
#endif
#endif

#if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the TIMER0 module */
#define TIMER0_INTERRUPT_DISABLE()             (INTCONbits.TMR0IE = 0)
/* this routine sets interrupt enable for the TIMER0 module */
#define TIMER0_INTERRUPT_ENABLE()              (INTCONbits.TMR0IE = 1)
/* this routine clear interrupt flag for the TIMER0 module */
#define TIMER0_CLEAR_FLAG()          (INTCONbits.TMR0IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the TIMER0 interrupt priority to be high priority */
#define TIMER0_INTERRUPT_HIGH_PRIORITY()      (INTCON2bits.TMR0IP = 1)
/* this routine set the TIMER0 interrupt priority to be low priority */
#define TIMER0_INTERRUPT_LOW_PRIORITY()       (INTCON2bits.TMR0IP = 0)
#endif
#endif
//===================================================
//===================================================
#if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the TIMER0 Module */
#define TIMER0_InterruptDisable()         (INTCONbits.TMR0IE = 0)
/* This routine sets the interrupt enable for the TIMER0 Module */
#define TIMER0_InterruptEnable()          (INTCONbits.TMR0IE = 1)
/* This routine clears the interrupt flag for the TIMER0 Module */
#define TIMER0_InterruptFlagClear()       (INTCONbits.TMR0IF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/* This routine set the TIMER0 Module Interrupt Priority to be High priority */
#define TIMER0_HighPrioritySet()          (INTCON2bits.TMR0IP = 1)
/* This routine set the TIMER0 Module Interrupt Priority to be Low priority */
#define TIMER0_LowPrioritySet()           (INTCON2bits.TMR0IP = 0)
#endif
#endif
//===================================================

//===================================================
#if TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the TIMER1 module */
#define TIMER1_INTERRUPT_DISABLE()             (PIE1bits.TMR1IE =0)
/* this routine sets interrupt enable for the TIMER1 module */
#define TIMER1_INTERRUPT_ENABLE()              (PIE1bits.TMR1IE =1)
/* this routine clear interrupt flag for the TIMER1 module */
#define TIMER1_CLEAR_FLAG()          (PIR1bits.TMR1IF = 0 )

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the TIMER1 interrupt priority to be high priority */
#define TIMER1_INTERRUPT_HIGH_PRIORITY()      (IPR1bits.TMR1IP =1)
/* this routine set the TIMER1 interrupt priority to be low priority */
#define TIMER1_INTERRUPT_LOW_PRIORITY()       (IPR1bits.TMR1IP =0 )
#endif
#endif

#if TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the TIMER2 module */
#define TIMER2_INTERRUPT_DISABLE()             (PIE1bits.TMR2IE =0)
/* this routine sets interrupt enable for the TIMER2 module */
#define TIMER2_INTERRUPT_ENABLE()              (PIE1bits.TMR2IE =1)
/* this routine clear interrupt flag for the TIMER2 module */
#define TIMER2_CLEAR_FLAG()          (PIR1bits.TMR2IF = 0 )

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the TIMER2 interrupt priority to be high priority */
#define TIMER2_INTERRUPT_HIGH_PRIORITY()      (IPR1bits.TMR2IP =1)
/* this routine set the TIMER2 interrupt priority to be low priority */
#define TIMER2_INTERRUPT_LOW_PRIORITY()       (IPR1bits.TMR2IP =0 )
#endif
#endif

#if TIMER3_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the TIMER3 module */
#define TIMER3_INTERRUPT_DISABLE()             (PIE2bits.TMR3IE =0)
/* this routine sets interrupt enable for the TIMER3 module */
#define TIMER3_INTERRUPT_ENABLE()              (PIE2bits.TMR3IE =1)
/* this routine clear interrupt flag for the TIMER3 module */
#define TIMER3_CLEAR_FLAG()          (PIR2bits.TMR3IF = 0 )

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the TIMER3 interrupt priority to be high priority */
#define TIMER3_INTERRUPT_HIGH_PRIORITY()      (IPR2bits.TMR3IP =1)
/* this routine set the TIMER3 interrupt priority to be low priority */
#define TIMER3_INTERRUPT_LOW_PRIORITY()       (IPR2bits.TMR3IP =0 )
#endif
#endif

#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the CCP1 module */
#define CCP1_INTERRUPT_DISABLE()             (PIE1bits.CCP1IE =0)
/* this routine sets interrupt enable for the CCP1 module */
#define CCP1_INTERRUPT_ENABLE()              (PIE1bits.CCP1IE =1)
/* this routine clear interrupt flag for the CCP1 module */
#define CCP1_CLEAR_FLAG()          (PIR1bits.CCP1IF = 0 )

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the CCP1 interrupt priority to be high priority */
#define CCP1_INTERRUPT_HIGH_PRIORITY()      (IPR1bits.CCP1IP =1)
/* this routine set the CCP1 interrupt priority to be low priority */
#define CCP1_INTERRUPT_LOW_PRIORITY()       (IPR1bits.CCP1IP =0 )
#endif
#endif
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the CCP module */
#define CCP2_INTERRUPT_DISABLE()             (PIE2bits.CCP2IE =0)
/* this routine sets interrupt enable for the CCP module */
#define CCP2_INTERRUPT_ENABLE()              (PIE2bits.CCP2IE =1)
/* this routine clear interrupt flag for the CCP2 module */
#define CCP2_CLEAR_FLAG()          (PIR2bits.CCP2IF = 0 )

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the CCP2 interrupt priority to be high priority */
#define CCP2_INTERRUPT_HIGH_PRIORITY()      (IPR2bits.CCP2IP =1)
/* this routine set the CCP2 interrupt priority to be low priority */
#define CCP2_INTERRUPT_LOW_PRIORITY()       (IPR2bits.CCP2IP =0 )
#endif
#endif

#if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the EUSART_TX module */
#define EUSART_TX_INTERRUPT_DISABLE()             (PIE1bits.TXIE =0)
/* this routine sets interrupt enable for the EUSART_TX module */
#define EUSART_TX_INTERRUPT_ENABLE()              (PIE1bits.TXIE =1)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the EUSART_TX interrupt priority to be high priority */
#define EUSART_TX_INTERRUPT_HIGH_PRIORITY()      (IPR1bits.TXIP =1)
/* this routine set the EUSART_TX interrupt priority to be low priority */
#define EUSART_TX_INTERRUPT_LOW_PRIORITY()       (IPR1bits.TXIP =0 )
#endif
#endif

#if EUSART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the EUSART_RX module */
#define EUSART_RX_INTERRUPT_DISABLE()             (PIE1bits.RCIE =0)
/* this routine sets interrupt enable for the EUSART_RX module */
#define EUSART_RX_INTERRUPT_ENABLE()              (PIE1bits.RCIE =1)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the EUSART_RX interrupt priority to be high priority */
#define EUSART_RX_INTERRUPT_HIGH_PRIORITY()      (IPR1bits.RCIP =1)
/* this routine set the EUSART_RX interrupt priority to be low priority */
#define EUSART_RX_INTERRUPT_LOW_PRIORITY()       (IPR1bits.RCIP =0 )
#endif
#endif

#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the mssp_i2c and bus collision */
#define MSSP_12C_INTERRUPT_DISABLE()                (PIE1bits.SSPIE =0)
#define MSSP_12C_BUS_COLLISION_INTERRUPT_DISABLE()  (PIE2bits.BCLIE = 0)

/* this routine set interrupt enable for the mssp_i2c and bus collision */
#define MSSP_12C_INTERRUPT_ENABLE()                (PIE1bits.SSPIE =1)
#define MSSP_12C_BUS_COLLISION_INTERRUPT_ENABLE()  (PIE2bits.BCLIE = 1)
/* this routine clear interrupt flag for the mssp_i2c and bus collision */
#define MSSP_12C_CLEAR_FLAG() (PIR1bits.SSPIF = 0)
#define MSSP_12C_BUS_COLLISION_CLEAR_FLAG() (PIR2bits.BCLIF = 0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the mssp_i2c and bus collision  interrupt priority to be high priority */
#define MSSP_I2C_INTERRUPT_HIGH_PRIORITY()                   (IPR1bits.SSPIP =1)
#define MSSP_12C_BUS_COLLISION_INTERRUPT_HIGH_PRIORITY()      (IPR2bits.BCLIP =1)

/* this routine set the mssp_i2c and bus collision  interrupt priority to be LOW priority */
#define MSSP_I2C_INTERRUPT_LOW_PRIORITY()                   (IPR1bits.SSPIP =0)
#define MSSP_12C_BUS_COLLISION_INTERRUPT_LOW_PRIORITY()      (IPR2bits.BCLIP =0)
#endif
#endif


#if MSSP_SPI_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/* this routine clear interrupt enable for the SPI module */
#define MSSP_SPI_INTERRUPT_DISABLE()             (PIE1bits.SSPIE =0)
/* this routine sets interrupt enable for the SPI module */
#define MSSP_SPI_INTERRUPT_ENABLE()              (PIE1bits.SSPIE=1)
/* this routine clear interrupt flag for the SPI module */
#define MSSP_SPI_CLEAR_FLAG()          (PIR1bits.SSPIF = 0 )

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/* this routine set the SPI interrupt priority to be high priority */
#define MSSP_SPI_INTERRUPT_HIGH_PRIORITY()      (IPR1bits.SSPIP =1)
/* this routine set the SPI interrupt priority to be low priority */
#define MSSP_SPI_INTERRUPT_LOW_PRIORITY()       (IPR1bits.SSPIP =0 )
#endif
#endif
/************************  Data Type Declaration ************************/
 

/************************  Software interface Declaration ************************/
 

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

