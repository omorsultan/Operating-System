#!/bin/bash

file="newfile.txt"

echo "Analyzing file: $file"
echo

# Line count
lines=$(wc -l < "$file")
echo "Lines: $lines"

# Word count
words=$(wc -w < "$file")
echo "Words: $words"

# Character count
chars=$(wc -m < "$file")
echo "Characters: $chars"

# Count specific word (case-insensitive) - Example: "apple"
word_count=$(grep -i -o "apple" "$file" | wc -l)
echo "Occurrences of 'apple': $word_count"
