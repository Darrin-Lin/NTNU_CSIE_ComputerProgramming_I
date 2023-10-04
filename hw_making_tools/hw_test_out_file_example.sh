#!/bin/sh
hw=1

for n in $(
	seq 1 5
); do
	if ! [ -d "0${n}" ]; then
		mkdir ./0${n}
	fi

	if ! [ -d "0${n}/in" ]; then
		mkdir ./0${n}/in
	fi

	python test010${n}.py

	if ! [ -d "0${n}/out" ]; then
		mkdir ./0${n}/out
	fi

	if ! [ -f "hw010${n}" ]; then
		cp ../HW01/hw010${n} .
	fi

	for i in $(seq 0 9); do
		./hw0${hw}0${n} <./0${n}/in/hw0${hw}0${n}-${i}.in >./0${n}/out/hw0${hw}0${n}-${i}.out
	done
	for i in $(seq 10 19); do
		if [ -f "./0${n}/in/hw0${hw}0${n}-${i}.in" ]; then
			./hw0${hw}0${n} <./0${n}/in/hw0${hw}0${n}-${i}.in >./0${n}/out/hw0${hw}0${n}-${i}.out
		fi
	done
done
