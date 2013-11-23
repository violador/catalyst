#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_kinetic_matrix(array &t_matrix,          // The kinetic matrix, T, to be built.
                                             array &type,              // The atom types array.
                                             array &x,                 // The atom x-axis positions.
                                             array &y,                 // The atom y-axis positions.
                                             array &z,                 // The atom z-axis positions.
                                             unsigned int given_level) // The basis set type.
{
//
    unsigned int i = 1, j = i, total_orbitals = count_orbitals(type);
    switch(t_matrix.array::check_if(IS_CONSTANT))
    {
        case false:
        {
            check_matrix_size(t_matrix, total_orbitals); 
            t_matrix.array::set_name("Kinetic matrix");
        }
        break;
        case true:
        {
            return;
        }
        break;
    }
    kinetic_matrix_ready = false;
    kinetic_timing.timer::start();
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
                for(i_atom == j_atom? j_orbital = i_orbital : j_orbital = 1;
                    j_orbital <= get.periodic_table::orbitals_number(type(j_atom));
                    ++j_orbital)
                {
                    t_matrix(i,
                             j,
                             cgf_kinetic_integral(type,
                                                  x,
                                                  y,
                                                  z,
                                                  i_atom,
                                                  j_atom,
                                                  i_orbital,
                                                  j_orbital,
                                                  given_level));
                    t_matrix(j,
                             i,
                             t_matrix(i, j));
                    global_log::file.write_debug_msg("lcao_wavefunction::build_overlap_matrix(): T(atom ",
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
                                                     t_matrix(i, j));
                    ++j;
                }
                switch(j > total_orbitals)
                {
                    case true:
                    ++i;
                    j = i;
                    break;
                }
            }
        }
    }
//
    kinetic_timing.timer::stop();
    kinetic_matrix_ready = true;
    switch(config -> state_of(DEBUG_MODE))
    {
         case false: break;
         case  true: t_matrix.array::write(); break;
    }
}
