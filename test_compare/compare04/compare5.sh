#!/bin/sh

# echo "hw number:"
# read hw
# #hw=
# echo part number:
# read n
# echo "directory name:"
# read directory
# echo "file name:"
# read filename
cp ../../Homework4/HW04/hw0405.c .
gcc hw0405.c -o ./05/hw0405
for i in $(seq 0 9); do
    echo " ${i}--------------------"
    ./05/hw0405 <./hw0405/in/0${i}.in >./05/hw0405_0${i}.out
    diff ./05/hw0405_0${i}.out ./hw0405/out/0${i}.out
done
for i in $(seq 10 19); do
    echo "${i}--------------------"
    ./05/hw0405 <./hw0405/in/${i}.in >./05/hw0405_${i}.out
    diff ./05/hw0405_${i}.out ./hw0405/out/${i}.out

done

# for i in $(seq 0 9); do
#     diff ./0${n}/out/hw0${hw}0${n}_0${i}.out ./${directory}/${filename}0${hw}0${n}_0${i}.out
# done
# for i in $(seq 10 19); do
#     if [ -f "./0${n}/in/hw0${hw}0${n}_${i}.out" ]; then
#         diff ./0${n}/out/hw0${hw}0${n}_${i}.out ./${directory}/${filename}0${hw}0${n}_${i}.out
#     fi
# done
