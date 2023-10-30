hw_number=3
homwork_c=hw0301.c hw0302.c hw0303.c hw0304.c hw0305.c
sourceFiles=./object_files/mycircle.c ./object_files/mycontrol.c ./object_files/hw0304-1.c ./object_files/hw0304-2.c ./object_files/diceRolls.c
objectFiles=./object_files/mycircle.o ./object_files/mycontrol.o ./object_files/hw0304-1.o ./object_files/hw0304-2.o ./object_files/diceRolls.o
#sharedlib=./object_files/libmycircle.so ./object_files/libmycontrol.so ./object_files/libhw0304-1.so ./object_files/libhw0304-2.so ./object_files/libdiceRolls.so
headerFiles=mycircle.h mycontrol.h hw0304.h diceRolls.h
target=hw0301 hw0302 hw0303 hw0304-1 hw0304-2 hw0305

# gtk3=-I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/harfbuzz -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0
#CC=gcc

all: #obj main
	-gcc -o ./object_files/diceRolls.o -c ./object_files/diceRolls.c
	-gcc -c ./object_files/mycircle.c -o ./object_files/mycircle.o
	-gcc -c ./object_files/mycontrol.c -o ./object_files/mycontrol.o
	-gcc -c ./object_files/hw0304-1.c -o ./object_files/hw0304-1.o
	-gcc -c ./object_files/hw0304-2.c -o ./object_files/hw0304-2.o
	-gcc -o hw0301 hw0301.c ./object_files/mycircle.o -lm
	-gcc -o hw0302 hw0302.c ./object_files/mycontrol.o -lm
	-gcc -o hw0303 hw0303.c -lm
	-gcc -o hw0304-1 hw0304.c ./object_files/hw0304-1.o -lm
	-gcc -o hw0304-2 hw0304.c ./object_files/hw0304-2.o -lm
	-gcc `pkg-config --cflags gtk+-3.0` -o hw0305 hw0305.c ./object_files/diceRolls.o -lm `pkg-config --libs gtk+-3.0`
	-gcc `pkg-config --cflags gtk+-3.0` -o hw0305-gui hw0305-guiVer.c ./object_files/diceRolls.o -lm `pkg-config --libs gtk+-3.0`


# obj: ${objectFiles} ${sourceFiles}
# 	-gcc -c ./object_files/mycircle.c -o ./object_files/mycircle.o
# #	gcc -shared ./object_files/mycircle.o -o ./object_files/libmycircle.so
# 	-gcc -c ./object_files/mycontrol.c -o ./object_files/mycontrol.o
# #	gcc -shared ./object_files/mycontrol.o -o ./object_files/libmycontrol.so
# 	-gcc -c ./object_files/hw0304-1.c -o ./object_files/hw0304-1.o
# 	-gcc -c ./object_files/hw0304-2.c -o ./object_files/hw0304-2.o
# #	gcc -shared ./object_files/hw0304-1.o -o ./object_files/libhw0304-1.so
# #	gcc -shared ./object_files/hw0304-2.o -o ./object_files/libhw0304-2.so
# 	gcc -c ./object_files/diceRolls.c -o ./object_files/diceRolls.o
# ##	gcc -shared ./object_files/diceRolls.o -o ./object_files/libdiceRolls.so

# main:${objectFiles} ${homwork_c} ${headerFiles} #${sharedlib}
# 	-gcc -o hw0301 hw0301.c ./object_files/mycircle.o -lm
# 	-gcc -o hw0302 hw0302.c ./object_files/mycontrol.o -lm
# 	-gcc -o hw0303 hw0303.c -lm
# 	-gcc -o hw0304-1 hw0304.c ./object_files/hw0304-1.o -lm
# 	-gcc -o hw0304-2 hw0304.c ./object_files/hw0304-2.o -lm
# 	-gcc `pkg-config --cflags gtk+-3.0` -o hw0305 hw0305.c ./object_files/diceRolls.o -lm `pkg-config --libs gtk+-3.0`

# .PHONY: clean clean_object_file
clean: clean_executable_file clean_object_file 

clean_executable_file:
	-rm hw0${hw_number}0?
	-rm hw0${hw_number}04-?

clean_object_file:
	-rm ./object_files/*.o
#	rm ./object_files/*.so

# gcc -c ./object_files/mycircle.c -o ./object_files/mycircle.o
# gcc -c ./object_files/mycontrol.c -o ./object_files/mycontrol.o
# gcc -c ./object_files/hw0304-1.c -o ./object_files/hw0304-1.o
# gcc -c ./object_files/hw0304-2.c -o ./object_files/hw0304-2.o
# # -gcc ./object_files/diceRolls.o -c ./object_files/diceRolls.c -lgtk-3.0
# gcc `pkg-config --cflags gtk+-3.0` -o ./object_files/diceRolls.o ./object_files/diceRolls.c `pkg-config --libs gtk+-3.0`
# gcc -o hw0301 hw0301.c ./object_files/mycircle.o -lm
# gcc -o hw0302 hw0302.c ./object_files/mycontrol.o -lm
# gcc -o hw0303 hw0303.c -lm
# gcc -o hw0304-1 hw0304.c ./object_files/hw0304-1.o -lm
# gcc -o hw0304-2 hw0304.c ./object_files/hw0304-2.o -lm
# gcc -o hw0305 hw0305.c ./object_files/diceRolls.o -lm