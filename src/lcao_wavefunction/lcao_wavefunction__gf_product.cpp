// ../src/lcao_wavefunction/lcao_wavefunction__gf_product.cpp -------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: Given two or three unormalized GF exponents, alpha and beta, centered 
//              at atom A and atom B, respectively; or alpha, beta and gamma, centered
//              at atom A, atom B and atom C, respectively; and the positions of A and
//              B; or A, B and C onto one axis; this function returns the position of
//              the point P(A, B) or P(A, B, C) on a line joining the atoms at that 
//              axis. 
//
// References:  A. Szabo and N. Ostlund; Modern Quantum Chemistry - Introduction to 
//              Advanced Electronic Sctructure.
//
//              J. Chem. Phys. 84, 3963 (1986); http://dx.doi.org/10.1063/1.450106
// ------------------------------------------------------------------------------------- //
//
//
//
inline double gf_product(const double &alpha, // The GF exponent at atom A.
                         const double &beta,  // The GF exponent at atom B.
                         const double &a,     // The position of atom A onto one axis.
                         const double &b)     // The position of atom B onto one axis.
{
//
//  A. Szabo and N. Ostlund; 
//  Modern Quantum Chemistry - Introduction to Advanced Electronic Sctructure;
//  Appendix A; 
//  pag. 411; 
//  equation (A.4):
    return (alpha*a + beta*b)/(alpha + beta);
};
//
//
//
inline double gf_product(const double &alpha, // The GF exponent at atom A.
                         const double &beta,  // The GF exponent at atom B.
                         const double &gamma, // The GF exponent at atom C.
                         const double &a,     // The position of atom A onto one axis.
                         const double &b,     // The position of atom B onto one axis.
                         const double &c)     // The position of atom C onto one axis.
{
//
//  S. Obara and A. Saika;
//  The Journal of Chemical Physics;
//  Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//  equation (16):
    return (alpha*a + beta*b + gamma*c)/(alpha + beta + gamma);
};
