#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::overlap_integral(array &r,                      // The atomic positions onto one axis.
                                           const unsigned int &atom_a,    // The atom A.
                                           const unsigned int &atom_b,    // The atom B.
                                           const unsigned int &a_orbital, // The orbital component over the atom A.
                                           const unsigned int &b_orbital, // The orbital component over the atom B.
                                           const double &alpha,           // The GF exponent at atom A.
                                           const double &beta)            // The GF exponent at atom B.
{
    double sum = 0.0;
    unsigned int i = 0;
    #pragma omp parallel for private(i) reduction(+:sum) ordered schedule(dynamic)
    for(i = 0; i <= a_orbital; ++i)
    {
        unsigned int j = 0;
        #pragma omp parallel for private(j) reduction(+:sum) ordered schedule(dynamic)
        for(j = 0; j <= b_orbital; ++j)
        {
            double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0, g = 0.0;
            #pragma omp parallel sections num_threads(7)
            {
                #pragma omp section
                {
                    a = tools::binomial_coeff(i, a_orbital);
                }
                #pragma omp section
                {
                    b = tools::binomial_coeff(j, b_orbital);
                }
                #pragma omp section
                {
                    c = tools::double_factorial(i + j - 1);
                }
                #pragma omp section
                {
                    d = gf_product(alpha,
                                   beta,
                                   r(atom_a),
                                   r(atom_b)) - r(atom_a);
                }
                #pragma omp section
                {
                    e = gf_product(alpha,
                                   beta,
                                   r(atom_a),
                                   r(atom_b)) - r(atom_b);
                }
                #pragma omp section
                {
                    f = std::sqrt(M_PI/(alpha + beta));
                }
                #pragma omp section
                {
                    g = std::pow(2.0*(alpha + beta), (i + j)/2.0);
                }
            }
//
//          Minhhuy Hô and Julio Manuel Hernández-Pérez;
//          The Mathematica Journal;
//          Evaluation of gaussian molecular integrals I - overlap integrals;
//          equation (6):
            #pragma omp atomic
            sum += a*b
                    *c
                    *std::pow(d, a_orbital - i)
                    *std::pow(e, b_orbital - j)
                    *f/g;
        }
    }
    return sum;
}
//
//
//
double lcao_wavefunction::overlap_integral(array &r,                      // The atomic positions onto one axis.
                                           const unsigned int &atom_a,    // The atom A.
                                           const unsigned int &atom_b,    // The atom B.
                                           const unsigned int &atom_c,    // The atom C.
                                           const unsigned int &a_orbital, // The orbital component over the atom A.
                                           const unsigned int &b_orbital, // The orbital component over the atom B.
                                           const unsigned int &c_orbital, // The orbital component over the atom C.
                                           const double &alpha,           // The GF exponent at atom A.
                                           const double &beta,            // The GF exponent at atom B.
                                           const double &gamma)           // The GF exponent at atom C.
{
    double sum = 0.0;
    unsigned int i = 0;
    #pragma omp parallel for private(i) reduction(+:sum) ordered schedule(dynamic)
    for(i = 0; i <= a_orbital; ++i)
    {
        unsigned int j = 0;
        #pragma omp parallel for private(j) reduction(+:sum) ordered schedule(dynamic)
        for(j = 0; j <= b_orbital; ++j)
        {
            unsigned int p = 0;
            #pragma omp parallel for private(p) reduction(+:sum) ordered schedule(dynamic)
            for(p = 0; p <= c_orbital; ++p)
            {
                double a = 0.0, b = 0.0, c = 0.0, d = 0.0, 
                       e = 0.0, f = 0.0, g = 0.0, h = 0.0, m = 0.0;
                #pragma omp parallel sections num_threads(9)
                {
                    #pragma omp section
                    {
                        a = tools::binomial_coeff(i, a_orbital);
                    }
                    #pragma omp section
                    {
                        b = tools::binomial_coeff(j, b_orbital);
                    }
                    #pragma omp section
                    {
                        c = tools::binomial_coeff(p, c_orbital);
                    }
                    #pragma omp section
                    {
                        d = tools::double_factorial(i + j + p - 1);
                    }
                    #pragma omp section
                    {
                        e = gf_product(alpha,
                                       beta,
                                       gamma,
                                       r(atom_a),
                                       r(atom_b),
                                       r(atom_c)) - r(atom_a);
                    }
                    #pragma omp section
                    {
                        f = gf_product(alpha,
                                       beta,
                                       gamma,
                                       r(atom_a),
                                       r(atom_b),
                                       r(atom_c)) - r(atom_b);
                    }
                    #pragma omp section
                    {
                        g = gf_product(alpha,
                                       beta,
                                       gamma,
                                       r(atom_a),
                                       r(atom_b),
                                       r(atom_c)) - r(atom_c);
                    }
                    #pragma omp section
                    {
                        h = std::sqrt(M_PI/(alpha + beta + gamma));
                    }
                    #pragma omp section
                    {
                        m = std::pow(2.0*(alpha + beta + gamma), (i + j + p)/2.0);
                    }
                }
//
//              S. Obara and A. Saika;
//              The Journal of Chemical Physics;
//              Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//              equation (17):
                #pragma omp atomic
                sum += a*b
                        *c
                        *d
                        *std::pow(e, a_orbital - i)
                        *std::pow(f, b_orbital - j)
                        *std::pow(g, c_orbital - p)
                        *h/m;
            }
        }
    }
    return sum;
}
//
//
//
double lcao_wavefunction::overlap_integral(array &type,                // The atomic types.
                                           array &x,                   // The atomic positions onto x-axis.
                                           array &y,                   // The atomic positions onto y-axis.
                                           array &z,                   // The atomic positions onto z-axis.
                                           const unsigned int &atom_a, // The atom A.
                                           const unsigned int &atom_b, // The atom B.
                                           const unsigned int &level)  // The basis set type. 
{
    basis_set a_psi(type(atom_a), level); 
    basis_set b_psi(type(atom_b), level);
    double ab_distance = tools::point_distance(x(atom_a),
                                               y(atom_a),
                                               z(atom_a),
                                               x(atom_b),
                                               y(atom_b),
                                               z(atom_b));
    double s_integral = 0.0;
    unsigned int m_primitive = 0;
    #pragma omp parallel for private(m_primitive) reduction(+:s_integral) ordered schedule(dynamic)
    for(m_primitive = 1; m_primitive <= a_psi.basis_set::size(); ++m_primitive)
    {
        unsigned int n_primitive = 0;
        #pragma omp parallel for private(n_primitive) reduction(+:s_integral) ordered schedule(dynamic)
        for(n_primitive = 1; n_primitive <= b_psi.basis_set::size(); ++n_primitive)
        {
            double a = 0.0, b = 0.0;
            #pragma omp parallel sections num_threads(2)
            {
                #pragma omp section
                {
                    a = a_psi.basis_set::function_coeff(m_primitive)
                      * b_psi.basis_set::function_coeff(n_primitive);
                }
                #pragma omp section
                {
                    b = gf_overlap_integral(a_psi.basis_set::function_expon(m_primitive),
                                            b_psi.basis_set::function_expon(n_primitive),
                                                                            ab_distance);
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
        }
    }
    return s_integral;
}
