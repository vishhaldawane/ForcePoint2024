

for i in `ls script*.sh`
do
	echo "file found : $i"
	if [ ! -x $i ]
	then
	echo "Granting EXECUTE permission on $i dated : `date`" >> /tmp/mylog.log
		chmod u+x $i
	fi
		echo "Running : $i on `date` " >> /tmp/mylog.log
		./$i
done
