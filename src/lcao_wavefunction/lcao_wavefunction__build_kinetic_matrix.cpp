#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_kinetic_matrix(array &t_matrix,    // The kinetic matrix, T, to be built.
                                             array &type,        // The atom types array.
                                             array &x,           // The atom x-axis positions.
                                             array &y,           // The atom y-axis positions.
                                             array &z,           // The atom z-axis positions.
                                             unsigned int level) // The basis set type.
{
//
    unsigned int i = 1; 
    unsigned int j = i; 
    unsigned int total_orbitals = count_orbitals(type);
    periodic_table a_data, b_data;
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
                for(unsigned int b_orbital = (atom_a == atom_b? a_orbital : 1);
                    b_orbital <= b_data.periodic_table::sub_shells();
                    ++b_orbital)
                {
                    t_matrix(i,
                             j,
                             t_matrix(i, j) + cgf_kinetic_integral(type,
                                                                   x,
                                                                   y,
                                                                   z,
                                                                   atom_a,
                                                                   atom_b,
                                                                   a_orbital,
                                                                   b_orbital,
                                                                   level));
                    t_matrix(j,
                             i,
                             t_matrix(i, j));
/*
                    global_log::file.write_debug_msg("lcao_wavefunction::build_overlap_matrix(): T(atom ",
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
                                                     t_matrix(i, j));
*/
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
    t_matrix.array::write();
}
