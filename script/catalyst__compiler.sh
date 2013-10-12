#!/bin/bash
#
#
# == Settings ========================================================================================
#
# The source code list files:
src_file_list="$1.out $1 periodic_table__database.cpp settings__read_state.cpp settings__read_number_of.cpp settings__read_preference.cpp settings__constructor.cpp molecular_system__constructor.cpp sto3g__constructor.cpp molecular_system__get_total_atoms.cpp molecular_system__interatomic_distance.cpp sto3g__gf_overlaping.cpp sto3g__build_overlap_matrix.cpp sto3g__build_kinetic_matrix.cpp sto3g__build_repulsion_matrix.cpp sto3g__exp.cpp sto3g__coeff.cpp sto3g__gf_midpoint.cpp sto3g__error_function.cpp sto3g__gf_product_const.cpp sto3g__two_electrons_repulsion.cpp tools__module.cpp array.hpp scf.hpp scf__constructor.cpp scf__build_density_matrix.cpp scf__get_energy.cpp scf__update_fock_matrix.cpp scf__check_convergence.cpp scf__number_of_iterations.cpp scf__density_matrix.cpp scf__fock_matrix.cpp scf__energy.cpp scf__converged.cpp scf__roothaan_equation_solver.cpp scf__init_scf.cpp array__restore_original_basis_of.cpp array__save_eigens_to.cpp array__save_jacobi_svd_to.cpp array__save_transpose_to.cpp array__delete_array.cpp array__create_array.cpp array__constructor.cpp array__orthonormalize.cpp sto3g__density_matrix.cpp molecular_system__read_input_file.cpp molecular_system__get_com_system.cpp molecular_system__get_nuclear_repulsion.cpp settings__read_value_of.cpp molecular_system__report_input_reading.cpp scf__report_scf_iterations.cpp array__check_if_column_is.cpp scf__check_mo_type.cpp sto3g__interatomic_distance.cpp molecular_system__get_wavefunction.cpp tools__generate_double_type.cpp tools__generate_integral_type.cpp scf__highest_mo.cpp scf__lowest_mo.cpp array__check_if.cpp file_system__constructor.cpp file_system__init.cpp file_system__size.cpp file_system__open_txt_output.cpp file_system__open_bin_output.cpp log_file_handler__init_log_file.cpp log_file_handler__constructor.cpp file_system__open_txt_input.cpp array__operator.cpp global_log__file.cpp array__write.cpp array__destructor.cpp timer__constructor.cpp timer__get.cpp periodic_table__constructor.cpp periodic_table__sto3g_exponent_database.cpp periodic_table__sto3g_total_functions.cpp periodic_table__sto3g_coefficient_database.cpp array__book_data.cpp array__read_temp_file.cpp"
#
# The compilation options:
compiler_options=" -O3 -Wall -DLINUX -DUSE_OMP -o"
#
# The flags to lib linkage:
linkage_flags="-lgsl -lgslcblas -lm -lpthread -lboost_mpi -lboost_serialization -lboost_system -lboost_filesystem -lboost_timer -fopenmp"
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
cp file_system/*.cpp       $temp_dir
cp lcao_wavefunction/*.cpp $temp_dir
cp log_file_handler/*.cpp  $temp_dir
cp molecular_system/*.cpp  $temp_dir
cp periodic_table/*.cpp    $temp_dir
cp scf/*.cpp               $temp_dir
cp settings/*.cpp          $temp_dir
cp tools/*.cpp             $temp_dir
cp globals/*.cpp           $temp_dir
cp timer/*.cpp             $temp_dir
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
    ./$1.out 
    rm -rf $1.out
fi
echo
echo "----------------------------------------------"