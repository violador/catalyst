//
//
//
inline double &function_expon(const unsigned int &primitive)
{
    switch(primitive <= current_set_size)
    {
        case false: return expon[0]; break;
        case  true: return expon[primitive]; break;
    }
};
