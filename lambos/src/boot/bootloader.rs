use cortex_m_semihosting::hprintln;

extern "C" {
    static __sdata: u32;
}

pub extern "C" fn boot() -> () {
    hprintln!("Bootloader running... {:p}", lambos_reset as *const()).unwrap();
    unsafe {
        let data_start = __sdata as *mut u8;
        let reset_ptr = lambos_reset as *const u8;
        let reset_size: u16 = 0x4a;
        
        hprintln!("Starting to copy reset to RAM... {:p} {:p}", reset_ptr, data_start).unwrap();

        for i in 0..reset_size {
            *data_start.add(i.into()) = *reset_ptr.add(i.into())
        }

        hprintln!("Done copying...").unwrap();
    }
    lambos_reset();
}

#[link_section = ".data"]
#[inline(never)]
fn lambos_reset() -> () {
    hprintln!("Resetting lambos...").unwrap();
}