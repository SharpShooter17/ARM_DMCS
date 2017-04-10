#ifndef Registers__
#define Registers__

#define REGFILESIZE 128
unsigned int Registers[REGFILESIZE];

void InitRegisters8b(void);
void InitRegistersBE(void);
void InitRegistersLE(void);
void PrintRegisters(void);
void PrintPORTBreg(void);
void PrintReg(unsigned int* Address, unsigned char Offset);
unsigned char ReadReg(unsigned int* Address, unsigned char Offset);
void WriteReg(unsigned int* Address, unsigned char Offset, unsigned char data);
void PrintRegBinBE (unsigned int RegSize, unsigned int* Data, unsigned char Offset);
void PrintRegBinLE (unsigned int RegSize, unsigned int* Data, unsigned char Offset);
#endif
