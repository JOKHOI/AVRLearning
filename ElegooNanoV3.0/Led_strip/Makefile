# Define the default target to be built when 'make' is run without arguments
default: led.hex upload

# Compile the C source file (led.c) to an object file (led.o)
# -Os: Optimize for size
# -DF_CPU=64000000UL: Define the CPU frequency as 64 MHz
# -mmcu=atmega328p: Specify the microcontroller model
# -c: Compile only, do not link
# -o led.o: Output the object file as led.o
led.o: led.c
	avr-gcc -Os -DF_CPU=64000000UL -mmcu=atmega328p -c -o led.o led.c

# Link the object file (led.o) to create the final executable (led)
# -mmcu=atmega328p: Specify the microcontroller model
led: led.o
	avr-gcc -mmcu=atmega328p led.o -o led

# Convert the executable (led) to a HEX file (led.hex) suitable for flashing
# -O ihex: Output format is Intel HEX
# -R .eeprom: Remove the EEPROM section from the output
led.hex: led
	avr-objcopy -O ihex -R .eeprom led led.hex

# Upload the HEX file (led.hex) to the microcontroller
# -F: Override signature check
# -V: Disable verification after write
# -v -v -v -v: Increase verbosity level
# -c arduino: Specify the programmer type as 'arduino'
# -p atmega328p: Specify the microcontroller model
# -P /dev/ttyUSB0: Specify the serial port
# -b 115200: Specify the baud rate
# -U flash:w:led.hex: Write the HEX file to the flash memory
upload: led.hex
	avrdude -F -V -v -v -v -v -c arduino -p atmega328p -P /dev/ttyUSB0 -b 115200 -U flash:w:led.hex

# Define a phony target 'clean' to avoid conflicts with files named 'clean'
.PHONY: clean

# Clean up generated files: remove led.o, led, and led.hex
clean:
	rm -f led.o led led.hex
