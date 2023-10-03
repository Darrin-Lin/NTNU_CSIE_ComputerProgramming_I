#!/bin/sh
echo "hw?(ex:hw01 ==> 01)"
read number
mkdir "HW${number}"
for i in $(seq 1 5)
do
	cp "./hw_making_tools/hw_c_example.c" "./HW${number}/hw${number}0${i}.c"
done
cp "./hw_making_tools/hw_makefile_example" "HW${number}/Makefile"
cp "./hw_making_tools/hw_README_example.md" "./HW${number}/README.md"
