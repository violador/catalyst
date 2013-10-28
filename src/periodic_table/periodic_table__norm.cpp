//
//
//
inline double norm(const unsigned int &primitive_function)
{
    switch(current_level)
    {
        case 1: return std::pow(2.0*exponent[primitive_function]
                                   *gsl_pow_2(slater_exponent)/M_PI, 0.75); break;
    }
    return 0.0;
};
