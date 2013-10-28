//
//
//
inline double norm()
{
    switch(is_1d_array and (not deleted_array))
    {
        case false: return 0.0; break;
        case  true: return cblas_dnrm2(sizeof_row, user_1d_array, 1); break;
    }
};
