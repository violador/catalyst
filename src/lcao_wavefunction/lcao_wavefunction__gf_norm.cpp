// ../src/lcao_wavefunction/lcao_wavefunction__gf_norm.cpp ----------------------------- //
//
// File author: Humberto Jr. 
//
// Date: 11/2013
//
// Description: Given the unormalized GF exponent centered at a given atom; and the
//              three components of the current angular momentum; this function 
//              returns its normalization factor.
//
// References:  The Mathematica Journal, (2012); http://dx.doi.org/doi:10.3888/tmj.14-3
//
// ------------------------------------------------------------------------------------- //
#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::gf_norm(const double &alpha,   // The GF exponent at a given atom.
                                  const unsigned int &x, // The x-axis angular component.
                                  const unsigned int &y, // The y-axis angular component.
                                  const unsigned int &z) // The z-axis angular component.
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0;
    #pragma omp parallel sections num_threads(5)
    {
        #pragma omp section
        {
            a = std::pow(2.0*alpha/M_PI, 0.75); 
        }
        #pragma omp section
        {
            b = std::pow(4.0*alpha, (x + y + z)/2.0);
        }
        #pragma omp section
        {
            c = tools::double_factorial(2*x - 1);
        }
        #pragma omp section
        {
            d = tools::double_factorial(2*y - 1);
        }
        #pragma omp section
        {
            e = tools::double_factorial(2*z - 1);
        }
    }
//
//  Minhhuy Hô and Julio Manuel Hernández-Pérez;
//  The Mathematica Journal;
//  Evaluation of gaussian molecular integrals I - overlap integrals;
    return a*b/std::sqrt(c*d*e);
}
