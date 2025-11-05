#!/bin/bash

# read -p "Enter file name: " file
file=/home/omor/os/shell_scripting/fileCheck.sh
if [ -f "$file" ]; then
    echo "✅ $file exists and is a regular file."
else
    echo "❌ $file does not exist or is not a regular file."
fi

dir=/home/omor/os/O

if [ -d "$dir" ]; then
    echo "$dir exists"
else 
    echo " $dir not exists."
fi