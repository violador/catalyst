#include "sto3g.hpp"
//
//
//
double sto3g::e(const unsigned int &element, const unsigned int &primitive_function)
{
    switch(element)
    {
    case 1:
    {
        switch(primitive_function)
        {
        case 1: return 3.42525091*gsl_pow_2(1.24); break;
        case 2: return 0.62391373*gsl_pow_2(1.24); break;
        case 3: return 0.16885540*gsl_pow_2(1.24); break;
        }
    }
    break;
    case 2:
    {
        // soon!
    }
    break;
    case 6:
    {
        // soon!
    }
    break;
    };
}
