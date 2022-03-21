# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as



all: toy.elf



#additional rules for files

toy.elf: ${COMMON_OBJECTS} led.o stateMachines.o p2_interrupt_handler.o wdInterruptHandler.o buttons.o buzzer.o buttonMain.o ../lib/libTimer.a

	${CC} ${CFLAGS} -o $@ $^



load: toy.elf

	msp430loader.sh  $^

clean: $^

	rm -f *.o *.elf


led.o: led.c led.h

buzzer.c: buzzer.h

buttons.c: buttons.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h
