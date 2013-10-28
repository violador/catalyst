#include "lcao_wavefunction.hpp"
//
//
//
lcao_wavefunction::lcao_wavefunction()
{
    config = &global_settings::config;
    overlap_matrix_ready = false;
    hamiltonian_matrix_ready = false;
    kinetic_matrix_ready = false;
    repulsion_matrix1_ready = false;
    repulsion_matrix2_ready = false;
}
//
//
//
lcao_wavefunction::lcao_wavefunction(array &type,
                                     array &x,
                                     array &y,
                                     array &z,
                                     const unsigned int given_theory_level)
{
    config = &global_settings::config;
    overlap_matrix_ready = false;
    hamiltonian_matrix_ready = false;
    kinetic_matrix_ready = false;
    repulsion_matrix1_ready = false;
    repulsion_matrix2_ready = false;
    current_level = given_theory_level;
    build_matrices(type,
                   x,
                   y,
                   z,
                   given_theory_level);
}
