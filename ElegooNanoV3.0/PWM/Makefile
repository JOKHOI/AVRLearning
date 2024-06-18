# Define the default target to be built when 'make' is run without arguments
default: led_pwm_control.hex upload

# Compile the C source file (led_pwm_control.c) to an object file (led_pwm_control.o)
# -Os: Optimize for size
# -DF_CPU=64000000UL: Define the CPU frequency as 64 MHz
# -mmcu=atmega328p: Specify the microcontroller model
# -c: Compile only, do not link
# -o led_pwm_control.o: Output the object file as led_pwm_control.o
led_pwm_control.o: led_pwm_control.c
	avr-gcc -Os -DF_CPU=64000000UL -mmcu=atmega328p -c -o led_pwm_control.o led_pwm_control.c

# Link the object file (led_pwm_control.o) to create the final executable (led_pwm_control)
# -mmcu=atmega328p: Specify the microcontroller model
led_pwm_control: led_pwm_control.o
	avr-gcc -mmcu=atmega328p led_pwm_control.o -o led_pwm_control

# Convert the executable (led_pwm_control) to a HEX file (led_pwm_control.hex) suitable for flashing
# -O ihex: Output format is Intel HEX
# -R .eeprom: Remove the EEPROM section from the output
led_pwm_control.hex: led_pwm_control
	avr-objcopy -O ihex -R .eeprom led_pwm_control led_pwm_control.hex

# Upload the HEX file (led_pwm_control.hex) to the microcontroller
# -F: Override signature check
# -V: Disable verification after write
# -v -v -v -v: Increase verbosity level
# -c arduino: Specify the programmer type as 'arduino'
# -p atmega328p: Specify the microcontroller model
# -P /dev/ttyUSB0: Specify the serial port
# -b 115200: Specify the baud rate
# -U flash:w:led_pwm_control.hex: Write the HEX file to the flash memory
upload: led_pwm_control.hex
	avrdude -F -V -v -v -v -v -c arduino -p atmega328p -P /dev/ttyUSB0 -b 115200 -U flash:w:led_pwm_control.hex

# Define a phony target 'clean' to avoid conflicts with files named 'clean'
.PHONY: clean

# Clean up generated files: remove led_pwm_control.o, led_pwm_control, and led_pwm_control.hex
clean:
	rm -f led_pwm_control.o led_pwm_control led_pwm_control.hex
