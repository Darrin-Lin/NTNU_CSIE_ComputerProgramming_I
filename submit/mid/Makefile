all:
	-gcc -o mid01 mid01.c -lm
	-gcc -o mid02 mid02.c -lm
	-gcc -o mid03 mid03.c -lm
	-gcc -c parity.c
	-gcc -o mid04 mid04.c parity.o -lm
	-gcc -o mid05 mid05.c -lm

clean:
	-rm mid0?
	-rm *.o