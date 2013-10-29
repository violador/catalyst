//
//
//
inline void start_scf_iterations(array &type,
                                 array &x,
                                 array &y,
                                 array &z,
                                 const unsigned int &given_theory_level)
{
    build_matrices(type,
                   x,
                   y,
                   z,
                   given_theory_level);
    iterative_routine.algorithm::scf::start_iterations(h_matrix, s_matrix, v_matrix2);
    f_matrix = iterative_routine.algorithm::scf::get_fock_matrix();
    p_matrix = iterative_routine.algorithm::scf::get_density_matrix();
    wavefunction = iterative_routine.algorithm::scf::get_wavefunction();
};
