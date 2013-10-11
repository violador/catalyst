#include "sto3g.hpp"
//
//
//
double lcao_wavefunction::sto3g::coeff(const unsigned int &atom_type, 
                                       const unsigned int &primitive_function)
{
    switch(atom_type)
    {
    case 1:
    {
        switch(primitive_function)
        {
        case 1:  return 0.15432897*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 2:  return 0.53532814*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 3:  return 0.44463454*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        default: return 0.0;
        };
    }
    break;
    case 2:
    {
        switch(primitive_function)
        {
        case 1:  return 0.15432897*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 2:  return 0.53532814*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 3:  return 0.44463454*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        default: return 0.0;
        };
    }
    break;
    case 6:
    {
        switch(primitive_function)
        { 
        case 1:  return  0.15432897*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 2:  return  0.53532814*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 3:  return  0.44463454*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 4:  return -0.09996723*0.15591627*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 5:  return  0.39951283*0.60768372*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 6:  return  0.70011547*0.39195739*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
/*
        case 7:  return  0.15591627*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 8:  return  0.60768372*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
        case 9:  return  0.39195739*pow(2.0*exp(atom_type, primitive_function)/M_PI, 0.75); break;
*/
        default: return 0.0;
        };
    }
    break;
    default: return 0.0;
    };
}
