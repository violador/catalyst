//
//
//
inline void build_identity_form()
{
    switch(is_2d_array 
           and (not deleted_array) 
           and (not is_const_array))
    {
        case false: break;
        case  true: gsl_matrix_set_identity(&gsl_2d_view.matrix); break;
    }
};
