// FOSCSEL
#pragma config FNOSC = FRC              // Oscillator Mode (Internal Fast RC (FRC))

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Source (Primary Oscillator Disabled)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSECMD           // Clock Switching and Monitor (Clock switching is enabled, Fail-Safe Clock Monitor is disabled)

// FWDT
#pragma config FWDTEN = OFF             // Watchdog Timer Enabled/disabled by user software
// (LPRC can be disabled by clearing SWDTEN bit in RCON register

#include <xc.h>
#include <libpic30.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libpic30.h>

#define FOSC    (80000000)
#define FP (FOSC/2)
#define BAUDRATE 19600
#define BRGVAL ((FP/BAUDRATE)/16)-1
#define DUMMY_DATA 0x0
#define    FCY    40000000UL

typedef unsigned char uint8_t;
typedef unsigned long int uint24_t;

void read_line(char * s, int max_len);
void putch(char c);
char read_char(void);
void oscillator_setup(void);
void uart_setup(void);

int main(void) {
    oscillator_setup();
    uart_setup();
    printf("RESET\n\r");
    uint8_t i = 0;
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISBbits.TRISB0 = 0;
    while (1) {
        LATAbits.LATA0 = 1; //rst
        LATAbits.LATA1 = 0; //clk
        LATBbits.LATB0 = 0; //start
        printf("Digitare man mano un tasto per far progredire la simulazione.\n\r");
        read_char();
        printf("rst\tclk\tstart\t\n\r");
        for (i = 0; i < 30; i++) {
            switch (i) {
                case 2:
                    LATAbits.LATA0 = 0; //rst
                    break;
                case 4:
                    LATBbits.LATB0 = 1; //start
                    break;
                case 6:
                    LATBbits.LATB0 = 0; //start
                    break;
                default:
                    break;
            }
            printf("%u\t%u\t%u\t\n\r",LATAbits.LATA0, LATAbits.LATA1, LATBbits.LATB0);
            read_char();
            LATAbits.LATA1 = !LATAbits.LATA1; //clk
        }
        printf("Fine simulazione.\n\r");
    }
}

void oscillator_setup() {
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD = 41; // M = 43
    CLKDIVbits.PLLPOST = 0; // N2 = 2
    CLKDIVbits.PLLPRE = 0; // N1 = 2
    OSCTUN = 0; // Tune FRC oscillator, if FRC is used
    // Disable Watch Dog Timer
    RCONbits.SWDTEN = 0;
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    // Wait for PLL to lock
    while (OSCCONbits.LOCK != 1) {
    };
}

void uart_setup() {
    AD1PCFGL = 0xFFFF; //all pins as digital
    TRISBbits.TRISB3 = 0; // TX as output
    TRISBbits.TRISB2 = 1; // RX as input

    RPINR18bits.U1RXR = 2; //U1RX on RP2 pin
    RPOR1bits.RP3R = 0b00011; //U1TX on RP3 pin

    U1MODEbits.STSEL = 0; // 1-stop bit
    U1MODEbits.PDSEL = 0; // No Parity, 8-data bits
    U1MODEbits.ABAUD = 0; // Auto-Baud disabled
    U1MODEbits.BRGH = 0; // Standard-Speed mode
    U1BRG = BRGVAL; // Baud Rate setting for 9600
    U1MODEbits.UARTEN = 1; // Enable 
    U1STAbits.UTXEN = 1; // Enable UART TX
    __C30_UART = 1;
}

void putch(char c) {
    // wait the end of transmission
    while (U1STAbits.TRMT == 0) {
    };
    IFS0bits.U1TXIF = 0; // Clear TX Interrupt flag
    U1TXREG = c; // send the new byte
}

char read_char(void) {
    while (U1STAbits.URXDA == 0) { //UART1 Receiver Interrupt Flag Status bit
        if (U1STAbits.OERR == 1) {
            U1STAbits.OERR = 0;
        }
    }
    return U1RXREG;
}

void read_line(char * s, int max_len) {
    int i = 0;
    for (;;) {
        char c = read_char();
        if (c == 13) {
            putchar(c);
            putchar(10);
            s[i] = 0;
            return;
        } else if (c == 127 || c == 8) {
            if (i > 0) {
                putchar(c);
                putchar(' ');
                putchar(c);
                --i;
            }
        } else if (c >= 32) {
            if (i < max_len) {
                putchar(c);
                s[i] = c;
                ++i;
            }
        }
    }
}