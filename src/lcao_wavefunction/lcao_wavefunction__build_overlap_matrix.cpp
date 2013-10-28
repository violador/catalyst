#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_overlap_matrix(array &s_matrix,           // The overlap matrix, S, to be built.
                                             array &type,               // The atom types array.
                                             array &x,                  // The atom x-axis positions.
                                             array &y,                  // The atom y-axis positions.
                                             array &z,                  // The atom z-axis positions.
                                             unsigned int theory_level) // The requested level of theory, i.e. the basis set type. 
{
//
    switch(s_matrix.array::check_if(IS_CONSTANT))
    {
        case false:
        {
            check_matrix_size(s_matrix, type.array::size_of_row());
            s_matrix.array::set_all(1.0);
        }
        break;
        case true:
        {
            return;
        }
        break;
    }
    global_log::file.write_debug_msg("lcao_wavefunction::build_overlap_matrix()");
    double s_integral = 0.0;
    overlap_matrix_ready = false;
//
    unsigned int i_atom = 0;
    #pragma omp parallel for private(i_atom) reduction(+:s_integral) ordered schedule(dynamic)
    for(i_atom = 1; i_atom <= type.array::size_of_row(); i_atom++)  
    {  
        unsigned int j_atom = 0;
        #pragma omp parallel for private(j_atom) reduction(+:s_integral) ordered schedule(dynamic)
        for(j_atom = i_atom; j_atom <= type.array::size_of_row(); j_atom++)
        {
            switch(i_atom not_eq j_atom)
            {
                case true:
                periodic_table i_basis_set(theory_level, type(i_atom));
                periodic_table j_basis_set(theory_level, type(j_atom)); 
                double ij_distance = interatomic_distance(x(i_atom),
                                                          y(i_atom),
                                                          z(i_atom),
                                                          x(j_atom),
                                                          y(j_atom),
                                                          z(j_atom));
                unsigned int m_primitive = 0;
                #pragma omp parallel for private(m_primitive) reduction(+:s_integral) ordered schedule(dynamic)
                for(m_primitive = 1; m_primitive <= i_basis_set.periodic_table::basis_size(); m_primitive++)
                {
                    unsigned int n_primitive = 0;
                    #pragma omp parallel for private(n_primitive) reduction(+:s_integral) ordered schedule(dynamic)
                    for(n_primitive = 1; n_primitive <= j_basis_set.periodic_table::basis_size(); n_primitive++)
                    {
                        double a = 0.0, b = 0.0;
                        #pragma omp parallel sections num_threads(2)
                        {
                            #pragma omp section
                            {
                                a = i_basis_set(BASIS_COEFFICIENT, m_primitive)*j_basis_set(BASIS_COEFFICIENT, n_primitive);
                            }
                            #pragma omp section
                            {
                                b = gf_overlaping(i_basis_set(BASIS_EXPONENT, m_primitive), 
                                                  j_basis_set(BASIS_EXPONENT, n_primitive), 
                                                  ij_distance);
                            }
                        }
//
//                      A. Szabo and N. Ostlund; 
//                      Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//                      Appendix A; 
//                      pag. 412; 
//                      equation (A.9):
                        #pragma omp atomic
                        s_integral += a*b;
//
                    } // for(n_primitive)
                } // for(m_primitive)
                s_matrix(i_atom, j_atom, s_integral);
                s_matrix(j_atom, i_atom, s_integral);
                s_integral = 0.0;
                break;
            }
        } // for(j_atom) 
    } // for(i_atom)
    overlap_matrix_ready = true;
} 
