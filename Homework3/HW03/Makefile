hw_number = 3
homwork_c = hw0301.c hw0302.c hw0303.c hw0304.c hw0305.c
function_o = ./object_files/mycircle.o ./object_files/mycontrol.o ./object_files/hw0304-1.o ./object_files/hw0304-2.o ./object_files/diceRolls.o

all: mycircle mycontrol hw0304-1_2 diceRolls main

mycircle: ./object_files/mycircle.c
	gcc -c ./object_files/mycircle.c -o ./object_files/mycircle.o -lm
	gcc -shared ./object_files/mycircle.o -o ./object_files/libmycircle.so

mycontrol: ./object_files/mycontrol.c
	gcc -c ./object_files/mycontrol.c -o ./object_files/mycontrol.o -lm
	gcc -shared ./object_files/mycontrol.o -o ./object_files/libmycontrol.so

hw0304-1_2: ./object_files/hw0304-1.c ./object_files/hw0304-2.c
	gcc -c ./object_files/hw0304-1.c -o ./object_files/hw0304-1.o -lm
	gcc -c ./object_files/hw0304-2.c -o ./object_files/hw0304-2.o -lm
	gcc -shared ./object_files/hw0304-1.o -o ./object_files/libhw0304-1.so
	gcc -shared ./object_files/hw0304-2.o -o ./object_files/libhw0304-2.so

diceRolls: ./object_files/diceRolls.c
	gcc -c ./object_files/diceRolls.c -o ./object_files/diceRolls.o
	gcc -shared ./object_files/diceRolls.o -o ./object_files/libdiceRolls.so

main: ${function_o} ${homwork_c}
	gcc hw0301.c -o hw0301 -lm -L./object_files -lmycircle
	gcc hw0302.c -o hw0302 -lm -L./object_files -lmycontrol
	gcc hw0303.c -o hw0303 -lm
	gcc hw0304.c ./object_files/hw0304-1.o -o hw0304-1 -lm -L./object_files -lhw0304-1
	gcc hw0304.c ./object_files/hw0304-2.o -o hw0304-2 -lm -L./object_files -lhw0304-2
	gcc hw0305.c -o hw0305 -lm -L./object_files -ldiceRolls

clean:
	rm hw0${hw_number}0?
	rm hw0${hw_number}04-?

clean_object_file:
	rm ./object_files/*.o
	rm ./object_files/*.so