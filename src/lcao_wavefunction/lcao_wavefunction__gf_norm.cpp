#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::gf_norm(const double &alpha,   // The gf primitive exponent.
                                  const unsigned int &x, // The x-axis angular value.
                                  const unsigned int &y, // The y-axis angular value.
                                  const unsigned int &z) // The z-axis angular value.
{
    tools get;
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
            c = get.double_factorial_of(2*x - 1);
        }
        #pragma omp section
        {
            d = get.double_factorial_of(2*y - 1);
        }
        #pragma omp section
        {
            e = get.double_factorial_of(2*z - 1);
        }
    }
    return a*b/std::sqrt(c*d*e);
}
