// ../src/lcao_wavefunction/lcao_wavefunction__os_scheme_ssss_eri.cpp ------------------ //
//
// File author: Humberto Jr. 
//
// Date: 11/2013
//
// Description: Given the four unormalized GF exponents, alpha, beta, gamma and delta
//              centered at atoms A, B, C and D, respectively; and the positions of A, 
//              B, C and D onto one axis; this function returns the zero order ERI over
//              the four s type orbitals, (ssss)^0, at the Obara-Saika scheme.
//
// References:  J. Chem. Phys. 84, 3963 (1986); http://dx.doi.org/10.1063/1.450106 
//
// ------------------------------------------------------------------------------------- //
#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::os_scheme_ssss_eri(array &r,                   // The atomic positions onto one axis.
                                             const unsigned int &atom_a, // The atom A.
                                             const unsigned int &atom_b, // The atom B.
                                             const unsigned int &atom_c, // The atom C.
                                             const unsigned int &atom_d, // The atom D.
                                             const double &alpha,        // The GF exponent at atom A.
                                             const double &beta,         // The GF exponent at atom B.
                                             const double &gamma,        // The GF exponent at atom C.
                                             const double &delta)        // The GF exponent at atom D.
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            a = gf_overlap_integral(alpha,
                                    beta,
                                    tools::module(r(atom_a),
                                                  r(atom_b)));
        }
        #pragma omp section
        {
            b = gf_overlap_integral(gamma,
                                    delta,
                                    tools::module(r(atom_c),
                                                  r(atom_d)));
        }
        #pragma omp section
        {
            double p = gf_product(alpha,
                                  beta,
                                  r(atom_a), 
                                  r(atom_b));
            double q = gf_product(gamma,
                                  delta,
                                  r(atom_c),
                                  r(atom_d));
            c = gsl_pow_2(p - q)
              * (alpha + beta)*(gamma + delta)
              / (alpha + beta + gamma + delta);
        }
        #pragma omp section
        {
            d = std::sqrt(alpha + beta + gamma + delta);
        }
    }
//
//  S. Obara and A. Saika;
//  The Journal of Chemical Physics;
//  Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//  table I:
    return a*b*boys_function(0.0, c)/d;
}
