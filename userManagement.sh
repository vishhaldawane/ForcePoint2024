
echo "User:$LOGNAME executed $0 on $HOSTNAME at `date`" >> script.log

#if [ $UID -ne 0 ]
#then
#	echo "only root users can run this script"
#	exit
#fi

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
		1) echo "User Creation" ;;
		2) echo "View User By ID" ;;
		3) echo "View All Users" ;;
		4) echo "Modify User";;
		5) echo "Delete User By Id" ;;
		*) echo "Mismatched choice"
	esac
	echo "Press ENTER to continue.."
	read anykey
done


