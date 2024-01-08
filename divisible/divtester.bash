#!/bin/bash

echo "Test 1: not divisible & not increasing"
echo -e "10 5 7\n" | ./divisible
echo "Expected output message: Not divisible & Not increasing"

echo "Test 2: divisible & not increasing"
echo -e "5 20 10\n" | ./divisible

code=$?
if [ $code == 2 ]; then
	echo "Exited with expected return code: 2"
else
	echo "Exited with unexpected return code: $code (Expected 2)"
fi

