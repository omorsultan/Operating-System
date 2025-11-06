#!/bin/bash

find="Apple"
replace="APPLE"

sed -i "s/${find}/${replace}/gi" newfile.txt
