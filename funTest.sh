#!/bin/bash
LIB_FILE=funLib.sh
echo "$0 is invoking $LIB_FILE from PID:$$ in SHLVL: $SHLVL"

if [ -f $LIB_FILE ]
then
	if [ ! -x $LIB_FILE ]
	then
		echo "Granting execute permission on $LIB_FILE"
		chmod u+x $LIB_FILE
	else
		echo "Execute permission is already present"
	fi
	echo "Executing .... $LIB_FILE"
	. ./$LIB_FILE 
else
	echo "$LIB_FILE is missing"
	exit 1
fi

echo "Main started"
addition 20 1
addition 150 40 30
addition 160 20 10 5
subtraction 20 10
subtraction 150 4 3
subtraction  160 2 1 5
echo "Main over"
