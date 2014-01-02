//
//
//
inline double &function_coeff(const unsigned int &primitive)
{
    switch(primitive <= current_set_size)
    {
        case false: return coeff[0]; break;
        case  true: return coeff[primitive]; break;
    }
};
