// ../src/lcao_wavefunction/lcao_wavefunction__os_scheme_overlap_integral.cpp ---------- //
//
// File author: Humberto Jr. 
//
// Date: 12/2013
//
// Description: Given the three unormalized GF exponents, alpha, beta and gamma 
//              centered at atoms A, B and C, respectively; and the positions of 
//              A, B and C onto one axis; this function returns the three-center 
//              overlap integral, S, at the Obara-Saika scheme.
//
// References:  J. Chem. Phys. 84, 3963 (1986); http://dx.doi.org/10.1063/1.450106 
//
// ------------------------------------------------------------------------------------- //
#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::os_scheme_overlap_integral(array &r,                      // The atomic positions onto one axis.
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
//
//  The S = (sss) case:
    switch(a_orbital == SUB_SHELL_1s 
           and b_orbital == SUB_SHELL_1s
           and c_orbital == SUB_SHELL_1s) 
    {
        case true:
        double a = 0.0, b = 0.0;
        #pragma omp parallel sections num_threads(2) 
        {
            #pragma omp section
            {
                a = std::pow(M_PI/(alpha + beta + gamma), 1.5);
            }
            #pragma omp section
            {
                double p = gf_product(alpha, 
                                      beta, 
                                      r(atom_a),
                                      r(atom_b));
                b = gf_overlap_factor(alpha,
                                      beta,
                                      gamma,
                                      tools::module(r(atom_a), r(atom_b)),
                                      tools::module(p, r(atom_c)));
            }
        }
//
//      S. Obara and A. Saika;
//      The Journal of Chemical Physics;
//      Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//      equation (21):
        return a*b;
        break;
    }
//
//  The general case:
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0;
    #pragma omp parallel sections num_threads(5)
    {
        #pragma omp section
        {
            a = gf_product(alpha,
                           beta,
                           gamma,
                           r(atom_a),
                           r(atom_b),
                           r(atom_c)) - r(atom_a);

        }
        #pragma omp section
        {
            b = os_scheme_overlap_integral(r,
                                           atom_a,
                                           atom_b,
                                           atom_c,
                                           a_orbital,
                                           b_orbital,
                                           c_orbital,
                                           alpha,
                                           beta,
                                           gamma);
        }
        #pragma omp section
        {
            c = a_orbital
              * os_scheme_overlap_integral(r,
                                           atom_a,
                                           atom_b,
                                           atom_c,
                                           a_orbital - 1,
                                           b_orbital,
                                           c_orbital,
                                           alpha,
                                           beta,
                                           gamma);
        }
        #pragma omp section
        {
            d = b_orbital
              * os_scheme_overlap_integral(r,
                                           atom_a,
                                           atom_b,
                                           atom_c,
                                           a_orbital,
                                           b_orbital - 1,
                                           c_orbital,
                                           alpha,
                                           beta,
                                           gamma);
        }
        #pragma omp section
        {
            e = c_orbital
              * os_scheme_overlap_integral(r,
                                           atom_a,
                                           atom_b,
                                           atom_c,
                                           a_orbital,
                                           b_orbital,
                                           c_orbital - 1,
                                           alpha,
                                           beta,
                                           gamma);
        }
    }
//
//  S. Obara and A. Saika;
//  The Journal of Chemical Physics;
//  Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//  equation (20):
    return a*b + c/2.0*(alpha + beta + gamma) 
               + d/2.0*(alpha + beta + gamma) 
               + e/2.0*(alpha + beta + gamma);
}
