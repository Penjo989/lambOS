#![no_main]
#![no_std]

use panic_halt as _;
use cortex_m::asm;
use cortex_m_rt::entry;
use cortex_m_semihosting::hprintln;

mod boot;
use boot::bootloader;

#[entry]
fn main() -> ! {
    hprintln!("Reseting...").unwrap();
    bootloader::boot();
    loop {
        asm::nop();
    }
}