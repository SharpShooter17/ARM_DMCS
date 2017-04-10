#define PIOB_PER (volatile unsigned int *)0xFFFFF400
#define PIOB_OER (volatile unsigned int *)0xFFFFF410
#define PIOB_SODR (volatile unsigned int *)0xFFFFF430
#define PIOB_CODR (volatile unsigned int *)0xFFFFF434

#define PIOC_PER (volatile unsigned int *)0xFFFFF600
#define PIOC_OER (volatile unsigned int *)0xFFFFF610
#define PIOC_SODR (volatile unsigned int *)0xFFFFF630
#define PIOC_CODR (volatile unsigned int *)0xFFFFF634

void dbgu_print_ascii(const char * string) {};

void sleep(volatile int milisecond)
{
	volatile int i = 0;
	for (i = 0; i < milisecond*1000000; i++);
	return;	
}

int main(void) 
{
	*PIOB_PER = (1 << 8);
	*PIOB_OER = (1 << 8);

	for (;;)
	{
		*PIOB_CODR = (1 << 8);
		sleep(5);
		*PIOB_SODR = (1 << 8);
		sleep(5);
	}

	return 0;
}

