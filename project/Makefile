# makfile configuration
COMMON_OBJECTS  = main.o buzzer.o fur_elise.o switches.o led.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS		= msp430-elf-as
AR		= msp430-elf-ar
RANLIB		= msp430-elf-ranlib

all: run.elf

libTimer.a: clocksTimer.o sr.o
	$(AR) cr $@ $^
	$(RANLIB) $@

#additional rules for files
run.elf: ${COMMON_OBJECTS} libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: run.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *.c~ *.h~ libTimer.a

buzzer.o: buzzer.h libTimer.h switches.h
main.o: buzzer.h libTimer.h switches.h
switches.o: led.h switches.h
led.o: switches.h led.h
