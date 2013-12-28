// ../src/lcao_wavefunction/lcao_wavefunction__gf_overlap_integral.cpp ----------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: Given two unormalized GF exponents, alpha and beta, centered at atom A 
//              and atom B, respectively; and also the distance, d, between A and B; 
//              this function returns the minimal overlap integral, S = <A|B>.
//
// References:  A. Szabo and N. Ostlund; Modern Quantum Chemistry - Introduction to 
//              Advanced Electronic Sctructure.
//
// ------------------------------------------------------------------------------------- //
//
//
//
inline double gf_overlap_integral(const double &alpha, // The gf exponent at atom A.
                                  const double &beta,  // The gf exponent at atom B.
                                  const double &d)     // The A-B distance.
{
//
//  A. Szabo and N. Ostlund; 
//  Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//  Appendix A; 
//  pag. 412; 
//  equation (A.9):
    return std::pow(M_PI/(alpha + beta), 1.5)*gsl_sf_exp(-alpha*beta*gsl_pow_2(d)/(alpha + beta));
};
