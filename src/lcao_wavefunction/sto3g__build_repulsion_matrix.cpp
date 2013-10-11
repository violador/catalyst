#include "sto3g.hpp"
//
//
//
void lcao_wavefunction::sto3g::build_repulsion_matrix()
{
//
    v_matrix.create_array(number_of_atoms, number_of_atoms);
    v_matrix.array::set_config(*config);
    v_matrix.set_name("One electron Coulomb repulsion matrix");
//
    double ii_integral = 0.0;
    double ij_integral = 0.0;
    double jj_integral = 0.0; 
    double i_distance  = 0.0; 
    double j_distance  = 0.0;
    double ij_distance = 0.0;
    double i_atomic_num = 0.0;
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;
    double e = 0.0;
    double f = 0.0; 
    unsigned int i_atom = 0;
    unsigned int i_type = 0;
    #pragma omp parallel for private(i_atom, i_type, i_atomic_num, ij_distance, i_distance, a, b, c, d, e, f) reduction(+:ii_integral, ij_integral, jj_integral) ordered schedule(dynamic)
    for(i_atom = 1; i_atom <= number_of_atoms; i_atom++)
    {
        i_type = (type -> get(i_atom));
        i_atomic_num = ((double) i_type);
        unsigned int j_atom = 0;
        unsigned int j_type = 0;
        #pragma omp parallel for private(j_atom, j_type, ij_distance, j_distance, a, b, c, d, e, f) reduction(+:ii_integral, ij_integral, jj_integral) ordered schedule(dynamic)
        for(j_atom = 1; j_atom <= number_of_atoms; j_atom++)
        {
            j_type = (type -> get(j_atom));
            if(i_atom == j_atom)
            {
                unsigned int m_primitive = 0;
                #pragma omp parallel for private(m_primitive, a, b, c, d, e, f) reduction(+:ii_integral, ij_integral, jj_integral) ordered schedule(dynamic)
                for(m_primitive = 1; m_primitive <= (i_type == 1? 3:6); m_primitive++)
                {
                    unsigned int n_primitive = 0;
                    #pragma omp parallel for private(n_primitive, a, b, c, d, e, f) reduction(+:ii_integral, ij_integral, jj_integral) ordered schedule(dynamic)
                    for(n_primitive = 1; n_primitive <= (i_type == 1? 3:6); n_primitive++)
                    {
                        #pragma omp parallel sections num_threads(4)
                        {
                            #pragma omp section
                            {
                                a = coeff(i_type, m_primitive)*coeff(i_type, n_primitive);
                            }
                            #pragma omp section
                            {
                                b = -2.0*M_PI/(exp(i_type, m_primitive) + exp(i_type, n_primitive));
                            }
                            #pragma omp section
                            {
                                c = gf_product_const(exp(i_type, m_primitive), exp(i_type, n_primitive), 0.0);
                            }
                            #pragma omp section
                            {
                                d = error_function(0.0);
                            }
                        }
//
                        #pragma omp atomic
                        ii_integral += a*b*c*d*i_atomic_num;
//
                        a = b = c = d = 0.0;
                    } // for(n_primitive)
                } // for(m_primitive)
                v_matrix.set(i_atom, j_atom, v_matrix.get(i_atom, j_atom) + ii_integral);
                ii_integral = 0.0;
            }
            else // if(i_atom != j_atom)
            {
                ij_distance = interatomic_distance(i_atom, j_atom);
                for(unsigned int m_primitive = 1; m_primitive <= (i_type == 1? 3:6); m_primitive++)
                {
                    for(unsigned int n_primitive = 1; n_primitive <= (i_type == 1? 3:6); n_primitive++)
                    {
                        gf_midpoint(i_distance,
                                    j_distance,
                                    exp(i_type, m_primitive),
                                    exp(j_type, n_primitive),
                                    ij_distance);
                        a =  gsl_pow_2(i_distance)*(exp(i_type, m_primitive) + exp(j_type, n_primitive));
                        b =  gsl_pow_2(ij_distance)*(exp(j_type, m_primitive) + exp(j_type, n_primitive));
                        #pragma omp parallel sections num_threads(4)
                        {
                            #pragma omp section
                            {
                                c = coeff(i_type, m_primitive)*coeff(j_type, n_primitive);
                            }
                            #pragma omp section
                            {
                                d = -2.0*M_PI/(exp(i_type, m_primitive) + exp(j_type, n_primitive));
                            }
                            #pragma omp section
                            {
                                e = gf_product_const(exp(i_type, m_primitive), exp(j_type, n_primitive), ij_distance);
                            }
                            #pragma omp section
                            {
                                f = error_function(a);
                            }
                        }
//
                        #pragma omp atomic
                        ij_integral += c*d*e*f*i_atomic_num;
//
                        c = d = e = f = 0.0;
                        #pragma omp parallel sections num_threads(4)
                        {
                            #pragma omp section
                            {
                                c = coeff(j_type, m_primitive)*coeff(j_type, n_primitive);
                            }
                            #pragma omp section
                            {
                                d = -2.0*M_PI/(exp(j_type, m_primitive) + exp(j_type, n_primitive));
                            }
                            #pragma omp section
                            {
                                e = gf_product_const(exp(j_type, m_primitive), exp(j_type, n_primitive), 0.0);
                            }
                            #pragma omp section
                            {
                                f = error_function(b);
                            }
                        }
//
                        #pragma omp atomic
                        jj_integral += c*d*e*f*i_atomic_num;
//
                        a = b = c = d = e = f = 0.0;
                    } // for(n_primitive)
                } // for(m_primitive)
                v_matrix.set(i_atom, j_atom, v_matrix.get(i_atom, j_atom) + ij_integral);
                v_matrix.set(j_atom, i_atom, v_matrix.get(i_atom, j_atom));
                v_matrix.set(j_atom, j_atom, v_matrix.get(j_atom, j_atom) + jj_integral);
                ij_integral = jj_integral = i_distance = j_distance = ij_distance = 0.0;
            }
        } // for(j_atom)
    } // for(i_atom)
}
