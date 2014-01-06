#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_repulsion_matrix_2(array &v_matrix,           // The overlap matrix, S, to be built.
                                                 array &type,               // The atom types array.
                                                 array &x,                  // The atom x-axis positions.
                                                 array &y,                  // The atom y-axis positions.
                                                 array &z,                  // The atom z-axis positions.
                                                 unsigned int theory_level) // The requested level of theory, i.e. the basis set type. 
{
//
/*
    switch(v_matrix.array::check_if(IS_CONSTANT))
    {
        case false: 
        check_matrix_size(v_matrix, type.array::size_of_row()); 
        v_matrix.array::set_name("Two electron repulsion matrix");
        break;
    }
    global_log::file.write_debug_msg("lcao_wavefunction::build_repulsion_matrix_2()");
    double v_integral  = 0.0; 
    repulsion_matrix2_ready = false;
//
    unsigned int i_atom = 0;
    #pragma omp parallel for private(i_atom) reduction(+:v_integral) ordered schedule(dynamic)
    for(i_atom = 1; i_atom <= type.array::size_of_row(); i_atom++)
    {
        unsigned int j_atom = 0;
        #pragma omp parallel for private(j_atom) reduction(+:v_integral) ordered schedule(dynamic)
        for(j_atom = 1; j_atom <= type.array::size_of_row(); j_atom++)
        {
            unsigned int p_atom = 0;
            #pragma omp parallel for private(p_atom) reduction(+:v_integral) ordered schedule(dynamic)
            for(p_atom = 1; p_atom <= type.array::size_of_row(); p_atom++)
            {
                unsigned int q_atom = 0;
                #pragma omp parallel for private(q_atom) reduction(+:v_integral) ordered schedule(dynamic)
                for(q_atom = 1; q_atom <= type.array::size_of_row(); q_atom++)
                {
                    double ij_distance = 0, pq_distance = 0;
//
                    #pragma omp parallel sections num_threads(2)
                    {
                        #pragma omp section
                        {
                            ij_distance = interatomic_distance(x(i_atom),
                                                               y(i_atom),
                                                               z(i_atom),
                                                               x(j_atom),
                                                               y(j_atom),
                                                               z(j_atom));
                        }
                        #pragma omp section
                        {
                            pq_distance = interatomic_distance(x(p_atom),
                                                               y(p_atom),
                                                               z(p_atom),
                                                               x(q_atom),
                                                               y(q_atom),
                                                               z(q_atom));
                        }
                    }
//
                    periodic_table i_basis_set(theory_level, type(i_atom));
                    periodic_table j_basis_set(theory_level, type(j_atom));
                    periodic_table p_basis_set(theory_level, type(p_atom));
                    periodic_table q_basis_set(theory_level, type(q_atom));
                    unsigned int m_primitive = 0;
                    #pragma omp parallel for private(m_primitive) reduction(+:v_integral) ordered schedule(dynamic)
                    for(m_primitive = 1; m_primitive <= i_basis_set.periodic_table::basis_size(); m_primitive++)
                    {
                        unsigned int n_primitive = 0;
                        #pragma omp parallel for private(n_primitive) reduction(+:v_integral) ordered schedule(dynamic)
                        for(n_primitive = 1; n_primitive <= j_basis_set.periodic_table::basis_size(); n_primitive++)
                        {
                            unsigned int k_primitive = 0;
                            #pragma omp parallel for private(k_primitive) reduction(+:v_integral) ordered schedule(dynamic)
                            for(k_primitive = 1; k_primitive <= p_basis_set.periodic_table::basis_size(); k_primitive++)
                            {
                                unsigned int l_primitive = 0;
                                #pragma omp parallel for private(l_primitive) reduction(+:v_integral) ordered schedule(dynamic)
                                for(l_primitive = 1; l_primitive <= q_basis_set.periodic_table::basis_size(); l_primitive++)
                                {
//
                                    double i_distance = 0.0, j_distance = 0.0, p_distance = 0.0, q_distance = 0.0;
//
                                    #pragma omp parallel sections num_threads(2)
                                    {
                                        #pragma omp section
                                        {
                                            gf_midpoint(i_distance,
                                                        j_distance,
                                                        i_basis_set(BASIS_EXPONENT, m_primitive),
                                                        j_basis_set(BASIS_EXPONENT, n_primitive),
                                                        ij_distance);
                                        }
                                        #pragma omp section
                                        {
                                            gf_midpoint(p_distance,
                                                        q_distance,
                                                        p_basis_set(BASIS_EXPONENT, k_primitive),
                                                        q_basis_set(BASIS_EXPONENT, l_primitive),
                                                        pq_distance);
                                        }
                                    }
//
                                    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0;
//
                                    #pragma omp parallel sections num_threads(3)
                                    {
                                        #pragma omp section
                                        {
                                            a =  i_basis_set(BASIS_COEFFICIENT, m_primitive)
                                                *j_basis_set(BASIS_COEFFICIENT, n_primitive)
                                                *p_basis_set(BASIS_COEFFICIENT, k_primitive)
                                                *q_basis_set(BASIS_COEFFICIENT, l_primitive);
                                        }
                                        #pragma omp section
                                        {
                                            b = i_basis_set(BASIS_EXPONENT, m_primitive) 
                                              + j_basis_set(BASIS_EXPONENT, n_primitive);
                                        }
                                        #pragma omp section
                                        {
                                            c = p_basis_set(BASIS_EXPONENT, k_primitive) 
                                              + q_basis_set(BASIS_EXPONENT, l_primitive);
                                        }
                                    }
//
                                    #pragma omp parallel sections num_threads(3)
                                    {
                                        #pragma omp section
                                        {
                                            d = -i_basis_set(BASIS_EXPONENT, m_primitive)
                                                *j_basis_set(BASIS_EXPONENT, n_primitive)
                                                *gsl_pow_2(ij_distance)/b;
                                        }
                                        #pragma omp section
                                        {
                                            e = -p_basis_set(BASIS_EXPONENT, k_primitive)
                                                *q_basis_set(BASIS_EXPONENT, l_primitive)
                                                *gsl_pow_2(pq_distance)/c;
                                        }
                                        #pragma omp section
                                        {
                                            switch((i_atom == j_atom) 
                                                   and (p_atom == q_atom) 
                                                   and (i_atom not_eq q_atom))
                                            {
                                                case false: 
                                                {
                                                    f = i_distance - p_distance; 
                                                }
                                                break;
                                                case true: 
                                                {
                                                    f = interatomic_distance(x(i_atom),
                                                                             y(i_atom),
                                                                             z(i_atom),
                                                                             x(q_atom),
                                                                             y(q_atom),
                                                                             z(q_atom));
                                                }
                                                break;
                                            }
                                        }
                                    }
//
//                                  A. Szabo and N. Ostlund; 
//                                  Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//                                  Appendix A; 
//                                  pag. 416; 
//                                  equation (A.41):
                                    #pragma omp atomic
                                    v_integral += a*(2.0*std::pow(M_PI, 2.5)/(b*c*std::sqrt(b + c)))
                                                   *gsl_sf_exp(d + e)
                                                   *error_function(b*c*gsl_pow_2(f)/(b + c));
//
                                } // for(l_primitive)
                            } // for(k_primitive)
                        } // for(n_primitive)
                    } // for(m_primitive)
                    v_matrix(i_atom, 
                             j_atom, 
                             p_atom, 
                             q_atom, 
                             v_matrix(i_atom, j_atom, p_atom, q_atom) + v_integral);
                    v_integral = 0.0;
                } // for(q_atom)
            } // for(p_atom)
        } // for(j_atom)
    } // for(i_atom)
    repulsion_matrix2_ready = true;
*/
/*
    switch(config -> state_of(DEBUG_MODE))
    {
         case false: break;
         case  true: v_matrix.array::write(); break;
    }
*/
}
