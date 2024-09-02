echo "Enter the filename  : "
read filename

if [ -z $filename ]
then
        echo "Filename canot be blank"
        exit 1
else
        if [ -f $filename ]
        then
                echo "--- Searching hard links ---"
                INODE_TO_SEARCH=`ls -i $filename | cut -d  " " -f1`
                echo "Inode is : $INODE_TO_SEARCH"
                #ls -ilR | grep -w ^$INODE_TO_SEARCH
                find . -inum $INODE_TO_SEARCH
        else
                echo "File does not exist "
                exit 2
        fi
fi


