//
//
//
inline double norm(const unsigned int &primitive_function)
{
    switch(current_level)
    {
        case STO3G: return std::pow(2.0*exponent[primitive_function]/M_PI, 0.75); break;
    }
    return 0.0;
};
