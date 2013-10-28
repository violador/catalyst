// ../src/include/lcao_wavefunction.hpp ------------------------------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description:
//
// References:
//
// ------------------------------------------------------------------------------------- //
#ifndef __LCAO_WAVEFUNCTION_HPP
    #define __LCAO_WAVEFUNCTION_HPP
    #include "globals.hpp"
    #include "settings.hpp"
    #include "global_settings.hpp"
    #include "array.hpp"
    #include "global_log.hpp"
    #include "periodic_table.hpp"
//
//
//
class lcao_wavefunction
{
    private:
//
    settings *config;
    array s_matrix;
    array t_matrix;
    array v_matrix1;
    array v_matrix2;
    array h_matrix;
    unsigned int current_level;
    bool overlap_matrix_ready;
    bool kinetic_matrix_ready;
    bool hamiltonian_matrix_ready;
    bool repulsion_matrix1_ready;
    bool repulsion_matrix2_ready;
//
//  check_matrix_size(): To check the sizes of the given matrices used to store
//                       the data and to resize it when needed.
    void check_matrix_size(array &given_matrix, const unsigned int &dimension_size);
//
//  Including the inline/template/private member functions:
    #include "lcao_wavefunction__gf_product_const.cpp"
    #include "lcao_wavefunction__error_function.cpp"
    #include "lcao_wavefunction__interatomic_distance.cpp"
    #include "lcao_wavefunction__gf_midpoint.cpp"
    #include "lcao_wavefunction__gf_overlaping.cpp"
    #include "lcao_wavefunction__init_matrices.cpp"
//
    public:
//
//  Class identifier:
    static const int id = 30988;
//
//  Declaring the class constructor:
    lcao_wavefunction();
//
//  Declaring the class constructor:
    lcao_wavefunction(array  &type,
                      array  &x, 
                      array  &y, 
                      array  &z, 
                      const unsigned int given_theory_level = DEFAULT_TASK_NUMBER);
//
//  build_matrices(): To calculate all the matrices.
    void build_matrices(array &type,
                        array &x,
                        array &y,
                        array &z,
                        const unsigned int &given_theory_level);
//
//  build_overlap_matrix(): To calculate the overlaping integral, S, and to build the overlap
//                          matrix.
    void build_overlap_matrix(array &s_matrix,
                              array &type,
                              array &x,
                              array &y,
                              array &z,
                              unsigned int theory_level = 1);
//
//  build_kinetic_matrix(): To calculate the kinetic integral, T, and to build the kinetic
//                          matrix.
    void build_kinetic_matrix(array &t_matrix,
                              array &type,
                              array &x,
                              array &y,
                              array &z,
                              unsigned int theory_level = 1);
//
//  build_repulsion_matrix_1(): To calculate the one electron repulsion integral, V, 
//                              and to build the repulsion matrix.
    void build_repulsion_matrix_1(array &v_matrix1,
                                  array &type,
                                  array &x,
                                  array &y,
                                  array &z,
                                  unsigned int theory_level = 1);
//
//  build_repulsion_matrix_2(): To calculate the two electron repulsion integral, V, 
//                              and to build the repulsion matrix (four dimensions).
    void build_repulsion_matrix_2(array &v_matrix2,
                                  array &type,
                                  array &x,
                                  array &y,
                                  array &z,
                                  unsigned int theory_level = 1);
//
//  Including the inline/template/public member functions:
    #include "lcao_wavefunction__get_overlap_matrix.cpp"
    #include "lcao_wavefunction__get_kinetic_matrix.cpp" 
    #include "lcao_wavefunction__get_core_hamiltonian_matrix.cpp"
    #include "lcao_wavefunction__get_one_electron_repulsion_matrix.cpp"
    #include "lcao_wavefunction__get_two_electron_repulsion_matrix.cpp"
//
};
#endif
