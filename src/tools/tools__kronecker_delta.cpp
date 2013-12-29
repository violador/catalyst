//
//
//
template<typename data_type> 
inline data_type kronecker_delta(const data_type &a, 
                                 const data_type &b)
{
    switch(a == b)
    {
        case false: return 0.0; break;
        case  true: return 1.0; break;
    }
};
