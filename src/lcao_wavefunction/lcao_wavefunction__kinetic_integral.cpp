#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::kinetic_integral(array &r,                      // The atomic positions onto one axis.
                                           const unsigned int &atom_a,    // The atom A.
                                           const unsigned int &atom_b,    // The atom B.
                                           const unsigned int &a_orbital, // The orbital component over the atom A.
                                           const unsigned int &b_orbital, // The orbital component over the atom B.
                                           const double &alpha,           // The GF exponent at atom A.
                                           const double &beta)            // The GF exponent at atom B.
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            a = a_orbital
              * b_orbital
              * overlap_integral(r,
                                 atom_a,
                                 atom_b,
                                 a_orbital - 1,
                                 b_orbital - 1,
                                 alpha,
                                 beta);
        }
        #pragma omp section
        {
            b = 2.0
              * alpha
              * b_orbital
              * overlap_integral(r,
                                 atom_a,
                                 atom_b,
                                 a_orbital + 1,
                                 b_orbital - 1,
                                 alpha,
                                 beta);
        }
        #pragma omp section
        {
            c = 2.0
              * a_orbital
              * beta
              * overlap_integral(r,
                                 atom_a,
                                 atom_b,
                                 a_orbital - 1,
                                 b_orbital + 1,
                                 alpha,
                                 beta);
        }
        #pragma omp section
        {
            d = 4.0
              * alpha
              * beta
              * overlap_integral(r,
                                 atom_a,
                                 atom_b,
                                 a_orbital + 1,
                                 b_orbital + 1,
                                 alpha,
                                 beta);
        }
    }
//
//  Minhhuy Hô and Julio Manuel Hernández-Pérez;
//  The Mathematica Journal;
//  Evaluation of Gaussian Molecular Integrals II - Kinetic Integrals;
//  equation (15):
    return 0.5*(a - b - c + d);
}
//
//
//
double lcao_wavefunction::kinetic_integral(array &type,                // The atomic types.
                                           array &x,                   // The atomic positions onto x-axis.
                                           array &y,                   // The atomic positions onto y-axis.
                                           array &z,                   // The atomic positions onto z-axis.
                                           const unsigned int &atom_a, // The atom A.
                                           const unsigned int &atom_b, // The atom B.
                                           const unsigned int &level)  // The basis set type.
{
    periodic_table a_set(level, type(atom_a)),
                   b_set(level, type(atom_b));
    double t_integral = 0.0, 
           ab_distance = tools::point_distance(x(atom_a),
                                               y(atom_a),
                                               z(atom_a),
                                               x(atom_b),
                                               y(atom_b),
                                               z(atom_b));
    unsigned int m_primitive = 0;
    #pragma omp parallel for private(m_primitive) reduction(+:t_integral) ordered schedule(dynamic)
    for(m_primitive = 1; m_primitive <= a_set.periodic_table::basis_size(); ++m_primitive)
    {
        unsigned int n_primitive = 0;
        #pragma omp parallel for private(n_primitive) reduction(+:t_integral) ordered schedule(dynamic)
        for(n_primitive = 1; n_primitive <= b_set.periodic_table::basis_size(); ++n_primitive)
        {
            double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0;
            a = a_set(BASIS_EXPONENT, m_primitive) 
              + b_set(BASIS_EXPONENT, n_primitive);
            #pragma omp parallel sections num_threads(5)
            {
                #pragma omp section
                {
                    b = a_set(BASIS_COEFFICIENT, m_primitive)
                      * b_set(BASIS_COEFFICIENT, n_primitive);
                }
                #pragma omp section
                {
                    c = a_set(BASIS_EXPONENT, m_primitive)
                      * b_set(BASIS_EXPONENT, n_primitive)/a;
                }
                #pragma omp section
                {
                    d = 3.0 - 2.0*a_set(BASIS_EXPONENT, m_primitive)
                                 *b_set(BASIS_EXPONENT, n_primitive)
                                 *gsl_pow_2(ab_distance)/a;
                }
                #pragma omp section
                {
                    e = std::pow(M_PI/a, 1.5);
                }
                #pragma omp section
                {
                    f = gf_overlap_factor(a_set(BASIS_EXPONENT, m_primitive),
                                          b_set(BASIS_EXPONENT, n_primitive),
                                          ab_distance);
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
        }
    }
    return t_integral;
}
