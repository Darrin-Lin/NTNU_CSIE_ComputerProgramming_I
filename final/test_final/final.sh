#!/bin/sh
hw=fin
make_clean=0

for n in $(
	seq 1 3
); do
	if ! [ -d "0${n}" ]; then
		mkdir ./0${n}
	fi

	if ! [ -d "0${n}/in" ]; then
		mkdir ./0${n}/in
	fi

	python test${hw}0${n}.py

	if ! [ -d "0${n}/out" ]; then
		mkdir ./0${n}/out
	fi

	if ! [ -f "${hw}0${n}" ]; then
		if ! [ -f "../fin/${hw}0${n}" ]; then
			make -C ../${hw}
			make_clean=1
		fi
		cp ../${hw}/${hw}0${n} .
	fi

	for i in $(seq 0 9); do
		./${hw}0${n} <./0${n}/in/${hw}0${n}_0${i}.in >./0${n}/out/${hw}0${n}_0${i}.out
	done
	for i in $(seq 10 19); do
		if [ -f "./0${n}/in/${hw}0${n}_${i}.in" ]; then
			./${hw}0${n} <./0${n}/in/${hw}0${n}_${i}.in >./0${n}/out/${hw}0${n}_${i}.out
		fi
	done
done
if [ ${make_clean} -eq 1 ]; then
	make clean -C ../${hw}
fi