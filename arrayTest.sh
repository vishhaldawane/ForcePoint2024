#!/bin/bash


# C syntax : int ary[]={10,20,30};


#students=(Pradhyumn Vishal Chaitanya Shreya Khetan)
students=(*.sh)


echo "Length  of array is : ${#students[*]}"
echo "Content of array is : ${students[*]}"
echo "-----------------"
echo "1st element of array is : ${students[0]}"
echo "2nd element of array is : ${students[1]}"
echo "3rd element of array is : ${students[2]}"
echo "4th element of array is : ${students[3]}"
echo "5th element of array is : ${students[4]}"
echo "---------------"

lengthOfStudents=${#students[*]}
x=0
while [ $x -lt $lengthOfStudents ]
do
#	echo "value at $x position : ${students[$x]}"
	filename=${students[$x]} 
	if [ ! -x $filename ]
	then
		echo "File does not execute permission    : $filename"
	else
		echo "File already has execute permission : $filename"
		# ./$filename # to run it
	fi
	x=`expr $x + 1 `  # x=((x+1))
done




