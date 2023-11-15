hw_number = 4
# example: 1
all:
	-gcc -c ./object_files/mysort.c -o ./object_files/mysort.o
	-gcc -o hw0301 hw0301.c ./object_files/mysort.o -lm
	-gcc -o hw0302 hw0302.c -lm
	-gcc -o hw0303 hw0303.c -lm
	-gcc -o hw0304 hw0304.c -lm
	-gcc -o hw0305 hw0305.c -lm
	


clean: clean_executable_file clean_object_file

clean_executable_file:
	-rm hw0${hw_number}0?

clean_object_file:
	-rm ./object_files/*.o