BLANK_PATTERN=1
BLANK_FILENAME=2
PATTERN_NOT_FOUND=3
FILE_NOT_FOUND=4
PATTERN_FOUND=0

if [ $# -eq 0 ]
then

	echo "Enter pattern to search : "
	read pattern # to accept from keyboard

	if [ -z $pattern ]  # zero string length of pattern
	then
        	echo "Pattern cannot be blank"
        	exit $BLANK_PATTERN
	fi

	echo "In which file ? "
	read filepath # accept from keyboard
	if [ -z $filepath ]
	then

	echo "Filename cannot be blank" 
        	exit $BLANK_FILENAME
	fi
else
	if [ $# -eq 1 ]
	then
		echo "File name is missing"
		exit 5	
	else
		if [ $#  -eq 2 ]
		then
			pattern=$1
			filepath=$2
		else
			if [ $# -gt 2 ]
			then
				echo "Too many files..."
				exit 6
			fi
		fi
	fi
fi


	if [ -f $filepath ] # checks teh presence of the file
	then
        	grep $pattern $filepath --color
        	if [ $? -eq 0 ]; then
               		echo "Pattern Found";
                	exit $PATTERN_FOUND
        	else
                	if [ $? -eq 1 ];then
                        	echo "Pattern NOT found : $pattern"
                        	exit $PATTERN_NOT_FOUND
                	fi
        	fi
	else
        	echo "Data file not found : $filepath"
        	exit $FILE_NOT_FOUND
	fi
