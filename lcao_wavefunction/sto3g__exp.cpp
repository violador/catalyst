#include "sto3g.hpp"
//
//
//
double lcao_wavefunction::sto3g::exp(const unsigned int &atom_type, const unsigned int &primitive_function)
{
    switch(atom_type)
    {
    case 1:
    {
        switch(primitive_function)
        {
        case 1:  return 3.42525091; break;
        case 2:  return 0.62391373; break;
        case 3:  return 0.16885540; break;
        default: return 0.0; 
        };
    }
    break;
    case 2:
    {
        switch(primitive_function)
        {
        case 1:  return 6.36242139; break;
        case 2:  return 1.15892300; break;
        case 3:  return 0.31364979; break;
        default: return 0.0; 
        };
    }
    break;
    case 6:
    {
        switch(primitive_function)
        {
        case 1:  return 71.6168370; break;
        case 2:  return 13.0450960;  break;
        case 3:  return 3.5305122;   break;
        case 4:  return 2.9412494;   break;
        case 5:  return 0.6834831;   break;
        case 6:  return 0.2222899;   break;
        default: return 0.0; 
        };
    }
    break;
   default: return 0.0; 
   };
}
