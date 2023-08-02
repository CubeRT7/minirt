#!/bin/sh

parse_test()
{
	echo "Test Case : $1"
	read -p "Press any key to continue..."
	eval $1
}

file_list=$(find data/parse_test -type f)

for file in ${file_list[@]}; do
	parse_test "./miniRT $file"
done
