hw_number = 01
all:
	for i in 1 2 3 4 5;\
	do\
		gcc hw$(hw_number)0$$i.c -lm -o hw$(hw_number)0$$i || true;\
	done
clean:
	rm hw$(hw_number)0?