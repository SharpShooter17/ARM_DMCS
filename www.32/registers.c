/*
 *  ============================================================================
 *  Name        : Registers.c
 *  Author      : Dariusz Makowski
 *  Version     : v.1.3/2009.0327
 *  Copyright   : Embedded Computers
 *  Description : Exemplary program for exercises with registers mapped into computer memory
 *  ============================================================================
 */

/*
 * To compile write:
 * 	 gcc -static registers.c -L. -lreg -o registers
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "libreg.h"
#include "binarymacro.h"
#include "registers.h"

/* Define registers addresses */
#define PORTA 0x00
#define PORTB 0x10
#define PORTC 0x20
#define PORTD 0x30
#define PORTE 0x40

#define DDRA 0x01
#define DDRB 0x11
#define DDRC 0x21
#define DDRD 0x31
#define DDRE 0x41

#define PORTNA 0x02
#define PORTNB 0x12
#define PORTNC 0x22
#define PORTND 0x32
#define PORTNE 0x42

enum {PB1=1<<0, PB2=1<<1, PB3=1<<2, PB4=1<<3, PB5=1<<5, PB6=1<<6, PB7=1<<7, PB8=1<<8 };

enum {PB0_LE=1<<0, PB1_LE=1<<31, PB2_LE=1<<30, PB3_LE=1<<29, PB4_LE=1<<28, PB5_LE=1<<27, PB6_LE=1<<26, PB7_LE=1<<25, PB8_LE=1<<24 };


/* register file and pointer declared in libreg.h */
extern unsigned int* BASEREGISTER;


int main(void) {
	unsigned char DataFromReg;

/* Print registers file */
	PrintRegisters();

/* Initialize register file with numbers starting from 0 to REGFILESIZE-1 */
#if 1 /* 8-bit */
	InitRegisters8b();
#endif
#if 0 /* 32-bit big endian */
	InitRegistersBE();
#endif
#if 0 /* 32-bit little endian */
	InitRegistersLE();
#endif

/* Write registers */
	/* decimal */
	WriteReg (BASEREGISTER, PORTNE,  49);

	/* octal */
	WriteReg (BASEREGISTER, PORTNE, 061);

	/* hexadecimal */
	WriteReg (BASEREGISTER, PORTNE, 0x31);

	/* binary */
	WriteReg (BASEREGISTER, PORTNE, B8(00110001));

	PrintRegisters();

/* Print single register */
	printf ("Reading register PORTNE:");
	PrintReg(BASEREGISTER, PORTNE);

/* Read data from register */
	DataFromReg = ReadReg(BASEREGISTER, PORTNE);
	printf ("Read data from register PORTNE: 0x%0x\n\n", DataFromReg);
	return 0;
}
