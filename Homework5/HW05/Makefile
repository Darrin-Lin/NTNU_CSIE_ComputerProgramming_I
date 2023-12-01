hw_number = 5
# example: 1
all: hw0${hw_number}01 hw0${hw_number}02 hw0${hw_number}03 hw0${hw_number}04 hw0${hw_number}05 hw0506

CC=gcc
CFLAGS= -g -Wall -Wextra -fsanitize=address -lubsan -lasan
LDLIBS= -lm	
obj = mystatistics.o myge.o mysphere.o mytlv.o tas.o
target = hw0506 hw0${hw_number}01 hw0${hw_number}02 hw0${hw_number}03 hw0${hw_number}04 hw0${hw_number}05

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