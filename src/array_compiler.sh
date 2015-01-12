#!/bin/bash
#
#
# == Settings ========================================================================================
#
# The source code list of files:
src_file_list="$1.out $1 tools__module.cpp tools__first_gf.cpp tools__convert_enum.cpp"
#
# The compilation options:
compiler_options="-std=c++11 -O3 -Wall -DLINUX -DUSE_OMP -DUSE_MPI -o"
#
# The flags to lib linkage:
linkage_flags="-lgsl -lgslcblas -lm -lpthread -lboost_serialization -lboost_system -lboost_filesystem -lboost_timer -fopenmp"
#
# The number of CPUs:
cpus=8
#
# The temp dir used to compile:
temp_dir=.
#
# The mpirun directory:
mpirun_dir=/usr/local/bin
#
# ====================================================================================================
#
#
# Cheking inputs:
if [ "$1" == "" ]
then
    echo "----------------------------------------------"
    echo
    echo "No valid main source file is given."
    echo
    echo "----------------------------------------------"
    exit
fi
#
#
# Preparing to compile:
echo "----------------------------------------------"
echo
echo "[preparing...]"
cp $1 $1.bkp
cp array/*.cpp             $temp_dir
#cp basis_set/*.cpp         $temp_dir
#cp file_system/*.cpp       $temp_dir
#cp lcao_wavefunction/*.cpp $temp_dir
#cp log_file_handler/*.cpp  $temp_dir
#cp molecular_system/*.cpp  $temp_dir
#cp periodic_table/*.cpp    $temp_dir
#cp scf/*.cpp               $temp_dir
#cp settings/*.cpp          $temp_dir
cp tools/*.cpp             $temp_dir
#cp globals/*.cpp           $temp_dir
#cp timer/*.cpp             $temp_dir
cp math/*.cpp              $temp_dir
#cp control/*.cpp           $temp_dir
cp include/*.hpp           $temp_dir
cd $temp_dir
echo
echo "[compiling...]"
#
#
# Compiling without MPI:
g++ $compiler_options $src_file_list $linkage_flags
#
# Compiling with MPI:
#mpic++ $compiler_options $src_file_list $linkage_flags
#
#
# Running:
rm -rf *.cpp *.hpp
mv $1.bkp $1
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
if [ -e $1.out ];
then
    echo
    echo "[running...]"
    #$mpirun_dir/mpirun -np $cpus $PWD/test__catalyst.out
    time ./$1.out
    rm -rf $1.out
fi
echo
echo "----------------------------------------------"
