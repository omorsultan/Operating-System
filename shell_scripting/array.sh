#!/bin/bash

numbers=(3 3 5 6 21)

echo "${numbers[@]}"

fruits=("Apple" "Banana" "orrange")

fruits[2]="Tarmuj"
fruits+=("Anar")
for i in "${!fruits[@]}"; 
do
    echo "${fruits[$i]}"
done

echo "${#fruits[@]}"

for i in "${fruits[@]}"; do echo "$i"; done



# echo "Enter numbers (space-separated):"
# read -a numbers   # -a reads words into an array

# echo "You entered: ${numbers[@]}"
# echo "Total elements: ${#numbers[@]}"


echo "Enter fruits (press ENTER after each one, and type 'done' to finish):"

fruits=()
while true; do
    read fruit
    [[ $fruit == "done" ]] && break
    fruits+=("$fruit")
done

echo "Fruits entered: ${fruits[@]}"
echo "Total: ${#fruits[@]}"
