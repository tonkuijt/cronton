all: cronton.c
	gcc -o cronton cronton.c

clean:
	rm -rf cronton
