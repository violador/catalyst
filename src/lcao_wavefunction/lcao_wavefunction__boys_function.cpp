#include "lcao_wavefunction.hpp"
//
//
//
double lcao_wavefunction::boys_function(const double &order,
                                        const double &value)
{
    double a = 0.0, b = 0.0, c = 0.0;
    #pragma omp parallel sections num_threads(3)
    {
        #pragma omp section
        {
            a = tools::gamma_function(order + 0.5);
        }
        #pragma omp section
        {
            b = tools::incomplete_gamma_function(order + 0.5, value);
        }
        #pragma omp section
        {
            c = std::pow(2.0*value, order + 0.5);
        }
    }
//  
//  Guseinov and Mamedov;
//  Journal of Mathematical Chemistry;
//  Evaluation of the Boys function using analytical relations;
//  equation (3):
    return (a - b)/c;
} 
