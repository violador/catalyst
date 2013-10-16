//
//
//
inline double norm()
{
    if(is_1d_array and (not deleted_array))
    {
        return cblas_dnrm2(sizeof_row, user_1d_array, 1);
    }
    else
    {
        return 0.0;
    }
};
