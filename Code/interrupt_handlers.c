/* Simple program to lit up all 4 leds on reset*/

#define RCC_BASE (0x40023800)
#define RCC_AHB1ENR (RCC_BASE + 0x30)
#define GPIOD_BASE (0x40020C00)
#define GPIOD_MODER (GPIOD_BASE)
#define GPIOD_BSRR (GPIOD_BASE + 0x18)

void Reset_Handler()
{
    // turn on gpiod clock enable on rcc
    int *rcc_ahb1enr = RCC_AHB1ENR;
    *rcc_ahb1enr |= 0xf;

    // configure gpiod pins moder
    unsigned long int *gpiod_moder = GPIOD_MODER;
    *gpiod_moder = 0x55555555;
    
    // turn on leds
    int *gpiod_bsrr = GPIOD_BSRR;
    *gpiod_bsrr = 0xffff;
    while (1) { }
}

void Default_Handler()
{
}