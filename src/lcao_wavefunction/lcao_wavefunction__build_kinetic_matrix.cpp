#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_kinetic_matrix(array &t_matrix,                 // The kinetic matrix, T, to be built.
                                             array &type,                     // The atom types array.
                                             array &x,                        // The atom x-axis positions.
                                             array &y,                        // The atom y-axis positions.
                                             array &z,                        // The atom z-axis positions.
                                             unsigned int given_theory_level) // The basis set type.
{
//
    switch(t_matrix.array::check_if(IS_CONSTANT))
    {
        case false:
        {
            check_matrix_size(t_matrix, type.array::size_of_row()); 
            t_matrix.array::set_name("Kinetic matrix");
        }
        break;
        case true:
        {
            return;
        }
        break;
    }
    global_log::file.write_debug_msg("lcao_wavefunction::build_kinetic_matrix()");
    kinetic_matrix_ready = false;
//
    unsigned int i_atom = 0;
    #pragma omp parallel for private(i_atom) ordered schedule(dynamic)
    for(i_atom = 1; i_atom <= type.array::size_of_row(); i_atom++)
    {
        unsigned int j_atom = 0;
        #pragma omp parallel for private(j_atom) ordered schedule(dynamic)
        for(j_atom = i_atom; j_atom <= type.array::size_of_row(); j_atom++)
        {
            t_matrix(i_atom, 
                     j_atom,
                     get_kinetic_integral(i_atom,
                                          j_atom,
                                          type,
                                          x,
                                          y,
                                          z,
                                          given_theory_level));
            switch(i_atom not_eq j_atom)
            {
                case true:
                t_matrix(j_atom, 
                         i_atom, 
                         t_matrix(i_atom, j_atom));
                break;
            }
        }
    }
//
    kinetic_matrix_ready = true;
    switch(config -> state_of(DEBUG_MODE))
    {
         case false: break;
         case  true: t_matrix.array::write(); break;
    }
}
