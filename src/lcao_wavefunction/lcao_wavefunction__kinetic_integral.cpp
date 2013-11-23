#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::kinetic_integral(array &position,                        // The atomic positions onto one axis.
                                           const unsigned int &i_atom,             // The i-th atom.
                                           const unsigned int &j_atom,             // The j-th atom.
                                           const unsigned int &i_orbital_position, // The i-th atomic orbital onto one axis.
                                           const unsigned int &j_orbital_position, // The j-th atomic orbital onto one axis.
                                           const double &i_exponent,               // The i-th gf exponent.
                                           const double &j_exponent)               // The j-th gf exponent.
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            a = i_orbital_position
              * j_orbital_position
              * overlap_integral(position,
                                 i_atom,
                                 j_atom,
                                 i_orbital_position - 1,
                                 j_orbital_position - 1,
                                 i_exponent,
                                 j_exponent);
        }
        #pragma omp section
        {
            b = 2.0
              * i_exponent
              * j_orbital_position
              * overlap_integral(position,
                                 i_atom,
                                 j_atom,
                                 i_orbital_position + 1,
                                 j_orbital_position - 1,
                                 i_exponent,
                                 j_exponent);
        }
        #pragma omp section
        {
            c = 2.0
              * i_orbital_position
              * j_exponent
              * overlap_integral(position,
                                 i_atom,
                                 j_atom,
                                 i_orbital_position - 1,
                                 j_orbital_position + 1,
                                 i_exponent,
                                 j_exponent);
        }
        #pragma omp section
        {
            d = 4.0
              * i_exponent
              * j_exponent
              * overlap_integral(position,
                                 i_atom,
                                 j_atom,
                                 i_orbital_position + 1,
                                 j_orbital_position + 1,
                                 i_exponent,
                                 j_exponent);
        }
    }
//
//  Minhhuy Hô and Julio Manuel Hernández-Pérez;
//  The Mathematica Journal;
//  Evaluation of Gaussian Molecular Integrals II - Kinetic Integrals;
//  equation (15):
    return 0.5*(a - b - c + d);
//
}
//
//
//
double lcao_wavefunction::kinetic_integral(array &type,                            // The atom types array.
                                           array &x,                               // The atom x-axis positions.
                                           array &y,                               // The atom y-axis positions.
                                           array &z,                               // The atom z-axis positions.
                                           const unsigned int &i_atom,             // The i-th atom.
                                           const unsigned int &j_atom,             // The j-th atom.
                                           const unsigned int &given_theory_level) // The basis set type.
{
    tools get;
    periodic_table i_basis_set(given_theory_level, type(i_atom));
    periodic_table j_basis_set(given_theory_level, type(j_atom));
    double t_integral = 0.0, ij_distance = get.point_distance(x(i_atom),
                                                              y(i_atom),
                                                              z(i_atom),
                                                              x(j_atom),
                                                              y(j_atom),
                                                              z(j_atom));
    unsigned int m_primitive = 0;
    #pragma omp parallel for private(m_primitive) reduction(+:t_integral) ordered schedule(dynamic)
    for(m_primitive = 1; m_primitive <= i_basis_set.periodic_table::basis_size(); ++m_primitive)
    {
        unsigned int n_primitive = 0;
        #pragma omp parallel for private(n_primitive) reduction(+:t_integral) ordered schedule(dynamic)
        for(n_primitive = 1; n_primitive <= j_basis_set.periodic_table::basis_size(); ++n_primitive)
        {
            double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0;
            a = i_basis_set(BASIS_EXPONENT, m_primitive) + j_basis_set(BASIS_EXPONENT, n_primitive);
            #pragma omp parallel sections num_threads(5)
            {
                #pragma omp section
                {
                    b = i_basis_set(BASIS_COEFFICIENT, m_primitive)
                      * j_basis_set(BASIS_COEFFICIENT, n_primitive);
                }
                #pragma omp section
                {
                    c = i_basis_set(BASIS_EXPONENT, m_primitive)
                      * j_basis_set(BASIS_EXPONENT, n_primitive)/a;
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
                    f = gf_overlap_factor(i_basis_set(BASIS_EXPONENT, m_primitive),
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
        }
    }
    return t_integral;
}
