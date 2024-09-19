# lambOS
A simple operating system for the STM32F411 written in rust

## requirements for development
- jlink (linux version is highly recommnded).
- Ozone debugger (linux version is highly recommnded).

note: you may need to install jlink drivers on your st.

## Build
run make in the code directory - make sure you have the arm-none-eabi tool-chain installed

all of the build files will be saved in code/build

## Run 
open any jlink app or Ozone(if you want to debug) 
run with SWD and not JTAG.
TODO - add more instructions
