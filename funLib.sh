echo "funLib.sh is running...in PID:$$ SHLVL:$SHLVL"
function addition()
{
  echo "Addition function invoked with $# arguments "
  sum=0
  for i in $*
  do
    sum=`expr $sum + $i`
  done
  echo "Addition is : $sum"
  echo "---------------------------"
}

function subtraction()
{
  echo "Subtraction function invoked with $# arguments "
  sum=0
  for i in $*
  do
    sum=`expr $sum - $i`
  done
  echo "Subtraction is : $sum"
  echo "---------------------------"
}
