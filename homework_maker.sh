#!/bin/sh
echo "hw?(ex:hw01 ==> 01)"
read number
mkdir "./Homework${number}"
mkdir "./Homework${number}/HW${number}"
mkdir "./Homework${number}/test_hw${number}"
for i in $(seq 1 5)
do
	cp "./hw_making_tools/hw_c_example.c" "./Homework${number}/HW${number}/hw${number}0${i}.c"
	cp "./hw_making_tools/hw_test_in_file_example.py" "./Homework${number}/test_hw${number}/test${number}0${i}.py"
done
cp "./hw_making_tools/hw_makefile_example" "./Homework${number}/HW${number}/Makefile"
cp "./hw_making_tools/hw_README_example.md" "./Homework${number}/HW${number}/README.md"
cp "./hw_making_tools/hw_test_out_file_example.sh" "./Homework${number}/test_hw${number}/hw${number}.sh"