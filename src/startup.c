#include <stdint.h>

#define SRAM_START (0x20000000U)
#define SRAM_SIZE (128U * 1024U)
#define SRAM_END SRAM_START + SRAM_SIZE
#define STACK_POINTER_INIT_ADDRESS (SRAM_END)

#define ISR_VECTOR_SIZE_WORDS 101

/* Define the ivt */
void reset_handler(void);
void default_handler(void);

/* Weak alias so they can be overriden. */
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void) __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void) __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void) __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));
void svcall_handler(void) __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void) __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));
void wwdg_handler(void) __attribute__((weak, alias("default_handler")));
void exti16_pvd_handler(void) __attribute__((weak, alias("default_handler")));
void exti21_tamp_stamp_handler(void) __attribute__((weak, alias("default_handler")));
void exti22_rtc_wkup_handler(void) __attribute__((weak, alias("default_handler")));
void flash_handler(void) __attribute__((weak, alias("default_handler")));
void rcc_handler(void) __attribute__((weak, alias("default_handler")));
void exti0_handler(void) __attribute__((weak, alias("default_handler")));
void exti1_handler(void) __attribute__((weak, alias("default_handler")));
void exti2_handler(void) __attribute__((weak, alias("default_handler")));
void exti3_handler(void) __attribute__((weak, alias("default_handler")));
void exti4_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream0_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream1_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream2_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream3_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream4_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream5_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream6_handler(void) __attribute__((weak, alias("default_handler")));
void adc_handler(void) __attribute__((weak, alias("default_handler")));
void exti9_5_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_brk_tim9_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_up_tim10_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_trg_com_tim11_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_cc_handler(void) __attribute__((weak, alias("default_handler")));
void tim2_handler(void) __attribute__((weak, alias("default_handler")));
void tim3_handler(void) __attribute__((weak, alias("default_handler")));
void tim4_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_er_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_er_handler(void) __attribute__((weak, alias("default_handler")));
void spi1_handler(void) __attribute__((weak, alias("default_handler")));
void spi2_handler(void) __attribute__((weak, alias("default_handler")));
void usart1_handler(void) __attribute__((weak, alias("default_handler")));
void usart2_handler(void) __attribute__((weak, alias("default_handler")));
void exti15_10_handler(void) __attribute__((weak, alias("default_handler")));
void exti17_rtc_alarm_handler(void) __attribute__((weak, alias("default_handler")));
void exti18_otg_fs_wkup_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream7_handler(void) __attribute__((weak, alias("default_handler")));
void sdio_handler(void) __attribute__((weak, alias("default_handler")));
void tim5_handler(void) __attribute__((weak, alias("default_handler")));
void spi3_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream0_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream1_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream2_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream3_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream4_handler(void) __attribute__((weak, alias("default_handler")));
void otg_fs_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream5_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream6_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream7_handler(void) __attribute__((weak, alias("default_handler")));
void usart6_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_er_handler(void) __attribute__((weak, alias("default_handler")));
void fpu_handler(void) __attribute__((weak, alias("default_handler")));
void spi4_handler(void) __attribute__((weak, alias("default_handler")));
void spi5_handler(void) __attribute__((weak, alias("default_handler")));

uint32_t ivt[] __attribute__((section(".ivt"))) = {
    STACK_POINTER_INIT_ADDRESS,        // Initial stack pointer
    (uint32_t) &reset_handler,         // Reset handler
    (uint32_t) &nmi_handler,           // NMI handler
    (uint32_t) &hard_fault_handler,    // Hard fault handler
    (uint32_t) &mem_manage_handler,    // Memory management fault handler
    (uint32_t) &bus_fault_handler,     // Bus fault handler
    (uint32_t) &usage_fault_handler,   // Usage fault handler
    0, 0, 0, 0,                        // Reserved
    (uint32_t) &svcall_handler,        // SVCall handler
    (uint32_t) &debug_monitor_handler, // Debug monitor handler
    0,                                 // Reserved
    (uint32_t) &pendsv_handler,        // PendSV handler
    (uint32_t) &systick_handler,       // SysTick handler
    
    // External Interrupts
    (uint32_t) &wwdg_handler,                // Window WatchDog
    (uint32_t) &exti16_pvd_handler,          // PVD through EXTI Line detection
    (uint32_t) &exti21_tamp_stamp_handler,   // Tamper and TimeStamps through EXTI line
    (uint32_t) &exti22_rtc_wkup_handler,     // RTC Wakeup through EXTI line
    (uint32_t) &flash_handler,               // FLASH
    (uint32_t) &rcc_handler,                 // RCC
    (uint32_t) &exti0_handler,               // EXTI Line0
    (uint32_t) &exti1_handler,               // EXTI Line1
    (uint32_t) &exti2_handler,               // EXTI Line2
    (uint32_t) &exti3_handler,               // EXTI Line3
    (uint32_t) &exti4_handler,               // EXTI Line4
    (uint32_t) &dma1_stream0_handler,        // DMA1 Stream 0
    (uint32_t) &dma1_stream1_handler,        // DMA1 Stream 1
    (uint32_t) &dma1_stream2_handler,        // DMA1 Stream 2
    (uint32_t) &dma1_stream3_handler,        // DMA1 Stream 3
    (uint32_t) &dma1_stream4_handler,        // DMA1 Stream 4
    (uint32_t) &dma1_stream5_handler,        // DMA1 Stream 5
    (uint32_t) &dma1_stream6_handler,        // DMA1 Stream 6
    (uint32_t) &adc_handler,                 // ADC1, ADC2, and ADC3s
    0, 0, 0, 0,                             // Reserved
    (uint32_t) &exti9_5_handler,             // EXTI Lines [9:5]
    (uint32_t) &tim1_brk_tim9_handler,       // TIM1 Break and TIM9
    (uint32_t) &tim1_up_tim10_handler,       // TIM1 Update and TIM10
    (uint32_t) &tim1_trg_com_tim11_handler,  // TIM1 Trigger and Commutation and TIM11
    (uint32_t) &tim1_cc_handler,             // TIM1 Capture Compare
    (uint32_t) &tim2_handler,                // TIM2
    (uint32_t) &tim3_handler,                // TIM3
    (uint32_t) &tim4_handler,                // TIM4
    (uint32_t) &i2c1_ev_handler,             // I2C1 Event
    (uint32_t) &i2c1_er_handler,             // I2C1 Error
    (uint32_t) &i2c2_ev_handler,             // I2C2 Event
    (uint32_t) &i2c2_er_handler,             // I2C2 Error
    (uint32_t) &spi1_handler,                // SPI1
    (uint32_t) &spi2_handler,                // SPI2
    (uint32_t) &usart1_handler,              // USART1
    (uint32_t) &usart2_handler,              // USART2
    0,                                       // Reserved
    (uint32_t) &exti15_10_handler,           // EXTI Lines [15:10]
    (uint32_t) &exti17_rtc_alarm_handler,    // RTC Alarm (A and B) through EXTI Line
    (uint32_t) &exti18_otg_fs_wkup_handler,  // USB OTG FS Wakeup through EXTI line
    0, 0, 0, 0,                             // Reserved
    (uint32_t) &dma1_stream7_handler,        // DMA1 Stream7
    0,                                       // Reserved
    (uint32_t) &sdio_handler,                // SDIO
    (uint32_t) &tim5_handler,                // TIM5
    (uint32_t) &spi3_handler,                // SPI3
    0, 0, 0, 0,                             // Reserved
    (uint32_t) &dma2_stream0_handler,        // DMA2 Stream 0
    (uint32_t) &dma2_stream1_handler,        // DMA2 Stream 1
    (uint32_t) &dma2_stream2_handler,        // DMA2 Stream 2
    (uint32_t) &dma2_stream3_handler,        // DMA2 Stream 3
    (uint32_t) &dma2_stream4_handler,        // DMA2 Stream 4
    0, 0, 0, 0,                             // Reserved
    (uint32_t) &otg_fs_handler,              // USB OTG FS
    (uint32_t) &dma2_stream5_handler,        // DMA2 Stream 5
    (uint32_t) &dma2_stream6_handler,        // DMA2 Stream 6
    (uint32_t) &dma2_stream7_handler,        // DMA2 Stream 7
    (uint32_t) &usart6_handler,              // USART6
    (uint32_t) &i2c3_ev_handler,             // I2C3 Event
    (uint32_t) &i2c3_er_handler,             // I2C3 Error
    0, 0, 0, 0,                             // Reserved
    (uint32_t) &fpu_handler,                 // FPU
    0, 0,                                    // Reserved
    (uint32_t) &spi4_handler,                // SPI4
    (uint32_t) &spi5_handler,                // SPI5
};

void default_handler(void)
{
	while(1);
}

/* Now, actual startup code */
extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;
extern void main(void);

void reset_handler(void)
{
	// Copy .data from flash to SRAM.
	uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
	uint8_t* flash_data = (uint8_t*)&_etext;
	uint8_t* sram_data = (uint8_t*)&_sdata;

	for (uint32_t i = 0; i < data_size; ++i) sram_data[i] = flash_data[i];

	// Zero-fill .bss.
	uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	uint8_t* bss = (uint8_t*) &_sbss;

	for (uint32_t i = 0; i < bss_size; ++i) bss[i] = 0;

	main();
}
