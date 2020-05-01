#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdlib.h>

typedef unsigned short long int uint24_t;

void read_line(char * s, int max_len);
void RAM_set_SPI_mode(volatile unsigned char* latch, uint8_t pin_number);
void RAM_sequential_SPI_write(volatile unsigned char* latch, uint8_t pin_number, uint24_t address, uint8_t *data_out, uint8_t data_out_size);
void RAM_sequential_SPI_read(volatile unsigned char* latch, uint8_t pin_number, uint24_t address, uint8_t *data_in, uint8_t data_in_size);

void main(void) {
    SYSTEM_Initialize();

    unsigned long int dtc = 0;
    char string[30], buffer[30], ch;
    uint24_t ind = 0;
    uint8_t n = 2;
    printf("\n\r");

    do {
    printf("Selezionare la velocita' del trasferimento:\n\r");
    printf("\ta\tFOSC/4 (16MHz)\n\r");
    printf("\tb\tFOSC/16 (4MHz)\n\r");
    printf("\tc\tFOSC/64 (1MHz)\n\r");
    printf("scelta: ");
    ch = getch();
    printf("%c\n\r", ch);
        switch (ch) {
            case 'a': SSP1CON1 = 0x20;
                break;
            case 'b': SSP1CON1 = 0x21;
                break;
            case 'c': SSP1CON1 = 0x22;
                break;
            default:
                printf("Digitare solo uno tra i caratteri ammessi: a,b, o c.\n\r");
                break;
        }
    } while (ch !='a' & ch !='b' & ch !='c');
    while (1) {
        for (int i = 0; i < 30; i++) {
            string[i] = '\0';
            buffer[i] = '\0';
        }
        do {
            printf("Digitare invio per non apportare cambiamenti.\n\r");
            printf("Digitare il duty cycle del PWM (0 - 1023): ");
            read_line(string, 30);
            dtc =(unsigned long int) atol(string);
            if (dtc > 1023) printf("Immettere un valore compreso nell'intervallo 0 - 1023.\n\r");
            else    if(string[0] != '\0')    PWM4_LoadDutyValue(dtc);
        } while (dtc > 1023);
        printf("Digitare invio per ritornare alla selezione del duty cycle.\n\r");
        printf("Digitare se leggere (a) o scrivere (b) dalle RAM: ");
        ch = getch();
        printf("%c\n\r", ch);
        if (ch == 'a') {
            printf("Digitare a quale indirizzo stampare il contenuto delle RAM: ");
            read_line(string, 30);
            ind = atoi(string);
            RAM_sequential_SPI_read(&LATC, 0, ind, buffer, 30);
            buffer[29] = '\0';
            printf("Le stringhe attualmente in memoria all'indirizzo %d:\n\r%s\n\r", (int) ind, buffer);
            RAM_sequential_SPI_read(&LATC, 1, ind, buffer, 30);
            buffer[29] = '\0';
            printf("%s\n\r", buffer);
            RAM_sequential_SPI_read(&LATC, 2, ind, buffer, 30);
            buffer[29] = '\0';
            printf("%s\n\r", buffer);
        } else {
            if (ch == 'b') {
                printf("Digitare su quale RAM scrivere (a,b, o c):");
                ch = getch();
                printf("%c\n\r", ch);
                switch (ch) {
                    case 'a': n = 0;
                        break;
                    case 'b': n = 1;
                        break;
                    case 'c': n = 2;
                        break;
                    default:
                        printf("Digitare solo uno tra i caratteri ammessi: a,b, o c.\n\r");
                        break;
                }
                printf("Digitare a quale indirizzo scrivere: ");
                read_line(string, 30);
                ind = atoi(string);
                printf("Digitare una stringa: ");
                read_line(string, 30);
                RAM_sequential_SPI_write(&LATC, n, ind, string, strlen(string));
                RAM_sequential_SPI_read(&LATC, n, ind, buffer, 30);
                buffer[29] = '\0';
                printf("La stringa attualmente in memoria all'indirizzo %d:\n\r%s\n\r", (int) ind, buffer);
            } else printf("Digitare solo uno tra i caratteri ammessi: a o b.\n\r");
        }
    }
}

void RAM_set_SPI_mode(volatile unsigned char* latch, uint8_t pin_number) {
    *latch &= ~(1 << pin_number); //metto CS in low per avviare i trasferimenti
    SPI1_Exchange8bit(0b11111111); //comando RSTIO
    *latch |= (1 << pin_number); //metto CS in high per bloccare i trasferimenti
}

void RAM_sequential_SPI_write(volatile unsigned char* latch, uint8_t pin_number, uint24_t address, uint8_t *data_out, uint8_t data_out_size) {
    uint8_t address_array[3];
    address_array[2] = address;
    address_array[1] = address >> 8;
    address_array[0] = address >> 16;
    *latch &= ~(1 << pin_number); //metto CS in low per avviare i trasferimenti
    SPI1_Exchange8bit(0b00000010); //comando WRITE
    SPI1_Exchange8bitBuffer(address_array, 3, NULL);
    SPI1_Exchange8bitBuffer(data_out, data_out_size, NULL);
    *latch |= (1 << pin_number); //metto CS in high per bloccare i trasferimenti
}

void RAM_sequential_SPI_read(volatile unsigned char* latch, uint8_t pin_number, uint24_t address, uint8_t *data_in, uint8_t data_in_size) {
    uint8_t address_array[3];
    address_array[2] = address;
    address_array[1] = address >> 8;
    address_array[0] = address >> 16;
    *latch &= ~(1 << pin_number); //metto CS in low per avviare i trasferimenti
    SPI1_Exchange8bit(0b00000011); //comando READ
    SPI1_Exchange8bitBuffer(address_array, 3, NULL);
    SPI1_Exchange8bitBuffer(NULL, data_in_size, data_in);
    *latch |= (1 << pin_number); //metto CS in high per bloccare i trasferimenti
}

void read_line(char * s, int max_len) {
    int i = 0;
    for (;;) {
        char c = EUSART1_Read();
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