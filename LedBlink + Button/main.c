#define PIOB_PER (volatile unsigned int * const) 0xFFFFF400
#define PIOB_OER (volatile unsigned int * const) 0xFFFFF410
#define PIOB_SODR (volatile unsigned int * const) 0xFFFFF430
#define PIOB_CODR (volatile unsigned int * const) 0xFFFFF434

#define PIOC_PER (volatile unsigned int * const) 0xFFFFF600
#define PIOC_OER (volatile unsigned int * const) 0xFFFFF610
#define PIOC_ODR (volatile unsigned int * const) 0xFFFFF614
#define PIOC_SODR (volatile unsigned int * const) 0xFFFFF630
#define PIOC_CODR (volatile unsigned int * const) 0xFFFFF634
#define PIOC_PUER (volatile unsigned int * const) 0xFFFFF664
#define PIOC_PDSR (volatile unsigned int * const) 0xFFFFF63C

#define PMC_PCER (volatile unsigned int * const) 0xFFFFFC10

#define PIOC_BUTTON1 ( 1 << 5 )
#define PIOC_BUTTON2 ( 1 << 4 )

enum { False = 0, True = 1 };
typedef unsigned char boolean;

void dbgu_print_ascii(const char * string) {}

void sleep(volatile int milisecond)
{
  volatile int i = 0;
  for (i = 0; i < milisecond*1000000; i++);
  return;	
}

void initLed1()
{
  unsigned int LED = (1<<8);
  *PIOB_PER = LED;
  *PIOB_OER = LED;
  *PIOB_SODR = LED;
}

void initLed2()
{
  unsigned int LED = ( 1 << 29 );
  *PIOC_PER |= LED;
  *PIOC_OER |= LED;
  *PIOC_SODR |= LED;
}

void onLed1()
{
  *PIOB_CODR |= (1 << 8);
}

void offLed1()
{
  *PIOB_SODR |= (1 << 8);
}

void onLed2()
{
  *PIOC_CODR |= (1 << 29);
}

void offLed2()
{
  *PIOC_SODR |= (1 << 29);
}

void initButton1()
{
  *PIOC_PER |= PIOC_BUTTON1;
  *PIOC_ODR |= PIOC_BUTTON1;
  *PIOC_PUER |= PIOC_BUTTON1;
  *PMC_PCER |= ( 1 << 4 );
}

boolean getStateButton1()
{
  return ((*PIOC_PDSR & PIOC_BUTTON1) == 0);
}

int main(void) 
{
  initLed1();
  initLed2();
  initButton1();
  
  for (;;)
  {
    if ( getStateButton1() == True )
    {
      onLed2();
    }else 
    {
      offLed2();
    }
      
    onLed1();
    sleep(1);
    offLed1();
    sleep(1);
  }

  return 0;
}

