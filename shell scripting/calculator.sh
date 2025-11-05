#!/bin/bash

# Function to add two numbers
add() {
    echo "$(($1 + $2))"
}

# Function to subtract two numbers
subtract() {
    echo "$(($1 - $2))"
}

# Function to multiply two numbers
multiply() {
    echo "$(($1 * $2))"
}

# Function to divide two numbers
divide() {
    if [ $2 -eq 0 ]; then
        echo "Error: Division by zero!"
    else
        echo "$(($1 / $2))"
    fi
}

# Main program
echo "Basic Calculator"
echo "Select operation:"
echo "1) Addition"
echo "2) Subtraction"
echo "3) Multiplication"
echo "4) Division"

read -p "Enter choice [1-4]: " choice
read -p "Enter first number: " num1
read -p "Enter second number: " num2

case $choice in
    1)
        result=$(add $num1 $num2)
        echo "Result: $result"
        ;;
    2)
        result=$(subtract $num1 $num2)
        echo "Result: $result"
        ;;
    3)
        result=$(multiply $num1 $num2)
        echo "Result: $result"
        ;;
    4)
        result=$(divide $num1 $num2)
        echo "Result: $result"
        ;;
    *)
        echo "Invalid choice!"
        ;;
esac
