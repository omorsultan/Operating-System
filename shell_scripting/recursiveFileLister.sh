#!/bin/bash

# Read directory from user
read -p "Enter directory path: " dir

# Check if directory exists
if [ ! -d "$dir" ]; then
    echo "❌ Directory does not exist"
    exit 1
fi

# List all files recursively
echo "Listing all files recursively in $dir:"
find "$dir" -type d
