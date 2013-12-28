// ../src/lcao_wavefunction/lcao_wavefunction__gf_overlap_product.cpp ------------------ //
//
// File author: Humberto Jr. 
//
// Date: 10/2013
//
// Description: Given the four unormalized GF exponents, alpha, beta, gamma and delta
//              centered at atoms A, B, C and D, respectively; and the positions of A, 
//              B, C and D onto one axis; this function returns the product between 
//              the overlap of A and B, P(A, B), and C and D, Q(C, D). A line joining 
//              the points P(A, B) and Q(C, D).
//
// References:  J. Chem. Phys. 84, 3963 (1986); http://dx.doi.org/10.1063/1.450106
// ------------------------------------------------------------------------------------- //
//
//
//
inline double gf_overlap_product(const double &alpha, // The GF exponent at atom A.
                                 const double &beta,  // The GF exponent at atom B.
                                 const double &gamma, // The GF exponent at atom C.
                                 const double &delta, // The GF exponent at atom D.
                                 const double &a,     // The position of atom A onto one axis.
                                 const double &b,     // The position of atom B onto one axis.
                                 const double &c,     // The position of atom C onto one axis.
                                 const double &d)     // The position of atom D onto one axis.
{
    double p = 0.0, q = 0.0;
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            p = (alpha + beta)*gf_product(alpha, beta, a, b);
        }
        #pragma omp section
        {
            q = (gamma + delta)*gf_product(gamma, delta, c, d);
        }
    }
//
//  S. Obara and A. Saika;
//  The Journal of Chemical Physics;
//  Efficient recursive computation of molecular integrals over cartesian Gaussian functions;
//  equation (37):
    return (p + q)/(alpha + beta + gamma + delta);
};
