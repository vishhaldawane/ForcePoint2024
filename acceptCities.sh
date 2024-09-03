#!/bin/bash

echo "Total cities : $#"
echo "Actual cities : $*"

echo "1st $1"
echo "2nd $2"
echo "3rd $3"
echo "4th $4"

x=1

while [ $x -le 10 ]	# -lt -le,  -gt, -ge, -eq, -ne only ints
do
  echo "x is $x"
  x=`expr $x + 1` # expression as math line
done
echo "----------"
for i in 1 2 3 Mumbai 5 6 70.45 8 9 10.4 y female 88
do
   echo "i is $i"
done

echo "-----"

for i in "$*" # space separated are not considered as a single city
do
	echo "CITY is : $i"
done

echo "Now ..."

for i in "$@"  # for space separated city names in the loop
do
	echo "CITY is : $i"
done

