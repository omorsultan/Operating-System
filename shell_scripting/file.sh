#!/bin/bash

# read -p "Enter file name: " file
file=/home/omor/os/a.cpp

if [[ -e "$file" ]]; then
    echo "$file exists."

    [ -r "$file" ] && echo "Readable"
    [ -w "$file" ] && echo "Writable"
    [ -x "$file" ] && echo "Executable"

else
    echo "File does not exist."
fi
