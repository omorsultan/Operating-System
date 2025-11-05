#!/bin/bash

read -p "Enter file name: " file

if [ -f "$file" ]; then
    wc -w "$file"
else
    echo "❌ File not found!"
fi
echo " "
