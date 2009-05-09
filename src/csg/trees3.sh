#!/bin/sh

printf "/* Note - this file generated by trees3.sh */\n\n#include \"trees3.h\"\n\n" > trees3.cpp
printf "#ifndef TREES3_H\n#define TREES3_H\n\n"            > trees3.h

printf "Cheese...\n"

SEED=415039

for i in 25 50 75 100 125 150 175 200
do 
	echo $i;
	cheese 0 0.19 ${SEED} $i > tmp.txt;
	printf "\nchar cheeseGraphite%dTree[] = \n"    $i >> trees3.cpp;
	printf "extern char cheeseGraphite%dTree[];\n" $i >> trees3.h;
	text2src tmp.txt >> trees3.cpp;
done

printf "\n" >> trees3.h

printf "3Axis...\n"

SEED=415039

for i in 25 50 75 100 125 150 175 200
do 
	echo $i;
	3axis 0 ${SEED} $i > tmp.txt;
	printf "\nchar threeAxisGraphite%dTree[] = \n"    $i >> trees3.cpp;
	printf "extern char threeAxisGraphite%dTree[];\n" $i >> trees3.h;
	text2src tmp.txt >> trees3.cpp;
done

printf "\n#endif\n" >> trees3.h

