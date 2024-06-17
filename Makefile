# Define the default target to be built when 'make' is run without arguments
default: led_delay.hex upload

# Compile the C source file (led_delay.c) to an object file (led_delay.o)
# -Os: Optimize for size
# -DF_CPU=64000000UL: Define the CPU frequency as 64 MHz
# -mmcu=atmega328p: Specify the microcontroller model
# -c: Compile only, do not link
# -o led_delay.o: Output the object file as led_delay.o
led_delay.o: led_delay.c
	avr-gcc -Os -DF_CPU=64000000UL -mmcu=atmega328p -c -o led_delay.o led_delay.c

# Link the object file (led_delay.o) to create the final executable (led_delay)
# -mmcu=atmega328p: Specify the microcontroller model
led_delay: led_delay.o
	avr-gcc -mmcu=atmega328p led_delay.o -o led_delay

# Convert the executable (led_delay) to a HEX file (led_delay.hex) suitable for flashing
# -O ihex: Output format is Intel HEX
# -R .eeprom: Remove the EEPROM section from the output
led_delay.hex: led_delay
	avr-objcopy -O ihex -R .eeprom led_delay led_delay.hex

# Upload the HEX file (led_delay.hex) to the microcontroller
# -F: Override signature check
# -V: Disable verification after write
# -v -v -v -v: Increase verbosity level
# -c arduino: Specify the programmer type as 'arduino'
# -p atmega328p: Specify the microcontroller model
# -P /dev/ttyUSB0: Specify the serial port
# -b 115200: Specify the baud rate
# -U flash:w:led_delay.hex: Write the HEX file to the flash memory
upload: led_delay.hex
	avrdude -F -V -v -v -v -v -c arduino -p atmega328p -P /dev/ttyUSB0 -b 115200 -U flash:w:led_delay.hex

# Define a phony target 'clean' to avoid conflicts with files named 'clean'
.PHONY: clean

# Clean up generated files: remove led_delay.o, led_delay, and led_delay.hex
clean:
	rm -f led_delay.o led_delay led_delay.hex
