#include "lcao_wavefunction.hpp"
//
//
//
void lcao_wavefunction::build_repulsion_matrix_1(array &v_matrix,           // The repulsion matrix, V, to be built.
                                                 array &type,               // The atom types array.
                                                 array &x,                  // The atom x-axis positions.
                                                 array &y,                  // The atom y-axis positions.
                                                 array &z,                  // The atom z-axis positions.
                                                 unsigned int theory_level) // The basis set type.

{
//
    switch(v_matrix.array::check_if(IS_CONSTANT))
    {
        case false: 
        check_matrix_size(v_matrix, type.array::size_of_row()); 
        v_matrix.array::set_name("One electron repulsion matrix");
        break;
    }
    global_log::file.write_debug_msg("lcao_wavefunction::build_repulsion_matrix_1()");
    double ii_integral = 0.0;
    double ij_integral = 0.0;
    double jj_integral = 0.0; 
    repulsion_matrix1_ready = false;
//
    unsigned int i_atom = 0;
    #pragma omp parallel for private(i_atom) reduction(+:ii_integral, ij_integral, jj_integral) ordered schedule(dynamic)
    for(i_atom = 1; i_atom <= type.array::size_of_row(); i_atom++)
    {
        double i_atomic_number = (double) type(i_atom);
        unsigned int j_atom = 0;
        #pragma omp parallel for private(j_atom) reduction(+:ii_integral, ij_integral, jj_integral) ordered schedule(dynamic)
        for(j_atom = 1; j_atom <= type.array::size_of_row(); j_atom++)
        {
            switch(i_atom == j_atom)
            {
                case true:
                periodic_table i_basis_set(theory_level, type(i_atom));
                unsigned int m_primitive = 0;
                #pragma omp parallel for private(m_primitive) reduction(+:ii_integral) ordered schedule(dynamic)
                for(m_primitive = 1; m_primitive <= i_basis_set.periodic_table::basis_size(); m_primitive++)
                {
                    unsigned int n_primitive = 0;
                    #pragma omp parallel for private(n_primitive) reduction(+:ii_integral) ordered schedule(dynamic)
                    for(n_primitive = 1; n_primitive <= i_basis_set.periodic_table::basis_size(); n_primitive++)
                    {
                        double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
                        #pragma omp parallel sections num_threads(4)
                        {
                            #pragma omp section
                            {
                                a = i_basis_set(BASIS_COEFFICIENT, m_primitive)*i_basis_set(BASIS_COEFFICIENT, n_primitive);
                            }
                            #pragma omp section
                            {
                                b = -2.0*M_PI/(i_basis_set(BASIS_EXPONENT, m_primitive) + i_basis_set(BASIS_EXPONENT, n_primitive));
                            }
                            #pragma omp section
                            {
                                c = gf_product_const(i_basis_set(BASIS_EXPONENT, m_primitive), 
                                                     i_basis_set(BASIS_EXPONENT, n_primitive), 
                                                     0.0);
                            }
                            #pragma omp section
                            {
                                d = error_function(0.0);
                            }
                        }
//
//                      A. Szabo and N. Ostlund;
//                      Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//                      Appendix A; 
//                      pag. 412; 
//                      equation (A.33):
                        #pragma omp atomic
                        ii_integral += a*b*c*d*i_atomic_number;
//
                    } // for(n_primitive)
                } // for(m_primitive)
                v_matrix(i_atom, j_atom, v_matrix(i_atom, j_atom) + ii_integral);
                ii_integral = 0.0;
                break;
            }
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
                #pragma omp parallel for private(m_primitive) reduction(+:ij_integral, jj_integral) ordered schedule(dynamic)
                for(m_primitive = 1; m_primitive <= i_basis_set.periodic_table::basis_size(); m_primitive++)
                {
                    unsigned int n_primitive = 0;
                    #pragma omp parallel for private(n_primitive) reduction(+:ii_integral, jj_integral) ordered schedule(dynamic)
                    for(n_primitive = 1; n_primitive <= j_basis_set.periodic_table::basis_size(); n_primitive++)
                    {
                        double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0, i_distance = 0.0, j_distance = 0.0;
//
                        gf_midpoint(i_distance,
                                    j_distance,
                                    i_basis_set(BASIS_EXPONENT, m_primitive),
                                    j_basis_set(BASIS_EXPONENT, n_primitive),
                                    ij_distance);
//
                        a = gsl_pow_2(i_distance)
                            *(i_basis_set(BASIS_EXPONENT, m_primitive) + j_basis_set(BASIS_EXPONENT, n_primitive));
//
                        b = gsl_pow_2(ij_distance)
                            *(j_basis_set(BASIS_EXPONENT, m_primitive) + j_basis_set(BASIS_EXPONENT, n_primitive));
//
                        #pragma omp parallel sections num_threads(4)
                        {
                            #pragma omp section
                            {
                                c = i_basis_set(BASIS_COEFFICIENT, m_primitive)*j_basis_set(BASIS_COEFFICIENT, n_primitive);
                            }
                            #pragma omp section
                            {
                                d = -2.0*M_PI/(i_basis_set(BASIS_EXPONENT, m_primitive) + j_basis_set(BASIS_EXPONENT, n_primitive));
                            }
                            #pragma omp section
                            {
                                e = gf_product_const(i_basis_set(BASIS_EXPONENT, m_primitive),
                                                     j_basis_set(BASIS_EXPONENT, n_primitive), 
                                                     ij_distance);
                            }
                            #pragma omp section
                            {
                                f = error_function(a);
                            }
                        }
//
//                      A. Szabo and N. Ostlund;
//                      Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//                      Appendix A; 
//                      pag. 412; 
//                      equation (A.33):
                        #pragma omp atomic
                        ij_integral += c*d*e*f*i_atomic_number;
//
                        c = d = e = f = 0.0;
                        #pragma omp parallel sections num_threads(4)
                        {
                            #pragma omp section
                            {
                                c = j_basis_set(BASIS_COEFFICIENT, m_primitive)*j_basis_set(BASIS_COEFFICIENT, n_primitive);
                            }
                            #pragma omp section
                            {
                                d = -2.0*M_PI/(j_basis_set(BASIS_EXPONENT, m_primitive) + j_basis_set(BASIS_EXPONENT, n_primitive));
                            }
                            #pragma omp section
                            {
                                e = gf_product_const(j_basis_set(BASIS_EXPONENT, m_primitive),
                                                     j_basis_set(BASIS_EXPONENT, n_primitive), 
                                                     0.0);
                            }
                            #pragma omp section
                            {
                                f = error_function(b);
                            }
                        }
//
//                      A. Szabo and N. Ostlund;
//                      Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//                      Appendix A; 
//                      pag. 412; 
//                      equation (A.33):
                        #pragma omp atomic
                        jj_integral += c*d*e*f*i_atomic_number;
//
                    } // for(n_primitive)
                } // for(m_primitive)
                v_matrix(i_atom, j_atom, v_matrix(i_atom, j_atom) + ij_integral);
                v_matrix(j_atom, i_atom, v_matrix(i_atom, j_atom));
                v_matrix(j_atom, j_atom, v_matrix(j_atom, j_atom) + jj_integral);
                ij_integral = jj_integral = 0.0;
                break;
            }
        } // for(j_atom)
    } // for(i_atom)
    repulsion_matrix1_ready = true;
    switch(config -> state_of(DEBUG_MODE))
    {
         case false: break;
         case  true: v_matrix.array::write(); break;
    }
}
