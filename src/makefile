CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib
LINKER_FILE=linker.ld
LDFLAGS=-T $(LINKER_FILE)
PROGRAMMER=openocd
PROGRAMMER_FLAGS=-f interface/stlink.cfg -f target/stm32f4x.cfg

all: blink.elf

blink.elf: main.o startup.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) $^ -c

startup.o: startup.c
	$(CC) $(CFLAGS) $^ -c

flash: blink.elf
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program blink.elf verify reset exit"
	make clean

.PHONEY: clean
clean:
	rm -f *.o *.elf
