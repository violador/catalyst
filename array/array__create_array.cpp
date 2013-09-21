#include "array.hpp"
//
//
//
void array::create_array(const unsigned int local_row_size,
                         const unsigned int local_column_size,
                         const unsigned int local_1st_layer_size,
                         const unsigned int local_2nd_layer_size)
{
    if((local_row_size > 0) and (local_column_size == 0))
    {
        #pragma omp parallel sections num_threads(15)
        {
            #pragma omp section
            {
                tools id;
                array_id = (short unsigned int) id.generate_integral_type((long unsigned int) &array_name);
            }
            #pragma omp section
            {
                is_1d_array = true;
            }
            #pragma omp section
            {
                is_2d_array = false;
            }
            #pragma omp section
            {
                is_3d_array = false;
            }
            #pragma omp section
            {
                is_4d_array = false;
            }
            #pragma omp section
            {
                sizeof_row = local_row_size;
                user_1d_array = gsl_vector_calloc(local_row_size);
            }
            #pragma omp section
            {
                sizeof_column = 0;
            }
            #pragma omp section
            {
                sizeof_1st_layer = 0;
            }
            #pragma omp section
            {
                sizeof_2nd_layer = 0;
            }
            #pragma omp section
            {
                sizeof_3rd_layer = 0;
            }
            #pragma omp section
            {
                is_const_array = false;
            }
            #pragma omp section
            {
                is_square_array = false;
            }
            #pragma omp section
            {
                created_array = true;
            }
            #pragma omp section
            {
                deleted_array = false;
            }
            #pragma omp section
            {
                lowend_mode_on = false;
            }
            #pragma omp section
            {
                array_name = DEFAULT_ARRAY_NAME;
            }
        }
    }
    else if((local_row_size > 0) and (local_column_size > 0) and (local_1st_layer_size == 0))
    {
        *this = array(local_row_size, local_column_size);
    }
    else if((local_row_size > 0) and (local_column_size > 0) and (local_1st_layer_size > 0) and (local_2nd_layer_size == 0))
    {
        *this = array(local_row_size, local_column_size, local_1st_layer_size);
    }
    else
    {
        *this = array(local_row_size, local_column_size, local_1st_layer_size, local_2nd_layer_size);
    }    
}
