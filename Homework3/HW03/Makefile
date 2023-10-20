hw_number = 3
homwork_c = hw0301.c hw0302.c hw0303.c #hw0304-1.c hw0304-1.c hw0305.c
# hw0304 have some quation
# function_c = mycircle.c
function_o = mycircle.o mycontrol.o
# example: 1
all: mycircle main


mycircle: mycircle.c
	gcc -c ./mycircle.c -o mycircle.o
	gcc -shared mycircle.o -o libmycircle.so

mycontrol: mycontrol.c
	gcc -c ./mycontrol.c -o mycontrol.o
	gcc -shared mycontrol.o -o libmycontrol.so

main: ${function_o} ${homwork_c} 
	gcc hw0301.c -o hw0301 -L. -lmycircle
	gcc hw0302.c -o hw0302 -L. -lmycontrol
	gcc hw0303.c -o hw0303
#	gcc hw0304-1.c -o hw0304-1
#	gcc hw0304-2.c -o hw0304-2
	gcc hw0305.c -o hw0305

clean:
	rm hw0${hw_number}0?