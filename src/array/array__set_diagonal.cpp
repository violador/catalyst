//
//
//
inline void set_diagonal(const double &value)
{
    switch(is_2d_array 
           and (not deleted_array) 
           and (not is_const_array))
    {
        case true:
        gsl_vector_view diagonal = gsl_matrix_diagonal(&gsl_2d_view.matrix);
        gsl_vector_set_all(&diagonal.vector, value);
        break;
    }
};
