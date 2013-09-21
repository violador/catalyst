//
//
//
inline double norm()
{
    if(is_1d_array and (not deleted_array))
    {
        return gsl_blas_dnrm2(user_1d_array);
    }
};
