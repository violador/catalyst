//
//
//
inline void build_identity_form()
{
    if(is_2d_array and (not deleted_array) and (not is_const_array))
    {
        gsl_matrix_set_identity(user_2d_array);
    }
}
