#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_overlap_matrix(array &s_matrix,                       // The overlap matrix, S, to be built.
                                             array &type,                           // The atom types array.
                                             array &x,                              // The atom x-axis positions.
                                             array &y,                              // The atom y-axis positions.
                                             array &z,                              // The atom z-axis positions.
                                             const unsigned int given_theory_level) // The basis set type. 
{
    switch(s_matrix.array::check_if(IS_CONSTANT))
    {
        case false:
        {
            check_matrix_size(s_matrix, type.array::size_of_row());
            s_matrix.array::set_all(1.0);
            s_matrix.array::set_name("Overlap matrix");
        }
        break;
        case true:
        {
            return;
        }
        break;
    }
    global_log::file.write_debug_msg("lcao_wavefunction::build_overlap_matrix()");
    overlap_matrix_ready = false;
//
    unsigned int i_atom = 0;
    #pragma omp parallel for private(i_atom) ordered schedule(dynamic)
    for(i_atom = 1; i_atom <= type.array::size_of_row() - 1; i_atom++)  
    {  
        unsigned int j_atom = 0;
        #pragma omp parallel for private(j_atom) ordered schedule(dynamic)
        for(j_atom = i_atom + 1; j_atom <= type.array::size_of_row(); j_atom++)
        {
            s_matrix(i_atom, 
                     j_atom, 
                     get_overlap_integral(i_atom,
                                          j_atom,
                                          type,
                                          x,
                                          y,
                                          z,
                                          given_theory_level));
            s_matrix(j_atom, 
                     i_atom, 
                     s_matrix(i_atom, j_atom));
        }
    }
//
    overlap_matrix_ready = true;
    switch(config -> state_of(DEBUG_MODE))
    {
         case false: break;
         case  true: s_matrix.array::write(); break;
    }
} 
