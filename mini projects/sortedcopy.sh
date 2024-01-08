#!/bin/bash

# Noah Tonnesen
# 260948469

# Ex. 3 - Sorted Directory Copy


# if the user did not give 2 arguments, print error and usage, exit code 1
if [ $# -ne 2 ]; then
	echo "Error: Expected two parameters."
	echo "Usage: ./shortedcopy.sh <sourcedirectory> <targetdirectory>"
	exit 1
fi

# if <sourcedirectory> is not a directory or does not exist, print error and usage, exit code 2 
if [ ! -d "$1" ]; then
	echo "Error: Input parameter #1 '"$1"' is not a directory"
	echo "Usage: ./sortedcopy.sh <sourcedirectory> <targetdirectory>"
	exit 2
fi

# if <targetdirectory> already exists, enter the while loop and ask if they would like to overwrite it
if [ -e "$2" ]; then
	read -p "Directory '"$2"' already exists. Overwrite? (y/n)" ans
	# pattern match the response, if 'y' delete <targetdirectory> and create a new empty directory
        # with the same name, else exit code 3 
	case $ans in
		y) rm -r "$2"; mkdir "$2" ;;
		*) exit 3 ;;
	esac
fi

# we now know we have exactly two arguments, <sourcedirectory> is a valid directory, and <targetdirectory>
# exists and is empty

# echo the reversed list of files in <sourcedirectory> into the variable rev_list 
rev_list=$(echo $(ls -r $1))

# initialize an accumulator variable to 1
i=1

# iterate through rev_list
# if a file is is a regular file, copy it from <sourcedirectory> to <targetdirectory> under the new name
# "$i.$file", then increment i by one
# if the file is not a regular file, proceed to the next file in rev_list and do not increment i
for file in $rev_list; do 
	if [ -f "$1/$file" ]; then
		cp "$1/$file" "$2/$i.$file"
		i=$((i+1))
	fi
done
exit 0
