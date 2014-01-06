//
//
//
template<typename data_type> 
inline data_type kronecker_delta(const data_type &a, 
                                 const data_type &b)
{
    switch(a == b)
    {
        case false: return (data_type) 0.0; break;
        case  true: return (data_type) 1.0; break;
    }
};
