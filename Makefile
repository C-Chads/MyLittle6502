

all:
	cc -std=c99 tests.c -o main.out

clean:
	rm -f main.out
