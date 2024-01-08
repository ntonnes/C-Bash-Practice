#!/bin/bash

# Noah Tonnesen
# 260948469

# Ex. 2 - Analyzing User Input

echo "Please enter your sentence:"
read sentence 

echo "Your input has $(echo $sentence|wc -w) words and $(echo $sentence|wc -c) characters"
