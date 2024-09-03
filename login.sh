

echo "Enter username : "
read username

echo "Enter password : "
read -s password

echo "-----"

USER_ID_NAME=`cut -d "|" -f1,2 user.lst | grep -w $username`
if [ $? -eq 0 ]
then
	USERNAME=`echo $USER_ID_NAME | cut -d "|" -f2`	
	if [ $username = $USERNAME ]
	then
		echo "User found     : $USERNAME"
		PASSWD=`cut -d "|" -f2,3 user.lst | grep -w ^$USERNAME | cut -d "|" -f2`
		if [ $password = $PASSWD ]
		then
			echo "Correct Password"
		else
			echo "Incorrect Password"
		fi
	else
		echo "User NOT found"
	fi
else
	echo "User NOT found"
fi




