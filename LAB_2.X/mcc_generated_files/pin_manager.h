/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB� Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC18F26K22
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set CCP4 aliases
#define CCP4_TRIS               TRISB0
#define CCP4_LAT                LATB0
#define CCP4_PORT               PORTBbits.RB0
#define CCP4_WPU                WPUB0
#define CCP4_ANS                ANSB0
#define CCP4_SetHigh()    do { LATB0 = 1; } while(0)
#define CCP4_SetLow()   do { LATB0 = 0; } while(0)
#define CCP4_Toggle()   do { LATB0 = ~LATB0; } while(0)
#define CCP4_GetValue()         PORTBbits.RB0
#define CCP4_SetDigitalInput()    do { TRISB0 = 1; } while(0)
#define CCP4_SetDigitalOutput()   do { TRISB0 = 0; } while(0)

#define CCP4_SetPullup()    do { WPUB0 = 1; } while(0)
#define CCP4_ResetPullup()   do { WPUB0 = 0; } while(0)
#define CCP4_SetAnalogMode()   do { ANSB0 = 1; } while(0)
#define CCP4_SetDigitalMode()   do { ANSB0 = 0; } while(0)
// get/set IO_RC0 aliases
#define IO_RC0_TRIS               TRISC0
#define IO_RC0_LAT                LATC0
#define IO_RC0_PORT               PORTCbits.RC0
#define IO_RC0_SetHigh()    do { LATC0 = 1; } while(0)
#define IO_RC0_SetLow()   do { LATC0 = 0; } while(0)
#define IO_RC0_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define IO_RC0_GetValue()         PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS               TRISC1
#define IO_RC1_LAT                LATC1
#define IO_RC1_PORT               PORTCbits.RC1
#define IO_RC1_SetHigh()    do { LATC1 = 1; } while(0)
#define IO_RC1_SetLow()   do { LATC1 = 0; } while(0)
#define IO_RC1_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define IO_RC1_GetValue()         PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS               TRISC2
#define IO_RC2_LAT                LATC2
#define IO_RC2_PORT               PORTCbits.RC2
#define IO_RC2_ANS                ANSC2
#define IO_RC2_SetHigh()    do { LATC2 = 1; } while(0)
#define IO_RC2_SetLow()   do { LATC2 = 0; } while(0)
#define IO_RC2_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define IO_RC2_GetValue()         PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define IO_RC2_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()   do { ANSC2 = 0; } while(0)
// get/set SCK1 aliases
#define SCK1_TRIS               TRISC3
#define SCK1_LAT                LATC3
#define SCK1_PORT               PORTCbits.RC3
#define SCK1_ANS                ANSC3
#define SCK1_SetHigh()    do { LATC3 = 1; } while(0)
#define SCK1_SetLow()   do { LATC3 = 0; } while(0)
#define SCK1_Toggle()   do { LATC3 = ~LATC3; } while(0)
#define SCK1_GetValue()         PORTCbits.RC3
#define SCK1_SetDigitalInput()    do { TRISC3 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISC3 = 0; } while(0)

#define SCK1_SetAnalogMode()   do { ANSC3 = 1; } while(0)
#define SCK1_SetDigitalMode()   do { ANSC3 = 0; } while(0)
// get/set SDI1 aliases
#define SDI1_TRIS               TRISC4
#define SDI1_LAT                LATC4
#define SDI1_PORT               PORTCbits.RC4
#define SDI1_ANS                ANSC4
#define SDI1_SetHigh()    do { LATC4 = 1; } while(0)
#define SDI1_SetLow()   do { LATC4 = 0; } while(0)
#define SDI1_Toggle()   do { LATC4 = ~LATC4; } while(0)
#define SDI1_GetValue()         PORTCbits.RC4
#define SDI1_SetDigitalInput()    do { TRISC4 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISC4 = 0; } while(0)

#define SDI1_SetAnalogMode()   do { ANSC4 = 1; } while(0)
#define SDI1_SetDigitalMode()   do { ANSC4 = 0; } while(0)
// get/set SDO1 aliases
#define SDO1_TRIS               TRISC5
#define SDO1_LAT                LATC5
#define SDO1_PORT               PORTCbits.RC5
#define SDO1_ANS                ANSC5
#define SDO1_SetHigh()    do { LATC5 = 1; } while(0)
#define SDO1_SetLow()   do { LATC5 = 0; } while(0)
#define SDO1_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define SDO1_GetValue()         PORTCbits.RC5
#define SDO1_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

#define SDO1_SetAnalogMode()   do { ANSC5 = 1; } while(0)
#define SDO1_SetDigitalMode()   do { ANSC5 = 0; } while(0)
// get/set TX1 aliases
#define TX1_TRIS               TRISC6
#define TX1_LAT                LATC6
#define TX1_PORT               PORTCbits.RC6
#define TX1_ANS                ANSC6
#define TX1_SetHigh()    do { LATC6 = 1; } while(0)
#define TX1_SetLow()   do { LATC6 = 0; } while(0)
#define TX1_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define TX1_GetValue()         PORTCbits.RC6
#define TX1_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define TX1_SetDigitalOutput()   do { TRISC6 = 0; } while(0)

#define TX1_SetAnalogMode()   do { ANSC6 = 1; } while(0)
#define TX1_SetDigitalMode()   do { ANSC6 = 0; } while(0)
// get/set RX1 aliases
#define RX1_TRIS               TRISC7
#define RX1_LAT                LATC7
#define RX1_PORT               PORTCbits.RC7
#define RX1_ANS                ANSC7
#define RX1_SetHigh()    do { LATC7 = 1; } while(0)
#define RX1_SetLow()   do { LATC7 = 0; } while(0)
#define RX1_Toggle()   do { LATC7 = ~LATC7; } while(0)
#define RX1_GetValue()         PORTCbits.RC7
#define RX1_SetDigitalInput()    do { TRISC7 = 1; } while(0)
#define RX1_SetDigitalOutput()   do { TRISC7 = 0; } while(0)

#define RX1_SetAnalogMode()   do { ANSC7 = 1; } while(0)
#define RX1_SetDigitalMode()   do { ANSC7 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
 */