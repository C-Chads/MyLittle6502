

all:
	cc -std=c99 -Os tests.c -o main.out
	cc -std=c99 -Os test2cmos.c -o maincmos.out

clean:
	rm -f main.out maincmos.out *.exe
