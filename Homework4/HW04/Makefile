hw_number = 4
# example: 1
# all:
# 	-gcc -c mysort.c -o mysort.o
# 	-gcc -o hw0${hw_number}01 hw0${hw_number}01.c mysort.o -lm
# 	-gcc -o hw0${hw_number}02 hw0${hw_number}02.c -lm
# 	-gcc -o hw0${hw_number}03 hw0${hw_number}03.c -lm
# 	-gcc -c mychess.c -o mychess.o
# 	-gcc -o hw0${hw_number}04 hw0${hw_number}04.c mychess.o -lm
# 	-gcc -o hw0${hw_number}05 hw0${hw_number}05.c -lm
all: hw0${hw_number}01 hw0${hw_number}02 hw0${hw_number}03 hw0${hw_number}04 hw0${hw_number}05

CC=gcc
CFLAGS= -g -Wall -Wextra -fsanitize=address -lubsan -lasan
LDLIBS= -lm
obj = mysort.o mychess.o
target = hw0${hw_number}01 hw0${hw_number}02 hw0${hw_number}03 hw0${hw_number}04 hw0${hw_number}05

$(target): $(obj)

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$ $(LDLIBS); \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

include $(obj:.o=.d)

.PHONY: clean clean_executable_file clean_object_file

clean: clean_executable_file clean_object_file

clean_executable_file:
	-rm hw0${hw_number}0?

clean_object_file:
	-rm *.o
	-rm *.d*