

INCLUDE_DIR = /usr/local/include

all:
	cc -std=c99 -Os tests.c -o main.out
	cc -std=c99 -Os test2cmos.c -o maincmos.out

install:
	install --mode=444 fake6502.h $(INCLUDE_DIR)/
	install --mode=444 fake65c02.h $(INCLUDE_DIR)/

clean:
	rm -f main.out maincmos.out *.exe
