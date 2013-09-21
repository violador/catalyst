#!/bin/bash
src_dir=.
ls -1 $src_dir/array/*.cpp              > src_file_list.txt 
ls -1 $src_dir/file_system/*.cpp       >> src_file_list.txt
ls -1 $src_dir/lcao_wavefunction/*.cpp >> src_file_list.txt
ls -1 $src_dir/log_file_handler/*.cpp  >> src_file_list.txt
ls -1 $src_dir/molecular_system/*.cpp  >> src_file_list.txt
ls -1 $src_dir/periodic_table/*.cpp    >> src_file_list.txt
ls -1 $src_dir/scf/*.cpp               >> src_file_list.txt
ls -1 $src_dir/settings/*.cpp          >> src_file_list.txt
ls -1 $src_dir/tools/*.cpp             >> src_file_list.txt
ls -1 $src_dir/include/*.hpp           >> src_file_list.txt
lines_counter=0
while read line
do
    echo "File = $line: Number of lines = $(wc -l $line | cut -d " " -f1)"
    lines_counter=$(($lines_counter + $(wc -l $line | cut -d " " -f1)))
done < src_file_list.txt
echo
echo "Total number of lines = $lines_counter"
rm -rf src_file_list.txt
