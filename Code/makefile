lambos.bin: lambos.elf
	arm-none-eabi-objcopy -O binary -j .ivt ./build/lambos.elf ./build/ivt.bin
	arm-none-eabi-objcopy -O binary -j .text ./build/lambos.elf ./build/text.bin
	cat ./build/ivt.bin ./build/text.bin > ./build/lambos.bin

lambos.elf: ivt.o interrupt_handlers.o lambos_linker.ld
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -nostdlib -T lambos_linker.ld -o ./build/lambos.elf ./build/interrupt_handlers.o ./build/ivt.o

ivt.o: ivt.s 
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -nostdlib  -c -o ./build/ivt.o ivt.s   

interrupt_handlers.o: interrupt_handlers.c
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -nostdlib -c -o ./build/interrupt_handlers.o interrupt_handlers.c
