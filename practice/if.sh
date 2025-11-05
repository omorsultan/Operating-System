#!/bin/bash
read -p "Enter a number: " num

if [ $num -gt 10 ]; then
    echo " t is greater than 10. "
elif [ $num -eq 10 ]; then
    echo " num is equal 10 ".
else 
    echo " num is less than 10"
fi