//
//
//
inline double &operator ()(const unsigned int &option, const unsigned int &primitive_function) 
{
    switch(basis_database_ready)
    {
        case false:
        {
            return exponent[0];
        }
        break;
        case true:
        {
            switch(option)
            {
                case    BASIS_EXPONENT: return exponent[primitive_function];    break;
                case BASIS_COEFFICIENT: return coefficient[primitive_function]; break;
            }
        }
        break;
    }
    return exponent[0];
};
