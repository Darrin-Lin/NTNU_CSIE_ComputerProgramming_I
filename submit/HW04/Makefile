hw_number = 4
# example: 1
# all:
# 	-gcc -c mysort.c -o mysort.o
# 	-gcc -o hw0401 hw0401.c mysort.o -lm
# 	-gcc -o hw0402 hw0402.c -lm
# 	-gcc -o hw0403 hw0403.c -lm
# 	-gcc -c mychess.c -o mychess.o
# 	-gcc -o hw0404 hw0404.c mychess.o -lm
# 	-gcc -o hw0405 hw0405.c -lm
all: hw0401 hw0402 hw0403 hw0404 hw0405

CC=gcc
obj = mysort.o mychess.o
target = hw0401 hw0402 hw0403 hw0404 hw0405

$(target): $(obj)

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$ || true; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

include $(obj:.o=.d)

.PHONY: clean clean_executable_file clean_object_file

clean: clean_executable_file clean_object_file

clean_executable_file:
	-rm hw0${hw_number}0?

clean_object_file:
	-rm *.o
	-rm *.d