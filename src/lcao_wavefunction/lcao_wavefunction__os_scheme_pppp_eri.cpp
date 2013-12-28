// ../src/lcao_wavefunction/lcao_wavefunction__os_scheme_pppp_eri.cpp ------------------ //
//
// File author: Humberto Jr. 
//
// Date: 12/2013
//
// Description: Given the four unormalized GF exponents, alpha, beta, gamma and delta
//              centered at atoms A, B, C and D, respectively; and the positions of A, 
//              B, C and D onto one axis; this function returns the zero order ERI over
//              the four p type orbitals, (pppp)^0, at the Obara-Saika scheme.
//
// References:  J. Chem. Phys. 84, 3963 (1986); http://dx.doi.org/10.1063/1.450106 
//
// ------------------------------------------------------------------------------------- //
#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::os_scheme_pppp_eri(array &r,                   // The atomic positions onto one axis.
                                             const unsigned int &atom_a, // The atom A.
                                             const unsigned int &atom_b, // The atom B.
                                             const unsigned int &atom_c, // The atom C.
                                             const unsigned int &atom_d, // The atom D.
                                             const double &alpha,        // The GF exponent at atom A.
                                             const double &beta,         // The GF exponent at atom B.
                                             const double &gamma,        // The GF exponent at atom C.
                                             const double &delta)        // The GF exponent at atom D.
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, 
           e = 0.0, f = 0.0, g = 0.0, h = 0.0;
    #pragma omp parallel sections num_threads(8)
    {
        #pragma omp section
        {
            a = gf_product(gamma,
                           delta,
                           r(atom_c),
                           r(atom_d)) - r(atom_d);
        }
        #pragma omp section
        {
            b = os_scheme_ppps_eri(r,
                                   atom_a,
                                   atom_b,
                                   atom_c,
                                   atom_d,
                                   alpha,
                                   beta,
                                   gamma,
                                   delta);
        }
        #pragma omp section
        {
            c = gf_overlap_product(alpha,
                                   beta,
                                   gamma,
                                   delta,
                                   r(atom_a),
                                   r(atom_b),
                                   r(atom_c),
                                   r(atom_d)) - gf_product(gamma,
                                                           delta,
                                                           r(atom_c),
                                                           r(atom_d));
        }
        #pragma omp section
        {
            d = os_scheme_aux_eri(r,
                                  1,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  orbital::p,
                                  orbital::p,
                                  orbital::p,
                                  orbital::s,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
        }
        #pragma omp section
        {
            e = os_scheme_aux_eri(r,
                                  1,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  orbital::s,
                                  orbital::p,
                                  orbital::p,
                                  orbital::s,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
        }
        #pragma omp section
        {
            f = os_scheme_aux_eri(r,
                                  1,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  orbital::p,
                                  orbital::s,
                                  orbital::p,
                                  orbital::s,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
        }
        #pragma omp section
        {
            g = os_scheme_ppss_eri(r,
                                   atom_a,
                                   atom_b,
                                   atom_c,
                                   atom_d,
                                   alpha,
                                   beta,
                                   gamma,
                                   delta);
        }
        #pragma omp section
        {
            h = os_scheme_aux_eri(r,
                                  1,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  orbital::p,
                                  orbital::p,
                                  orbital::s,
                                  orbital::s,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
            h *= (alpha + beta)*(gamma + delta);
            h /= alpha + beta + gamma + delta;
            h /= gamma + delta;
        }
    }
//
//  S. Obara and A. Saika;
//  The Journal of Chemical Physics;
//  Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//  table I:
    return a*b + c*d 
               + (e + f)/2.0*(alpha + beta + gamma + delta) 
               + (g - h)/2.0*(gamma + delta);
}
