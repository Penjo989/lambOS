lambos:
	cargo build
	arm-none-eabi-objcopy -O binary -j .vector_table ./target/thumbv7em-none-eabi/debug/test ./build/vector_table.bin
	arm-none-eabi-objcopy -O binary -j .text ./target/thumbv7em-none-eabi/debug/test ./build/text.bin
	cat ./build/vector_table.bin ./build/text.bin > ./build/lambos.bin