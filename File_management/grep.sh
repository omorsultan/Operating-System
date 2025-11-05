#!/bin/bash

# File to search
LOG_FILE="app.log"

# Search for lines containing "ERROR"
echo "Searching for errors in $LOG_FILE..."
grep "ERROR" "$LOG_FILE"

# Count number of errors
ERROR_COUNT=$(grep -c "ERROR" "$LOG_FILE")
echo "Total number of errors: $ERROR_COUNT"

# Check if a specific error exists
if grep -q "Database connection failed" "$LOG_FILE"; then
    echo "Critical error: Database connection failed found!"
else
    echo "No critical database errors found."
fi
