#!/bin/bash


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

echo "Main started"
addition 10 20
addition 30 40 50
addition 60 70 80 90
echo "Main over"
