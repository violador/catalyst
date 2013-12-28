// ../src/lcao_wavefunction/lcao_wavefunction__os_scheme_ssss_eri.cpp ------------------ //
//
// File author: Humberto Jr. 
//
// Date: 12/2013
//
// Description: Given the four unormalized GF exponents, alpha, beta, gamma and delta
//              centered at atoms A, B, C and D, respectively; the positions of A, 
//              B, C and D onto one axis; the components for each orbital at each
//              atom; and the ERI order; this function returns the auxiliary ERI over
//              the four orbitals, (spdf)^order, at the Obara-Saika scheme.
//
// References:  J. Chem. Phys. 84, 3963 (1986); http://dx.doi.org/10.1063/1.450106 
//
// ------------------------------------------------------------------------------------- //
#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::os_scheme_aux_eri(array &r,                      // The atomic positions onto one axis.
                                            const unsigned int &order,     // The auxiliary ERI order.
                                            const unsigned int &atom_a,    // The atom A.
                                            const unsigned int &atom_b,    // The atom B.
                                            const unsigned int &atom_c,    // The atom C.
                                            const unsigned int &atom_d,    // The atom D.
                                            const unsigned int &a_orbital, // The orbital component over the atom A.
                                            const unsigned int &b_orbital, // The orbital component over the atom B.
                                            const unsigned int &c_orbital, // The orbital component over the atom C.
                                            const unsigned int &d_orbital, // The orbital component over the atom D.
                                            const double &alpha,           // The GF exponent at atom A.
                                            const double &beta,            // The GF exponent at atom B.
                                            const double &gamma,           // The GF exponent at atom C.
                                            const double &delta)           // The GF exponent at atom D.
{
//
//  Auxiliary ERI for order = 0:
    switch(order)
    {
        case 0:
        switch(check_eri_type(a_orbital, b_orbital, c_orbital, d_orbital))
        {
            case eri::ssss: return os_scheme_ssss_eri(r,
                                                      atom_a,
                                                      atom_b,
                                                      atom_c,
                                                      atom_d,
                                                      alpha,
                                                      beta,
                                                      gamma,
                                                      delta); break;
            case eri::psss: return os_scheme_psss_eri(r,
                                                      atom_a,
                                                      atom_b,
                                                      atom_c,
                                                      atom_d,
                                                      alpha,
                                                      beta,
                                                      gamma,
                                                      delta); break;
            case eri::psps: return os_scheme_psps_eri(r,
                                                      atom_a,
                                                      atom_b,
                                                      atom_c,
                                                      atom_d,
                                                      alpha,
                                                      beta,
                                                      gamma,
                                                      delta); break;
            case eri::ppss: return os_scheme_ppss_eri(r,
                                                      atom_a,
                                                      atom_b,
                                                      atom_c,
                                                      atom_d,
                                                      alpha,
                                                      beta,
                                                      gamma,
                                                      delta); break;
            case eri::ppps: return os_scheme_ppps_eri(r,
                                                      atom_a,
                                                      atom_b,
                                                      atom_c,
                                                      atom_d,
                                                      alpha,
                                                      beta,
                                                      gamma,
                                                      delta); break;
            case eri::pppp: return os_scheme_pppp_eri(r,
                                                      atom_a,
                                                      atom_b,
                                                      atom_c,
                                                      atom_d,
                                                      alpha,
                                                      beta,
                                                      gamma,
                                                      delta); break;
        }
        break;
    }
//
//  Auxiliary ERI for order > 0 and type (ssss):
    switch(a_orbital == orbital::s
           and b_orbital == orbital::s
           and c_orbital == orbital::s
           and d_orbital == orbital::s)
    {
        case true: 
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
//      S. Obara and A. Saika;
//      The Journal of Chemical Physics;
//      Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//      equation (44):
        return a*b*boys_function(order, c)/d;
        break;
    }
    
//
//  Auxiliary ERI for order > 0:
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, 
           f = 0.0, g = 0.0, h = 0.0, i = 0.0, j = 0.0;
    #pragma omp parallel sections num_threads(10)
    {
        #pragma omp section
        {
            a = gf_product(alpha,
                           beta,
                           r(atom_a),
                           r(atom_b)) - r(atom_a);
        }
        #pragma omp section
        {
            b = os_scheme_aux_eri(r,
                                  order,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  a_orbital,
                                  b_orbital,
                                  c_orbital,
                                  d_orbital,
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
                                   r(atom_d)) - gf_product(alpha,
                                                           beta,
                                                           r(atom_a),
                                                           r(atom_b));
        }
        #pragma omp section
        {
            d = os_scheme_aux_eri(r,
                                  order + 1,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  a_orbital,
                                  b_orbital,
                                  c_orbital,
                                  d_orbital,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
        }
        #pragma omp section
        {
            e = os_scheme_aux_eri(r,
                                  order,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  a_orbital - 1,
                                  b_orbital,
                                  c_orbital,
                                  d_orbital,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
        }
        #pragma omp section
        {
            f = os_scheme_aux_eri(r,
                                  order + 1,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  a_orbital - 1,
                                  b_orbital,
                                  c_orbital,
                                  d_orbital,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
            f *= (alpha + beta)*(gamma + delta);
            f /= alpha + beta + gamma + delta;
            f /= alpha + beta;
        }
        #pragma omp section
        {
            g = os_scheme_aux_eri(r,
                                  order,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  a_orbital,
                                  b_orbital - 1,
                                  c_orbital,
                                  d_orbital,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
        }
        #pragma omp section
        {
            h = os_scheme_aux_eri(r,
                                  order + 1,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  a_orbital,
                                  b_orbital - 1,
                                  c_orbital,
                                  d_orbital,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
            h *= (alpha + beta)*(gamma + delta);
            h /= alpha + beta + gamma + delta;
            h /= alpha + beta;
        }
        #pragma omp section
        {
            i = os_scheme_aux_eri(r,
                                  order + 1,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  a_orbital,
                                  b_orbital,
                                  c_orbital - 1,
                                  d_orbital,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
            i *= c_orbital/2.0*(alpha + beta + gamma + delta);
        }
        #pragma omp section
        {
            j = os_scheme_aux_eri(r,
                                  order + 1,
                                  atom_a,
                                  atom_b,
                                  atom_c,
                                  atom_d,
                                  a_orbital,
                                  b_orbital,
                                  c_orbital,
                                  d_orbital - 1,
                                  alpha,
                                  beta,
                                  gamma,
                                  delta);
            j *= d_orbital/2.0*(alpha + beta + gamma + delta);
        }
    }
//
//  S. Obara and A. Saika;
//  The Journal of Chemical Physics;
//  Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//  equation (39):
    return a*b + c*d 
               + (e - f)*a_orbital/2.0*(a_orbital + b_orbital)
               + (g - h)*b_orbital/2.0*(a_orbital + b_orbital)
               + i
               + j;
}
