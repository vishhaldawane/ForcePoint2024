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
echo "Main started"
addition 20 10
addition 150 40 30
addition 160 20 10 5
subtraction 20 10
subtraction 150 40 30
subtraction  160 20 10 5
echo "Main over"
