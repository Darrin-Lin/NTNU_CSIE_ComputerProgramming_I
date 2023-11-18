hw_number = 4
# example: 1
all:
	-gcc -c ./object_files/mysort.c -o ./object_files/mysort.o
	-gcc -o hw0401 hw0401.c ./object_files/mysort.o -lm
	-gcc -o hw0402 hw0402.c -lm
	-gcc -o hw0403 hw0403.c -lm
	-gcc -c ./object_files/mychess.c -o ./object_files/mychess.o
	-gcc -o hw0404 hw0404.c ./object_files/mychess.o -lm
	-gcc -o hw0405 hw0405.c -lm

clean: clean_executable_file clean_object_file

clean_executable_file:
	-rm hw0${hw_number}0?

clean_object_file:
	-rm ./object_files/*.o