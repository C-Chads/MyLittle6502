

all:
	cc -std=c99 -O3 tests.c -o main.out
	cc -std=c99 -O3 test2cmos.c -o maincmos.out

clean:
	rm -f main.out maincmos.out *.exe
