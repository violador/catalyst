// ../src/include/lcao_wavefunction.hpp ------------------------------------------------ //
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
    #include "scf.hpp"
    #include "global_log.hpp"
    #include "periodic_table.hpp"
//
//
//
class lcao_wavefunction
{
    private:
//
//  Declaring the data members:
    settings *config;                 //
    array s_matrix;                   //
    array t_matrix;                   //
    array v_matrix1;                  //
    array v_matrix2;                  //
    array h_matrix;                   //
    array *f_matrix;                  //
    array *p_matrix;                  //
    array *wavefunction;              //
    unsigned int current_level;       //
    bool overlap_matrix_ready;        //
    bool kinetic_matrix_ready;        //
    bool repulsion_matrix1_ready;     //
    bool repulsion_matrix2_ready;     //
    bool hamiltonian_matrix_ready;    //
    algorithm::scf iterative_routine; //
//
//  check_matrix_size(): To check the sizes of the given matrices used to store
//                       the data and to resize it when needed.
    void check_matrix_size(array &given_matrix, const unsigned int &dimension_size);
//
//  build_overlap_matrix(): To calculate the overlaping integral, S, and to build the overlap
//                          matrix.
    void build_matrices(array &type,
                        array &x,
                        array &y,
                        array &z,
                        const unsigned int given_theory_level = 1);
//
//  get_overlap_integral():
    double get_overlap_integral(const unsigned int &i_atom,
                                const unsigned int &j_atom,
                                array &type,
                                array &x,
                                array &y,
                                array &z,
                                const unsigned int &theory_level);
//
//  get_kinetic_integral():
    double get_kinetic_integral(const unsigned int &i_atom,
                                const unsigned int &j_atom,
                                array &type,
                                array &x,
                                array &y,
                                array &z,
                                const unsigned int &theory_level);
//
//
    double gf_norm(const double &alpha,
                   const unsigned int &x,
                   const unsigned int &y,
                   const unsigned int &z);
//
//  Including the inline/template/private member functions:
    #include "lcao_wavefunction__gf_product_const.cpp"
    #include "lcao_wavefunction__error_function.cpp"
    #include "lcao_wavefunction__interatomic_distance.cpp"
    #include "lcao_wavefunction__gf_midpoint.cpp"
    #include "lcao_wavefunction__gf_overlaping.cpp"
    #include "lcao_wavefunction__init_matrices.cpp"
    #include "lcao_wavefunction__gf_product.cpp"
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
    lcao_wavefunction(array &type,
                      array &x, 
                      array &y, 
                      array &z, 
                      const unsigned int given_theory_level = DEFAULT_TASK_NUMBER);
//
//  build_hamiltonian_matrix(): To calculate the Core-Hamiltonian, H, matrix.
    void build_hamiltonian_matrix(array &h_matrix,
                                  array &type,
                                  array &x,
                                  array &y,
                                  array &z,
                                  const unsigned int given_theory_level = 1);

//
//  build_overlap_matrix(): To calculate the overlaping integral, S, and to build the overlap
//                          matrix.
    void build_overlap_matrix(array &s_matrix,
                              array &type,
                              array &x,
                              array &y,
                              array &z,
                              const unsigned int given_theory_level = 1);
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
    #include "lcao_wavefunction__get_density_matrix.cpp"
    #include "lcao_wavefunction__get_fock_matrix.cpp"
    #include "lcao_wavefunction__get_wavefunction.cpp"
    #include "lcao_wavefunction__start_scf_iterations.cpp"
    #include "lcao_wavefunction__scf_ready.cpp"
    #include "lcao_wavefunction__energy.cpp"
//
double get_overlap_integral(const unsigned int &i_atom,  // The i-th atom.
                                               const unsigned int &j_atom,  // The j-th atom.
                                               const unsigned int &i_shell, // The i-th atomic shell.
                                               const unsigned int &j_shell, // The j-th atomic shell.
                                               const double &i_exponent,    // The i-th gf exponent.
                                               const double &j_exponent,    // The j-th gf exponent.
                                               array &position);             // The atomic positions onto one axis.

};
#endif
