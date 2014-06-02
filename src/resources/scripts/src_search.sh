#!/bin/bash
src_dir=.
ls -1 $src_dir/*/*.cpp  > src_file_list.txt 
ls -1 $src_dir/*/*.hpp >> src_file_list.txt 
lines_counter=0
while read line
do
    echo
    echo "File = $line:"
    echo "--------------------------------------------------"
    grep $1 $line
    echo "--------------------------------------------------"
    echo
done < src_file_list.txt
rm -rf src_file_list.txt
