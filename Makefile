

all:
	cc -std=c99 tests.c -o main.out
	cc -std=c99 test2cmos.c -o maincmos.out

clean:
	rm -f main.out maincmos.out *.exe
