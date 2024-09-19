
/* Entry Point */
ENTRY(Reset_Handler)


/* Memories definition */
MEMORY
{
  RAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 128K
  FLASH    (rx)    : ORIGIN = 0x8000000,   LENGTH = 512K
}

/* Sections */
SECTIONS
{
  /* The startup code into "FLASH" Rom type memory */
  .ivt :
  {
    . = ALIGN(4);
    *(.isr_vector) /* Startup code */
  } >FLASH

  /* The program code and other data into "FLASH" Rom type memory */
  .text :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
  } >FLASH


  .ARM.attributes 0 : { *(.ARM.attributes) }
}
  