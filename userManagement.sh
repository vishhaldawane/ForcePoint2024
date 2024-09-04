
echo "User:$LOGNAME executed $0 on $HOSTNAME at `date`" >> script.log

if [ $UID -ne 0 ]
then
	echo "only root users can run this script"
	exit
fi

echo "		USER MANAGEMENT"
echo "		----------------"
echo "		1. Create User"
echo "		2. View User By ID"
echo "		3. View All Users"
echo "		4. Modify User"
echo "		5. Delete User By ID"
echo "		-----------------"
echo "		6. Exit	"

