
echo "User:$LOGNAME executed $0 on $HOSTNAME at `date`" >> script.log

#if [ $UID -ne 0 ]
#then
#	echo "only root users can run this script"
#	exit
#fi
function createUser()
{
	echo "Enter user id       : "; read userid
	echo "Enter user name     : "; read username
	echo "Enter user password : "; read userpass
	echo "Enter user location : "; read userloc
	sed  "$ a $userid|$username|$userpass|$userloc" user.lst

	#sed -i.bak "$ a\ 
	#	$userid|$username|$userpass|$userloc \
	#
	#	" user.lst

	if [ $? -eq 0 ]
	then
		echo "User added"
	else
		echo "User addition error"
	fi
}
function viewUser()
{
	echo "Enter user id to search : "
	read userid
	DATA=`grep ^$userid user.lst`
	if [ $? -eq 0 ]
	then
		echo "User found"
		echo "USER ID   : `echo $DATA | cut -d "|" -f1`"
		echo "USER NAME : `echo $DATA | cut -d "|" -f2`"
		echo "USER LOC  : `echo $DATA | cut -d "|" -f4`"
	else
		echo "User not found"
	fi
	
}
function viewAllUsers()
{
		echo "-- showing all users --"
		cut -d "|" -f1,2,4  user.lst
}

function deleteUser()
{
	echo "Enter user id to delete : "
	read userid

	LINE_DATA=`grep -n -w ^$userid user.lst`
	if [ $? -eq 0 ]
	then
		echo "User found"
		LINENUM=`echo $LINE_DATA | cut -d ":" -f1`
		DATA=`echo $LINE_DATA | cut -d ":" -f2-`

		echo "RECORD NO : $LINENUM"
		echo "USER ID   : `echo $DATA | cut -d "|" -f1`"
		echo "USER NAME : `echo $DATA | cut -d "|" -f2`"
		echo "USER LOC  : `echo $DATA | cut -d "|" -f4`"
		echo "Are you sure to delete above record :"
		read confirm
		if [ $confirm = 'y' -o $confirm = 'Y' ]
		then
			echo "Deleting the record"
			sed -i.bak $LINENUM"d" user.lst
		else
			echo "Record deletion discarded"
		fi
	else
		echo "User not found"
	fi
}
function modifyUser()
{
	
	echo "Enter user id to modify: "
	read userid

	LINE_DATA=`grep -n -w ^$userid user.lst`
	if [ $? -eq 0 ]
	then
		echo "User found"
		LINENUM=`echo $LINE_DATA | cut -d ":" -f1`
		DATA=`echo $LINE_DATA | cut -d ":" -f2-`

		echo " -- OLD DATA IS BELOW --"
		echo "RECORD NO : $LINENUM"

		echo "DATA : $DATA"

		USER_ID=`echo $DATA | cut -d "|" -f1`
		USER_NAME=`echo $DATA | cut -d "|" -f2`
		USER_PASS=`echo $DATA | cut -d "|" -f3`
		USER_LOC=`echo $DATA | cut -d "|" -f4`
		
		echo "USER ID   : $USER_ID"
		echo "USER NAME : $USER_NAME"
		echo "USER LOC  : $USER_LOC"

		echo "-- ENTER NEW DATA BELOW --"

		echo "Enter NEW user name     : "; read username
		echo "Enter NEW user password : "; read userpass
		echo "Enter NEW user location : "; read userloc
		echo "Are you sure to modify above record :"
		read confirm
		if [ $confirm = 'y' -o $confirm = 'Y' ]
		then
			echo "Modifying the record"
			sed "$LINENUM s/$USER_NAME|$USER_PASS|$USER_LOC/$username|$userpass|$userloc/" user.lst
		else
			echo "Record modification discarded"
		fi
	else
		echo "User not found"
	fi
}

choice=0
while [ $choice -ne 6 ]
do
	clear
	echo "		USER MANAGEMENT"
	echo "		----------------"
	echo "		1. Create User"
	echo "		2. View User By ID"
	echo "		3. View All Users"
	echo "		4. Modify User"
	echo "		5. Delete User By ID"
	echo "		-----------------"
	echo "		6. Exit	"
	echo "		-----------------"
	read choice # accept from keyboard
	if [ -z $choice ]
	then
		echo "Choice cannot be blank"
		choice=0
	fi

	case $choice in
		1) echo "User Creation" 
			createUser # function is invoked...
			;;
		2) echo "View User By ID" 
			viewUser
			;;
		3) echo "View All Users" 
			viewAllUsers
			;;
		4) echo "Modify User"
			modifyUser
			;;
		5) echo "Delete User By Id" 
			deleteUser
			;;
		*) echo "Mismatched choice"
	esac
	echo "Press ENTER to continue.."
	read anykey
done


