hw_number=3
homwork_c=hw0301.c hw0302.c hw0303.c hw0304.c hw0305.c
sourceFiles=./object_files/mycircle.c ./object_files/mycontrol.c ./object_files/hw0304-1.c ./object_files/hw0304-2.c ./object_files/diceRolls.c
objectFiles=./object_files/mycircle.o ./object_files/mycontrol.o ./object_files/hw0304-1.o ./object_files/hw0304-2.o ./object_files/diceRolls.o
#sharedlib=./object_files/libmycircle.so ./object_files/libmycontrol.so ./object_files/libhw0304-1.so ./object_files/libhw0304-2.so ./object_files/libdiceRolls.so
headerFiles=mycircle.h mycontrol.h hw0304.h diceRolls.h
target=hw0301 hw0302 hw0303 hw0304-1 hw0304-2 hw0305
# CC=gcc

all: obj main

obj: ${objectFiles} ${sourceFiles}
	-gcc -c ./object_files/mycircle.c -o ./object_files/mycircle.o
#	gcc -shared ./object_files/mycircle.o -o ./object_files/libmycircle.so
	-gcc -c ./object_files/mycontrol.c -o ./object_files/mycontrol.o
#	gcc -shared ./object_files/mycontrol.o -o ./object_files/libmycontrol.so
	-gcc -c ./object_files/hw0304-1.c -o ./object_files/hw0304-1.o
	-gcc -c ./object_files/hw0304-2.c -o ./object_files/hw0304-2.o
#	gcc -shared ./object_files/hw0304-1.o -o ./object_files/libhw0304-1.so
#	gcc -shared ./object_files/hw0304-2.o -o ./object_files/libhw0304-2.so
	-gcc -c ./object_files/diceRolls.c -o ./object_files/diceRolls.o
##	gcc -shared ./object_files/diceRolls.o -o ./object_files/libdiceRolls.so

main:${objectFiles} ${homwork_c} ${headerFiles} #${sharedlib}
	-gcc -o hw0301 hw0301.c ./object_files/mycircle.o -lm
	-gcc -o hw0302 hw0302.c ./object_files/mycontrol.o -lm
	-gcc -o hw0303 hw0303.c -lm
	-gcc -o hw0304-1 hw0304.c ./object_files/hw0304-1.o -lm
	-gcc -o hw0304-2 hw0304.c ./object_files/hw0304-2.o -lm
	-gcc -o hw0305 hw0305.c ./object_files/diceRolls.o -lm
# .PHONY: clean clean_object_file
clean: clean_executable_file clean_object_file 

clean_executable_file:
	rm hw0${hw_number}0?
	rm hw0${hw_number}04-?

clean_object_file:
	rm ./object_files/*.o
#	rm ./object_files/*.so