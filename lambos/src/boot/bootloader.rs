use cortex_m_semihosting::hprintln;

pub fn boot() -> () {
    hprintln!("Bootloader running... {:p}", lambos_reset as *const()).unwrap();
    lambos_reset();
}

fn lambos_reset() -> () {
    hprintln!("Resetting lambos...").unwrap();
}