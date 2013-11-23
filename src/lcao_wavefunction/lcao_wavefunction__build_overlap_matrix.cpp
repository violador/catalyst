#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_overlap_matrix(array &s_matrix,                // The overlap matrix, S, to be built.
                                             array &type,                    // The atom types array.
                                             array &x,                       // The atom x-axis positions.
                                             array &y,                       // The atom y-axis positions.
                                             array &z,                       // The atom z-axis positions.
                                             const unsigned int given_level) // The basis set type. 
{
    unsigned int i = 1, j = 1, total_orbitals = count_orbitals(type);
    switch(s_matrix.array::check_if(IS_CONSTANT))
    {
        case false:
        {
            check_matrix_size(s_matrix, total_orbitals);
            s_matrix.array::set_name("Overlap matrix");
        }
        break;
        case true:
        {
            return;
        }
        break;
    }
    overlap_matrix_ready = false;
    overlap_timing.timer::start();
//
    for(unsigned int i_atom = 1; 
        i_atom <= type.array::size_of_row(); 
        ++i_atom)
    {
        for(unsigned int j_atom = i_atom; 
            j_atom <= type.array::size_of_row(); 
            ++j_atom)
        {
            periodic_table get;
            for(unsigned int i_orbital = 1; 
                i_orbital <= get.periodic_table::orbitals_number(type(i_atom)); 
                ++i_orbital)  
            {
                unsigned int j_orbital = 0;
                for(i_atom == j_atom? j_orbital = i_orbital + 1 : j_orbital = 1; 
                    j_orbital <= get.periodic_table::orbitals_number(type(j_atom)); 
                    ++j_orbital)  
                {
                    ++j;
                    s_matrix(i, 
                             j, 
                             cgf_overlap_integral(type,
                                                  x,
                                                  y,
                                                  z,
                                                  i_atom,
                                                  j_atom,
                                                  i_orbital,
                                                  j_orbital,
                                                  given_level));
                    s_matrix(j, 
                             i, 
                             s_matrix(i, j));
                    global_log::file.write_debug_msg("lcao_wavefunction::build_overlap_matrix(): S(atom ",
                                                     i_atom,
                                                     ", orbital ",
                                                     i_orbital,
                                                     "/",
                                                     get.periodic_table::orbitals_number(type(i_atom)),
                                                     "; atom ",
                                                     j_atom,
                                                     ", orbital ",
                                                     j_orbital,
                                                     "/",
                                                     get.periodic_table::orbitals_number(type(j_atom)),
                                                     "; ",
                                                     i,
                                                     ", ",
                                                     j,
                                                     ") = ",
                                                     s_matrix(i, j));
                }
                switch(j == total_orbitals)
                {
                    case true:
                    ++i;
                    j = i;
                    break;
                }
            }
        }
    }
    s_matrix.array::set_diagonal(1.0);
//
    overlap_timing.timer::stop();
    overlap_matrix_ready = true;
    switch(config -> state_of(DEBUG_MODE))
    {
         case false: break;
         case  true: s_matrix.array::write(); break;
    }
} 
