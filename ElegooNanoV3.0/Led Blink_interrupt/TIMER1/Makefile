# Define the default target to be built when 'make' is run without arguments
default: led_Interrupt.hex upload

# Compile the C source file (led_Interrupt.c) to an object file (led_Interrupt.o)
# -Os: Optimize for size
# -DF_CPU=64000000UL: Define the CPU frequency as 64 MHz
# -mmcu=atmega328p: Specify the microcontroller model
# -c: Compile only, do not link
# -o led_Interrupt.o: Output the object file as led_Interrupt.o
led_Interrupt.o: led_Interrupt.c
	avr-gcc -Os -DF_CPU=64000000UL -mmcu=atmega328p -c -o led_Interrupt.o led_Interrupt.c

# Link the object file (led_Interrupt.o) to create the final executable (led_Interrupt)
# -mmcu=atmega328p: Specify the microcontroller model
led_Interrupt: led_Interrupt.o
	avr-gcc -mmcu=atmega328p led_Interrupt.o -o led_Interrupt

# Convert the executable (led_Interrupt) to a HEX file (led_Interrupt.hex) suitable for flashing
# -O ihex: Output format is Intel HEX
# -R .eeprom: Remove the EEPROM section from the output
led_Interrupt.hex: led_Interrupt
	avr-objcopy -O ihex -R .eeprom led_Interrupt led_Interrupt.hex

# Upload the HEX file (led_Interrupt.hex) to the microcontroller
# -F: Override signature check
# -V: Disable verification after write
# -v -v -v -v: Increase verbosity level
# -c arduino: Specify the programmer type as 'arduino'
# -p atmega328p: Specify the microcontroller model
# -P /dev/ttyUSB0: Specify the serial port
# -b 115200: Specify the baud rate
# -U flash:w:led_Interrupt.hex: Write the HEX file to the flash memory
upload: led_Interrupt.hex
	avrdude -F -V -v -v -v -v -c arduino -p atmega328p -P /dev/ttyUSB0 -b 115200 -U flash:w:led_Interrupt.hex

# Define a phony target 'clean' to avoid conflicts with files named 'clean'
.PHONY: clean

# Clean up generated files: remove led_Interrupt.o, led_Interrupt, and led_Interrupt.hex
clean:
	rm -f led_Interrupt.o led_Interrupt led_Interrupt.hex
