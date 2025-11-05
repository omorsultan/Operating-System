#!/bin/bash

Dir=/home/omor/os/synchronization
dir=/home/omor/os/synchronization
# /home/omor/os/synchronization/
File=$(find $Dir -maxdepth 1 -type f | wc -l)
file=$(find "$dir" -maxdepth 1 -type f | wc -l)
echo "file : $File "