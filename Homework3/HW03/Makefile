hw_number = 3
homwork_c = hw0301.c hw0302.c hw0303.c hw0304.c hw0305.c
# hw0304 have some quation
# function_c = mycircle.c
function_o = mycircle.o mycontrol.o hw0304-1.o hw0304-2.o diceRolls.o
# example: 1
all: mycircle mycontrol hw0304-1_2 diceRolls main

mycircle: mycircle.c
	gcc -c ./mycircle.c -o mycircle.o
	gcc -shared mycircle.o -o libmycircle.so

mycontrol: mycontrol.c
	gcc -c ./mycontrol.c -o mycontrol.o
	gcc -shared mycontrol.o -o libmycontrol.so

hw0304-1_2: hw0304-1.c hw0304-2.c
	gcc -c ./hw0304-1.c -o hw0304-1.o
	gcc -c ./hw0304-2.c -o hw0304-2.o
	gcc -shared hw0304-1.o -o libhw0304-1.so
	gcc -shared hw0304-2.o -o libhw0304-2.so

diceRolls: diceRolls.c
	gcc diceRolls.c -o diceRolls
	gcc -c ./diceRolls.c -o diceRolls.o

main: ${function_o} ${homwork_c} 
	gcc hw0301.c -o hw0301 -lm -L. -lmycircle
	gcc hw0302.c -o hw0302 -lm -L. -lmycontrol
	gcc hw0303.c -o hw0303 -lm
	gcc hw0304.c hw0304-1.o -o hw0304-1 -lm -L. -lhw0304-1
	gcc hw0304.c hw0304-2.o -o hw0304-2 -lm -L. -lhw0304-2
	gcc hw0305.c -o hw0305 -lm -L. -ldiceRolls

clean:
	rm hw0${hw_number}0?