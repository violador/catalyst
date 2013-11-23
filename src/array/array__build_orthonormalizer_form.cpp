#include "array.hpp"
//
//
//
void array::build_orthonormalizer_form()
{
//  (1) To allocate memory for the eigenvectors.
//  (2) To allocate memory for the eigenvalues.
//  (3) To allocate memory for an eigen system computation.
//  (4) To compute the eigenvalues and eigenvectors. 
//  (5) To deallocate the memory for the eigen system computation.
//  (6) To build the transformation matrix form.
    gsl_matrix *eigenvectors = gsl_matrix_calloc(sizeof_row, sizeof_column);            // (1)
    gsl_vector *eigenvalues = gsl_vector_calloc(sizeof_row);                            // (2)
    gsl_eigen_symmv_workspace *memory_allocation = gsl_eigen_symmv_alloc(4*sizeof_row); // (3)
    gsl_eigen_symmv(&gsl_2d_view.matrix, eigenvalues, eigenvectors, memory_allocation); // (4)
    gsl_eigen_symmv_free(memory_allocation);                                            // (5)
    gsl_matrix_set_zero(&gsl_2d_view.matrix);
//
    unsigned int i = 0, j = 0;
    #pragma omp parallel for private(i) ordered schedule(dynamic)
    for(i = 0; i < sizeof_row; ++i)
    {
        #pragma omp parallel for private(j) ordered schedule(dynamic)
        for(j = 0; j < sizeof_column; ++j)
        {
            double a = eigenvectors -> data[i*eigenvectors -> tda + j]/std::sqrt(eigenvalues -> data[j*eigenvalues -> stride]);
            user_2d_array[i*sizeof_row + j] = a; // (6)
        }
    }
//
    gsl_matrix_free(eigenvectors);
    gsl_vector_free(eigenvalues);
    is_const_array = true;
}
