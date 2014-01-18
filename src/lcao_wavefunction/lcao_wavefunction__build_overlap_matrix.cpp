#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_overlap_matrix(array &s_matrix,          // The overlap matrix, S, to be built.
                                             array &type,              // The atom types array.
                                             array &x,                 // The atom x-axis positions.
                                             array &y,                 // The atom y-axis positions.
                                             array &z,                 // The atom z-axis positions.
                                             const unsigned int level) // The basis set type. 
{
    unsigned int i = 1; 
    unsigned int j = i; 
    unsigned int total_orbitals = count_orbitals(type);
    periodic_table a_data, b_data;
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
    for(unsigned int atom_a = 1; 
        atom_a <= type.array::size_of_row(); 
        ++atom_a)
    {
        for(unsigned int atom_b = atom_a; 
            atom_b <= type.array::size_of_row(); 
            ++atom_b)
        {
            a_data.periodic_table::init(type(atom_a));
            b_data.periodic_table::init(type(atom_b));
            for(unsigned int a_orbital = 1; 
                a_orbital <= a_data.periodic_table::sub_shells();
                ++a_orbital)
            {
                for(unsigned int b_orbital = (atom_a == atom_b? a_orbital + 1 : 1); 
                    b_orbital <= b_data.periodic_table::sub_shells();
                    ++b_orbital)
                {
                    ++j;
                    s_matrix(i, 
                             j, 
                             cgf_overlap_integral(type,
                                                  x,
                                                  y,
                                                  z,
                                                  atom_a,
                                                  atom_b,
                                                  a_orbital,
                                                  b_orbital,
                                                  level));
                    s_matrix(j, 
                             i, 
                             s_matrix(i, j));
/*
                    global_log::file.write_debug_msg("lcao_wavefunction::build_overlap_matrix(): S(atom ",
                                                     atom_a,
                                                     ", orbital ",
                                                     a_orbital,
                                                     "/",
                                                     get.periodic_table::orbitals_number(type(atom_a)),
                                                     "; atom ",
                                                     atom_b,
                                                     ", orbital ",
                                                     b_orbital,
                                                     "/",
                                                     get.periodic_table::orbitals_number(type(atom_b)),
                                                     "; ",
                                                     i,
                                                     ", ",
                                                     j,
                                                     ") = ",
                                                     s_matrix(i, j));
*/
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
    s_matrix.array::write();
} 
