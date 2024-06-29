# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS		= msp430-elf-as
AR		= msp430-elf-ar

all: run.elf

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ libTimer.a

#additional rules for files
run.elf: ${COMMON_OBJECTS} main.o buzzer.o libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: run.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

buzzer.o: buzzer.h libTimer.h
main.o: buzzer.h libTimer.h
