


echo "Enter first filename  : "
read filename1

echo "Enter second filename  : "
read filename2

if [ $filename1 -ot $filename2 ]
then
	echo "$filename1 is older than $filename2"
else
	if [ $filename1 -nt $filename2 ]
	then
		echo "$filename1 is newer than $filename2 "
	else
		echo "Both $filename1 and $filename2 are of same age"
	fi
fi

