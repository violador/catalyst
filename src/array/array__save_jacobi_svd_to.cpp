//
//
//
inline void save_jacobi_svd_to(array &u_matrix, array &eigenvalues)
{
    if(is_2d_array and (not deleted_array))
    {
        gsl_linalg_SV_decomp_jacobi(&gsl_2d_view.matrix, &u_matrix.gsl_2d_view.matrix, &eigenvalues.gsl_1d_view.vector);
    }
    else
    {
        global_log::file.write_debug_msg("array::save_jacobi_svd_to(): Array ID = ",
                                         array_id,
                                         ", was not possible to work. Maybe the current array is either not a 2D type or it is deleted!");
    }
};
