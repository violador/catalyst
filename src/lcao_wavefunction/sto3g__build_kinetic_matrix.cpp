#include "sto3g.hpp"
//
//
//
void lcao_wavefunction::sto3g::build_kinetic_matrix()
{
//
    t_matrix.array::create_array(number_of_atoms, number_of_atoms);
    t_matrix.array::set_config(*config);
    t_matrix.array::set_name("Kinetic energy matrix");
//
    double t_integral = 0.0, ij_distance = 0.0, a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0;
    unsigned int i_type = 0, i_atom = 0;
    #pragma omp parallel for private(i_atom, i_type, ij_distance, a, b, c, d, e, f) reduction(+:t_integral) ordered schedule(dynamic)
    for(i_atom = 1; i_atom <= number_of_atoms; i_atom++)
    {
        i_type = type -> get(i_atom);
        unsigned int j_atom = 0, j_type = 0;
        #pragma omp parallel for private(j_atom, j_type, ij_distance, a, b, c, d, e, f) reduction(+:t_integral) ordered schedule(dynamic)
        for(j_atom = i_atom; j_atom <= number_of_atoms; j_atom++)
        {
            j_type = type -> get(j_atom);
            ij_distance = (i_atom == j_atom? 0.0 : interatomic_distance(i_atom, j_atom));
            unsigned int m_primitive = 0;
            #pragma omp parallel for private(m_primitive, a, b, c, d, e, f) reduction(+:t_integral) ordered schedule(dynamic)
            for(m_primitive = 1; m_primitive <= (i_type == 1? 3:6); m_primitive++)
            {
                unsigned int n_primitive = 0;
                #pragma omp parallel for private(n_primitive, a, b, c, d, e, f) reduction(+:t_integral) ordered schedule(dynamic)
                for(n_primitive = 1; n_primitive <= (i_type == 1? 3:6); n_primitive++)
                {
                    a = exp(i_type, m_primitive) + exp(j_type, n_primitive);
                    #pragma omp parallel sections num_threads(5)
                    {
                        #pragma omp section
                        {
                            b = coeff(i_type, m_primitive)*coeff(j_type, n_primitive);
                        }
                        #pragma omp section
                        {
                            c = exp(i_type, m_primitive)*exp(j_type, n_primitive)/a;
                        }
                        #pragma omp section
                        {
                            d = 3.0 - 2.0*exp(i_type, m_primitive)*exp(j_type, n_primitive)*gsl_pow_2(ij_distance)/a;
                        }
                        #pragma omp section
                        {
                            e = pow(M_PI/a, 1.5);
                        }
                        #pragma omp section
                        {
                            f = gf_product_const(exp(i_type, m_primitive), exp(j_type, n_primitive), ij_distance);
                        }
                    }
//
//                  A. Szabo and N. Ostlund;
//                  Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//                  Appendix A; 
//                  pag. 412; 
//                  equation (A.11):
                    #pragma omp atomic
                    t_integral += b*c*d*e*f;
//
                    a = b = c = d = e = f = 0.0;
                } // for(n_primitive)
            } // for(m_primitive)
            t_matrix.array::set(i_atom, j_atom, t_integral);
            t_matrix.array::set(j_atom, i_atom, t_integral);
            t_integral = ij_distance = 0.0;
        } // for(j_atom)
    } // for(i_atom)
}
