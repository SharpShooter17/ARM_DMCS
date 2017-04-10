#ifndef __BINARYMACRO_H_
#define __BINARYMACRO_H_

/* change a numeric literal into a hex constant
   (fill up with leading zeroes up to 32 bits)
   8-bit constants with maximum value 0x11111111, always fits in unsigned long
*/
#define HEX__(n) 0x##n##LU

/* Convert 8-bit binary data into compatible with C digit */
#define B8__(x) ((x&0x0000000FLU)?1:0)      \
               +((x&0x000000F0LU)?2:0)      \
               +((x&0x00000F00LU)?4:0)      \
               +((x&0x0000F000LU)?8:0)      \
               +((x&0x000F0000LU)?16:0)     \
               +((x&0x00F00000LU)?32:0)     \
               +((x&0x0F000000LU)?64:0)     \
               +((x&0xF0000000LU)?128:0)

/* for upto 8-bit binary constants */
#define B8(d) ((unsigned char)B8__(HEX__(d)))

/* for upto 16-bit binary constants, MSB first */
#define B16(dmsb,dlsb) (((unsigned short)B8(dmsb)<<8)     \
								+ B8(dlsb))

/* for upto 32-bit binary constants, MSB first */
#define B32(dmsb,db2,db3,dlsb) (((unsigned long)B8(dmsb)<<24)  \
								+ ((unsigned long)B8(db2)<<16) \
								+ ((unsigned long)B8(db3)<<8)  \
								+ B8(dlsb))

/* How to use
      B8(01111101)    							data equal to        125 or       0x7D
      B16(10111011,01110101) 					data equal to      47989 or     0xBB75
      B32(10100100,10101111,01010,01001) 		data equal to 2762934793 or 0xA4AF0A09
*/
#endif /* __BINARYMACRO_H_ */



