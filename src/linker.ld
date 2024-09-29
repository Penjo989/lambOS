/* Handle memory initialization. */
ENTRY(reset_handler) 

/* Define the memory sections. */
MEMORY
{
	FLASH (rx): ORIGIN = 0x08000000, LENGTH = 512K
	SRAM (rwx): ORIGIN = 0x20000000, LENGTH = 128K
}

/* Now, we need to specify where each memory section of our .o files should be placed. */
SECTIONS
{
	.ivt :
	{
		. = ALIGN(4);
		KEEP(*(.ivt))
	} >FLASH

	.text : 
	{
		. = ALIGN(4);
		*(.text)
		*(.rodata)

		. = ALIGN(4);
		_etext = .;
	} >FLASH

	.data : 
	{
		. = ALIGN(4);
		_sdata = .;

		*(.data)

		. = ALIGN(4);
		_edata = .;
	} >SRAM AT> FLASH
	
	.bss :
	{
		. = ALIGN(4);
		_sbss = .;

		*(.bss)

		. = ALIGN(4);
		_ebss = .;
	} >SRAM 
}
