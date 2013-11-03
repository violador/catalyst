#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::get_overlap_integral(const unsigned int &i_atom,  // The i-th atom.
                                               const unsigned int &j_atom,  // The j-th atom.
                                               const unsigned int &i_shell, // The i-th atomic shell.
                                               const unsigned int &j_shell, // The j-th atomic shell.
                                               const double &i_exponent,    // The i-th gf exponent.
                                               const double &j_exponent,    // The j-th gf exponent.
                                               array &position)             // The atomic positions onto one axis.
{
    double sum = 0.0;
    unsigned int i = 0;
    #pragma omp parallel for private(i) reduction(+:sum) ordered schedule(dynamic)
    for(i = 0; i <= i_shell; i++)
    {
        unsigned int j = 0;
        #pragma omp parallel for private(j) reduction(+:sum) ordered schedule(dynamic)
        for(j = 0; j <= j_shell; j++)
        {
            double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0, g = 0.0;
            #pragma omp parallel sections num_threads(7)
            {
                #pragma omp section
                {
                    a = gsl_sf_fact(i_shell)/(gsl_sf_fact(i)*gsl_sf_fact(i_shell - i));
                }
                #pragma omp section
                {
                    b = gsl_sf_fact(j_shell)/(gsl_sf_fact(j)*gsl_sf_fact(j_shell - j));
                }
                #pragma omp section
                {
                    c = gsl_sf_doublefact(i + j - 1);
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
            #pragma omp atomic
            sum += a*b*c*std::pow(d, i_shell - i)*std::pow(e, j_shell - j)*f/g;
        }
    }
    return sum;
}
//
//
//
double lcao_wavefunction::get_overlap_integral(const unsigned int &i_atom,       // The i-th atom.
                                               const unsigned int &j_atom,       // The j-th atom.
                                               array &type,                      // The atomic types.
                                               array &x,                         // The atomic x-axis positions.
                                               array &y,                         // The atomic y-axis positions.
                                               array &z,                         // The atomic z-axis positions.
                                               const unsigned int &theory_level) // The basis set type. 
{
    periodic_table i_basis_set(theory_level, type(i_atom));
    periodic_table j_basis_set(theory_level, type(j_atom));
    double ij_distance = interatomic_distance(x(i_atom),
                                              y(i_atom),
                                              z(i_atom),
                                              x(j_atom),
                                              y(j_atom),
                                              z(j_atom));
    double s_integral = 0.0;
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
//          A. Szabo and N. Ostlund; 
//          Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//          Appendix A; 
//          pag. 412; 
//          equation (A.9):
            #pragma omp atomic
            s_integral += a*b;
//
        } // for(n_primitive)
    } // for(m_primitive)
    return s_integral;
}
