// ../src/lcao_wavefunction/lcao_wavefunction__gf_overlap_factor.cpp ------------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: Given two or three unormalized GF exponents, alpha and beta, centered 
//              at atom A and atom B, respectively; or alpha, beta and gamma, centered
//              at atom A, atom B and atom C, respectively; and also the distances, d, 
//              between A and B; or between A and B and P(A, B) and C; this function 
//              returns the overlap factor of a GF product.
//
// References:  A. Szabo and N. Ostlund; Modern Quantum Chemistry - Introduction to 
//              Advanced Electronic Sctructure.
//
//              J. Chem. Phys. 84, 3963 (1986); http://dx.doi.org/10.1063/1.450106
// ------------------------------------------------------------------------------------- //
//
//
//
inline double gf_overlap_factor(const double &alpha, // The GF exponent at atom A.
                                const double &beta,  // The GF exponent at atom B.
                                const double &d)     // The A-B distance.
{
//
//  A. Szabo and N. Ostlund; 
//  Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//  Appendix A; 
//  pag. 411; 
//  equation (A.3):
    return gsl_sf_exp(-alpha*beta*gsl_pow_2(d)/(alpha + beta));
};
//
//
//
inline double gf_overlap_factor(const double &alpha, // The GF exponent at atom A.
                                const double &beta,  // The GF exponent at atom B.
                                const double &gamma, // The GF exponent at atom C.
                                const double &d1,    // The A-B distance. 
                                const double &d2)    // The P(A, B)-C distance.
{
//
//  S. Obara and A. Saika;
//  The Journal of Chemical Physics;
//  Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//  equation (11):
    return gf_overlap_factor(alpha, beta, d1)*gf_overlap_factor(alpha + beta, gamma, d2);
};
