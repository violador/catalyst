//
//
//
inline void unset_constant()
{
    switch(not deleted_array and is_const_array)
    {
        case false: break;
        case  true: is_const_array = false; break;
    }
};
