# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as



all: toy.elf



#additional rules for files

.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o wdInterruptHandler.o buttons.o buzzer.o buzzerMain.o ../lib/libTimer.a

	${CC} ${CFLAGS} -o $@ $^



load: toy.elf

	msp430loader.sh  $^



clean: $^

	rm -f *.o *.elf


led.o: led.c led.h

buzzer.c: buzzer.h

buttons.c: buttons.h
