#!/bin/bash

echo "Enter a string:"
read str
str2=$(echo "$str" | rev)

if [ "$str" == "$str2" ]; then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi
