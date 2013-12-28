#/bin/bash
mkdir __temp_dir
cp array/*.cpp             __temp_dir
cp file_system/*.cpp       __temp_dir
cp lcao_wavefunction/*.cpp __temp_dir
cp log_file_handler/*.cpp  __temp_dir
cp molecular_system/*.cpp  __temp_dir
cp periodic_table/*.cpp    __temp_dir
cp scf/*.cpp               __temp_dir
cp settings/*.cpp          __temp_dir
cp tools/*.cpp             __temp_dir
cp globals/*.cpp           __temp_dir
cp timer/*.cpp             __temp_dir
cp include/*.hpp           __temp_dir
cd __temp_dir
ls -1 *.cpp > file_list.txt
while read line
do
done < file_list.txt
