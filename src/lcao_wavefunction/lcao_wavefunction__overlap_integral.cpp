#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::overlap_integral(array &position,                        // The atomic positions onto one axis.
                                           const unsigned int &i_atom,             // The i-th atom.
                                           const unsigned int &j_atom,             // The j-th atom.
                                           const unsigned int &i_orbital_position, // The i-th atomic orbital onto one axis.
                                           const unsigned int &j_orbital_position, // The j-th atomic orbital onto one axis.
                                           const double &i_exponent,               // The i-th gf exponent.
                                           const double &j_exponent)               // The j-th gf exponent.
{
    double sum = 0.0;
    unsigned int i = 0;
    #pragma omp parallel for private(i) reduction(+:sum) ordered schedule(dynamic)
    for(i = 0; i <= i_orbital_position; ++i)
    {
        unsigned int j = 0;
        #pragma omp parallel for private(j) reduction(+:sum) ordered schedule(dynamic)
        for(j = 0; j <= j_orbital_position; ++j)
        {
            tools get;
            double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0, g = 0.0;
            #pragma omp parallel sections num_threads(7)
            {
                #pragma omp section
                {
                    a = get.binomial_coeff(i, i_orbital_position);
                }
                #pragma omp section
                {
                    b = get.binomial_coeff(j, j_orbital_position);
                }
                #pragma omp section
                {
                    c = get.double_factorial_of(i + j - 1);
                }
                #pragma omp section
                {
                    d = gf_product(i_exponent,
                                   j_exponent,
                                   position(i_atom),
                                   position(j_atom)) - position(i_atom);
                }
                #pragma omp section
                {
                    e = gf_product(i_exponent,
                                   j_exponent,
                                   position(i_atom),
                                   position(j_atom)) - position(j_atom);
                }
                #pragma omp section
                {
                    f = std::sqrt(M_PI/(i_exponent + j_exponent));
                }
                #pragma omp section
                {
                    g = std::pow(2.0*(i_exponent + j_exponent), (i + j)/2.0);
                }
            }
//
//          Minhhuy Hô and Julio Manuel Hernández-Pérez;
//          The Mathematica Journal;
//          Evaluation of Gaussian Molecular Integrals I - Overlap Integrals;
//          equation (6):
            #pragma omp atomic
            sum += a*b
                    *c
                    *std::pow(d, i_orbital_position - i)
                    *std::pow(e, j_orbital_position - j)
                    *f/g;
        }
    }
    return sum;
}
//
//
//
double lcao_wavefunction::overlap_integral(array &type,                      // The atomic types.
                                           array &x,                         // The atomic x-axis positions.
                                           array &y,                         // The atomic y-axis positions.
                                           array &z,                         // The atomic z-axis positions.
                                           const unsigned int &i_atom,       // The i-th atom.
                                           const unsigned int &j_atom,       // The j-th atom.
                                           const unsigned int &theory_level) // The basis set type. 
{
    tools get;
    periodic_table i_basis_set(theory_level, type(i_atom));
    periodic_table j_basis_set(theory_level, type(j_atom));
    double ij_distance = get.point_distance(x(i_atom),
                                            y(i_atom),
                                            z(i_atom),
                                            x(j_atom),
                                            y(j_atom),
                                            z(j_atom));
    double s_integral = 0.0;
    unsigned int m_primitive = 0;
    #pragma omp parallel for private(m_primitive) reduction(+:s_integral) ordered schedule(dynamic)
    for(m_primitive = 1; 
        m_primitive <= i_basis_set.periodic_table::basis_size(); 
        ++m_primitive)
    {
        unsigned int n_primitive = 0;
        #pragma omp parallel for private(n_primitive) reduction(+:s_integral) ordered schedule(dynamic)
        for(n_primitive = 1; 
            n_primitive <= j_basis_set.periodic_table::basis_size(); 
            ++n_primitive)
        {
            double a = 0.0, b = 0.0;
            #pragma omp parallel sections num_threads(2)
            {
                #pragma omp section
                {
                    a = i_basis_set(BASIS_COEFFICIENT, m_primitive)
                      * j_basis_set(BASIS_COEFFICIENT, n_primitive);
                }
                #pragma omp section
                {
                    b = gf_overlap(i_basis_set(BASIS_EXPONENT, m_primitive),
                                   j_basis_set(BASIS_EXPONENT, n_primitive),
                                   ij_distance);
                }
            }
//
//          A. Szabo and N. Ostlund; 
//          Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//          Appendix A; 
//          pag. 412; 
//          equation (A.9):
            #pragma omp atomic
            s_integral += a*b;
//
        }
    }
    return s_integral;
}
