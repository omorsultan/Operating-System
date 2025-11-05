#!/bin/bash

echo "Demonstrating ;, &&, and || operators in Bash"

# Example 1: Using ;
echo
echo "Example 1: Using ;"
echo "Command1; Command2 always runs"
echo "Hello"; echo "World"  # Both commands run regardless

# Example 2: Using &&
echo
echo "Example 2: Using &&"
mkdir /home/nayem && echo "✅ Folder created successfully"  # Only prints if mkdir succeeds

# Example 3: Using ||
echo
echo "Example 3: Using ||"
mkdir /tmp/test_folder || echo "❌ Failed to create folder (probably already exists)"  # Only prints if mkdir fails

# Example 4: Combining && and ||
echo
echo "Example 4: Combining && and ||"
mkdir /tmp/test_folder2 && echo "✅ Folder2 created successfully" || echo "❌ Folder2 creation failed"
