#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::get_kinetic_integral(const unsigned int &i_atom,             // The ith-atom.
                                               const unsigned int &j_atom,             // The jth-atom.
                                               array &type,                            // The atom types array.
                                               array &x,                               // The atom x-axis positions.
                                               array &y,                               // The atom y-axis positions.
                                               array &z,                               // The atom z-axis positions.
                                               const unsigned int &given_theory_level) // The basis set type.
{
    periodic_table i_basis_set(given_theory_level, type(i_atom));
    periodic_table j_basis_set(given_theory_level, type(j_atom));
    double ij_distance = interatomic_distance(x(i_atom),
                                              y(i_atom),
                                              z(i_atom),
                                              x(j_atom),
                                              y(j_atom),
                                              z(j_atom));
    double t_integral = 0.0;
    unsigned int m_primitive = 0;
    #pragma omp parallel for private(m_primitive) reduction(+:t_integral) ordered schedule(dynamic)
    for(m_primitive = 1; m_primitive <= i_basis_set.periodic_table::basis_size(); m_primitive++)
    {
        unsigned int n_primitive = 0;
        #pragma omp parallel for private(n_primitive) reduction(+:t_integral) ordered schedule(dynamic)
        for(n_primitive = 1; n_primitive <= j_basis_set.periodic_table::basis_size(); n_primitive++)
        {
            double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0;
            a = i_basis_set(BASIS_EXPONENT, m_primitive) + j_basis_set(BASIS_EXPONENT, n_primitive);
            #pragma omp parallel sections num_threads(5)
            {
                #pragma omp section
                {
                    b = i_basis_set(BASIS_COEFFICIENT, m_primitive)*j_basis_set(BASIS_COEFFICIENT, n_primitive);
                }
                #pragma omp section
                {
                    c = i_basis_set(BASIS_EXPONENT, m_primitive)*j_basis_set(BASIS_EXPONENT, n_primitive)/a;
                }
                #pragma omp section
                {
                    d = 3.0 - 2.0*i_basis_set(BASIS_EXPONENT, m_primitive)
                                 *j_basis_set(BASIS_EXPONENT, n_primitive)
                                 *gsl_pow_2(ij_distance)/a;
                }
                #pragma omp section
                {
                    e = std::pow(M_PI/a, 1.5);
                }
                #pragma omp section
                {
                    f = gf_product_const(i_basis_set(BASIS_EXPONENT, m_primitive),
                                         j_basis_set(BASIS_EXPONENT, n_primitive),
                                         ij_distance);
                }
            }
//
//          A. Szabo and N. Ostlund;
//          Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//          Appendix A; 
//          pag. 412; 
//          equation (A.11):
            #pragma omp atomic
            t_integral += b*c*d*e*f;
//
        } // for(n_primitive)
    } // for(m_primitive)
    return t_integral;
}
