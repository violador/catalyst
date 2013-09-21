#!/bin/bash
echo "----------------------------------------------"
echo
#
#
mpirun_dir=/usr/local/bin
cpus=2
#
#
mpic++ -o test__open_mpi_install.out test__open_mpi_install.cpp
#
#
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
#
#
if [ -e test__open_mpi_install.out ];
then
    chmod 777 test__open_mpi_install.out
    echo "The mpirun directory used was" $mpirun_dir
    echo
    $mpirun_dir/mpirun -np $cpus $PWD/test__open_mpi_install.out 
    rm -rf test__open_mpi_install.out
fi
#
#
echo
echo "----------------------------------------------"
