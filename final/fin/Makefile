hw_number = mid
# example: 1
all: fin0${hw_number}01 fin0${hw_number}02 fin0${hw_number}03 fin0${hw_number}04

CC=gcc
CFLAGS= -g -Wall -Wextra -fsanitize=address -lubsan -lasan
LDLIBS= -lm
obj = 
target = fin0${hw_number}01 fin0${hw_number}02 fin0${hw_number}03 fin0${hw_number}04 fin0${hw_number}05

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
	-rm fin0${hw_number}0?

clean_object_file:
	-rm *.o
	-rm *.d*