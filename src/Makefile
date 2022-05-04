# makfile configuration
COMMON_OBJECTS		= draw_shapes.o wdtInterruptHandler.o switches.o buzzer.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: shape_demo.elf

#additional rules for
main_c.elf: ${COMMON_OBJECTS} main.o buzzer_sounds_c.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

main_s.elf: ${COMMON_OBJECTS} main.o buzzer_sounds_s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load_c: main_c.elf
	msp430loader.sh $^

load_s: main_s.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
