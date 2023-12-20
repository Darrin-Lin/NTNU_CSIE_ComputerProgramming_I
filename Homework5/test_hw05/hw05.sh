#!/bin/sh
hw=5
make_clean=0

for n in $(
	seq 1 4
); do
	if ! [ -d "0${n}" ]; then
		mkdir ./0${n}
	fi

	if ! [ -d "0${n}/in" ]; then
		mkdir ./0${n}/in
	fi

	python3 test0${hw}0${n}.py

	if ! [ -d "0${n}/out" ]; then
		mkdir ./0${n}/out
	fi

	if ! [ -f "hw0${hw}0${n}" ]; then
		if ! [ -f "../HW0${hw}/hw0${hw}0${n}" ]; then
			make -C ../HW0${hw}
			make_clean=1
		fi
		cp ../HW0${hw}/hw0${hw}0${n} .
	fi

	for i in $(seq 0 9); do
		./hw0${hw}0${n} <./0${n}/in/hw0${hw}0${n}_0${i}.in >./0${n}/out/hw0${hw}0${n}_0${i}.out
	done
	for i in $(seq 10 19); do
		if [ -f "./0${n}/in/hw0${hw}0${n}_${i}.in" ]; then
			./hw0${hw}0${n} <./0${n}/in/hw0${hw}0${n}_${i}.in >./0${n}/out/hw0${hw}0${n}_${i}.out
		fi
	done
done

# 05
if ! [ -d "05" ]; then
	mkdir ./05
fi

if ! [ -d "05/in" ]; then
	mkdir ./05/in
fi

python3 test0${hw}05.py

if ! [ -d "05/out" ]; then
	mkdir ./05/out
fi

if ! [ -f "hw0${hw}05" ]; then
	if ! [ -f "../HW0${hw}/hw0${hw}05" ]; then
		make -C ../HW0${hw}
		make_clean=1
	fi
	cp ../HW0${hw}/hw0${hw}05 .
fi

for i in $(seq 0 9); do
	./hw0${hw}05 <./05/in/hw0${hw}05_0${i}.in
	mv output.fm2 ./05/out/output0${i}.fm2
done
for i in $(seq 10 19); do
	if [ -f "./05/in/hw0${hw}05_${i}.in" ]; then
		./hw0${hw}05 <./05/in/hw0${hw}05_${i}.in
		mv output.fm2 ./05/out/output${i}.fm2
	fi
done

if [ ${make_clean} -eq 1 ]; then
	make clean -C ../HW0${hw}
fi
