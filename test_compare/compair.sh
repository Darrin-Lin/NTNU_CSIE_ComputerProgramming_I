#!/bin/sh

echo "hw number:"
read hw
#hw=
echo part number:
read n
echo "directory name:"
read directory
echo "file name:"
read filename

for i in $(seq 0 9); do
    diff ./0${n}/out/hw0${hw}0${n}_0${i}.out ./${directory}/${filename}0${hw}0${n}_0${i}.out
done
for i in $(seq 10 19); do
    if [ -f "./0${n}/in/hw0${hw}0${n}_${i}.out" ]; then
        diff ./0${n}/out/hw0${hw}0${n}_${i}.out ./${directory}/${filename}0${hw}0${n}_${i}.out
    fi
done
