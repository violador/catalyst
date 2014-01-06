#!/bin/bash
src_dir=.
ls -1 $src_dir/*/*.cpp  > src_file_list.txt 
ls -1 $src_dir/*/*.hpp >> src_file_list.txt
lines_counter=0
while read line
do
    echo "File = $line: Number of lines = $(wc -l $line | cut -d " " -f1)"
    lines_counter=$(($lines_counter + $(wc -l $line | cut -d " " -f1)))
done < src_file_list.txt
echo
echo "Total number of lines = $lines_counter"
rm -rf src_file_list.txt
