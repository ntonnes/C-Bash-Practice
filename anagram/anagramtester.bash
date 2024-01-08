#!/bin/bash

echo "Test 1: mary and ramy"
./anagram mary ramy
echo "Expected output message: Anagram"

echo "Test 2: bob and lary"
./anagram bob lary
code=$?
if [ $code == 1 ]; then
	echo "Exited with expected return code: 1"  
else
	echo "Exited with unexpected return code: $code (Expected 1)"
fi

