
echo "Enter filename  : "
read filename


if [ -d $filename ]
then
	echo "$filename is a directory"
else 
	if [ -L $filename ]
	then
		echo "$filename is a soft link file"
	else
		if [ -b $filename ]
		then
			echo "$filename is a block device"
		else
			if [ -c $filename ]
			then
				echo "$filename is a character device"	
			else
				if [ -p $filename ]
				then
					echo "$filename is a socket device"
				else
					if [ -e $filename ]
					then
						echo "Its a file"
					else
						echo "File not found"
					fi
				fi
			fi
		fi
	fi
fi

				

