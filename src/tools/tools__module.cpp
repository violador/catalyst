//
//
//
template<typename data_type> 
inline data_type module(const data_type &a, 
                        const data_type &b)
{
    switch((a - b) >= 0.0)
    {
        case false: return -1.0*(a - b); break;
        case  true: return a - b; break;
    }
};
