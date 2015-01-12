#!/bin/bash
#
#
# == Settings ========================================================================================
#
# The source code list of files:
src_file_list="$1.out $1 settings__constructor.cpp molecular_system__constructor.cpp molecular_system__get_total_atoms.cpp molecular_system__interatomic_distance.cpp tools__module.cpp array.hpp scf.hpp scf__constructor.cpp scf__build_density_matrix.cpp scf__get_energy.cpp scf__update_fock_matrix.cpp scf__check_convergence.cpp scf__roothaan_equation_solver.cpp array__restore_original_basis_of.cpp array__eigen.cpp array__delete_array.cpp array__constructor.cpp array__orthonormalize.cpp molecular_system__read_input_file.cpp molecular_system__get_com_system.cpp molecular_system__get_nuclear_repulsion.cpp molecular_system__report_input_reading.cpp scf__report_scf_iterations.cpp molecular_system__get_wavefunction.cpp file_system__constructor.cpp file_system__open_txt_output.cpp file_system__open_bin_output.cpp log_file_handler__init_log_file.cpp log_file_handler__constructor.cpp file_system__open_txt_input.cpp global_log__file.cpp array__write.cpp array__destructor.cpp timer__constructor.cpp  periodic_table__constructor.cpp array__book_data.cpp array__basic_assignment.cpp array__addition_assignment.cpp array__subtraction_assignment.cpp array__multiplication_assignment.cpp array__addition.cpp array__subtraction.cpp array__multiplication.cpp array__build_orthonormalizer_form.cpp settings__destructor.cpp settings__theory_database.cpp file_system__open_bin_input.cpp lcao_wavefunction__build_overlap_matrix.cpp lcao_wavefunction__build_kinetic_matrix.cpp lcao_wavefunction__build_repulsion_matrix_1.cpp lcao_wavefunction__build_repulsion_matrix_2.cpp lcao_wavefunction__check_matrix_size.cpp lcao_wavefunction__build_matrices.cpp lcao_wavefunction__constructor.cpp settings__basic_assignment.cpp global_settings__config.cpp lcao_wavefunction__build_hamiltonian_matrix.cpp lcao_wavefunction__kinetic_integral.cpp lcao_wavefunction__gf_norm.cpp lcao_wavefunction__overlap_integral.cpp lcao_wavefunction__cgf_overlap_integral.cpp tools__first_gf.cpp lcao_wavefunction__cgf_kinetic_integral.cpp lcao_wavefunction__boys_function.cpp lcao_wavefunction__check_eri_type.cpp lcao_wavefunction__os_scheme_ssss_eri.cpp lcao_wavefunction__os_scheme_psss_eri.cpp lcao_wavefunction__os_scheme_aux_eri.cpp lcao_wavefunction__os_scheme_overlap_integral.cpp lcao_wavefunction__os_scheme_psps_eri.cpp lcao_wavefunction__os_scheme_ppss_eri.cpp lcao_wavefunction__os_scheme_ppps_eri.cpp lcao_wavefunction__os_scheme_pppp_eri.cpp tools__convert_enum.cpp settings__read_inputs.cpp settings__read_levels.cpp log_file_handler__report_input_list.cpp array__is_positive.cpp array__is_negative.cpp array__is_null.cpp settings__check_total_memory.cpp settings__check_free_memory.cpp array__reset_properties.cpp basis_set__check_sto3g_size.cpp basis_set__init_sto3g_coeff.cpp basis_set__init_sto3g_expon.cpp basis_set__constructor.cpp periodic_table__update_data.cpp file_system__basic_assignment.cpp settings__scan_config_file.cpp array__build_jacobi_svd.cpp timer__save_timing.cpp array__random_2d_array.cpp"
#
# The compilation options:
compiler_options="-std=c++11 -O0 -Wall -DLINUX -DUSE_OMP -DUSE_MPI -o"
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
cp basis_set/*.cpp         $temp_dir
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
cp math/*.cpp              $temp_dir
cp control/*.cpp           $temp_dir
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
