#!/bin/bash

# Noah Tonnesen
# 260948469

# Ex. 1 - Simple Backup and Archive Script (5pts)

pwd
ls *.txt

mkdir ./backup 
cd ./backup
echo "Moved to backup directory"
pwd

cp ../*txt ./
echo "Copied all text files to backup directory" 

echo "Current backup:" > date.txt
echo "$(date)" >> date.txt
cat date.txt

tar -zcvf txtarchive.tgz *txt
echo "Created archive txtarchive.tgz"
ls -l

