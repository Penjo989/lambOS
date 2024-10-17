use cortex_m_semihosting::hprintln;
use cortex_m_semihosting::hio;

use core::ptr;
use core::ptr::addr_of; 

const BOOT_OFFSET: u32 = 0x1000;

extern "C" {
    static mut __sdata: u8;
    static mut __sboot: u8;
    static mut __eboot: u8;
}

pub extern "C" fn boot() -> () {
    hprintln!("Bootloader running...").unwrap();
    unsafe {
        let code_start: u32 = addr_of!(__sdata) as *const u8 as u32 + BOOT_OFFSET;
        hprintln!("Code will start @ {:x}", code_start).unwrap();

        let data_start = code_start as *const u32 as *mut  u8;  
        let reset_ptr = (lambos_reset as *const u8).sub(1);
        let reset_size = get_reset_function_size();
        hprintln!("Size of function @ {:x}", reset_size).unwrap();
        
        for i in 0..reset_size {
            ptr::write(data_start.add(i.into()), reset_ptr.add(i.into()).read());
        }

        hprintln!("Jumping to RAM reset...").unwrap();

        let reset_func: fn(fn(&str)) = core::mem::transmute(code_start | 1);
        reset_func(semihosting_print);
    }
}

unsafe fn get_reset_function_size() -> u16 {
    (addr_of!(__eboot) as *const u8 as u16) - (addr_of!(__sboot) as *const u8 as u16)
}

pub fn semihosting_print(message: &str) {
    if let Ok(mut hstdout) = hio::hstdout() {
        use core::fmt::Write;
        writeln!(hstdout, "{}", message).ok();  // Ignore the Result and force it to return ()
    }
}

#[link_section = ".boot"]
#[inline(never)]
#[no_mangle]
unsafe fn lambos_reset(hp: fn(&str)) -> () {
    hp("Resetting lambos...");
}