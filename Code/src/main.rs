
#![no_main]
#![no_std]

use panic_halt as _;

use core::fmt::Write;

use cortex_m::peripheral::syst::SystClkSource;
use cortex_m_rt::{entry, exception};
use cortex_m_semihosting::{
    debug,
    hio::{self, HStdout},
};

#[entry]
fn main() -> ! {
    let p = cortex_m::Peripherals::take().unwrap();
    let mut syst = p.SYST;

    // configures the system timer to trigger a SysTick exception every second
    syst.set_clock_source(SystClkSource::Core);
    // this is configured for the LM3S6965 which has a default CPU clock of 12 MHz
    syst.set_reload(12_000_000);
    syst.clear_current();
    syst.enable_counter();
    syst.enable_interrupt();

    loop {}
}


const RCC_BASE: usize = 0x40023800;
const RCC_AHB1ENR: *mut u32 = (RCC_BASE + 0x30) as *mut u32;
const GPIOD_BASE: usize = 0x40020C00;
const GPIOD_MODER: *mut u32 = GPIOD_BASE as *mut u32;
const GPIOD_BSRR: *mut u32 = (GPIOD_BASE + 0x18) as *mut u32;


#[exception]
fn SysTick() {
    unsafe {
        // Enable clock for GPIOD
        let rcc_ahb1enr = &mut *RCC_AHB1ENR;
        *rcc_ahb1enr |= 0xf;

        // Configure GPIOD pins mode
        let gpiod_moder = &mut *GPIOD_MODER;
        *gpiod_moder = 0x55555555;

        // Turn on LEDs
        let gpiod_bsrr = &mut *GPIOD_BSRR;
        *gpiod_bsrr = 0xffff;
    }

    // Infinite loop to prevent exit
    loop {}
}