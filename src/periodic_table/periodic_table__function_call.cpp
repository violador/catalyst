//
//
//
inline double operator ()(const unsigned int &option, const unsigned int &primitive_function) 
{
    switch(basis_database_ready)
    {
        case true:
        switch(option)
        {
            case    BASIS_EXPONENT: return exponent[primitive_function]*gsl_pow_2(slater_exponent); break;
            case BASIS_COEFFICIENT: return coefficient[primitive_function]*norm(primitive_function); break;
        }
        break;
    }
    return exponent[0];
};
