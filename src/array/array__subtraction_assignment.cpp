#include "array.hpp"
//
//
//
void array::operator -=(const array &b)
{
//
//  Given the arrays A (the this pointer) and B: A = A - B
//
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            if(this -> is_1d_array 
               and b.is_1d_array 
               and (this -> sizeof_row == b.sizeof_row)
               and (not this -> is_const_array)
               and (not this -> deleted_array))
            {
                cblas_daxpy(this -> sizeof_row,
                            -1.0,
                            b.user_1d_array,
                            1,
                            this -> user_1d_array,
                            1);
            }
        }
        #pragma omp section
        {
            if(this -> is_2d_array 
               and b.is_2d_array 
               and (this -> sizeof_row == b.sizeof_row) 
               and (this -> sizeof_column == b.sizeof_column)
               and (not this -> is_const_array)
               and (not this -> deleted_array))
            {
                cblas_daxpy((this -> sizeof_row)*(this -> sizeof_column),
                            -1.0,
                            b.user_2d_array,
                            1,
                            this -> user_2d_array,
                            1);
            }
        }
        #pragma omp section
        {
            if(this -> is_3d_array 
               and b.is_3d_array 
               and (this -> sizeof_row == b.sizeof_row) 
               and (this -> sizeof_column == b.sizeof_column) 
               and (this -> sizeof_1st_layer == b.sizeof_1st_layer)
               and (not this -> is_const_array)
               and (not this -> deleted_array))
            {
                unsigned int i = 0, j = 0, m = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < this -> sizeof_row; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < this -> sizeof_column; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < this -> sizeof_1st_layer; m++)
                        {
                            this -> user_3d_array[i][j][m] = this -> user_3d_array[i][j][m] 
                                                           - b.user_3d_array[i][j][m];
                        }
                    }
                }
            }
        }
        #pragma omp section
        {
            if(this -> is_4d_array    
               and b.is_4d_array 
               and (this -> sizeof_row == b.sizeof_row) 
               and (this -> sizeof_column == b.sizeof_column) 
               and (this -> sizeof_1st_layer == b.sizeof_1st_layer)
               and (this -> sizeof_2nd_layer == b.sizeof_2nd_layer)
               and (not this -> is_const_array)
               and (not this -> deleted_array))
            {
                unsigned int i = 0, j = 0, m = 0, n = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < this -> sizeof_row; i++)
                {
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < this -> sizeof_column; j++)
                    {
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < this -> sizeof_1st_layer; m++)
                        {
                            #pragma omp parallel for private(n) ordered schedule(dynamic)
                            for(n = 0; n < this -> sizeof_2nd_layer; n++)
                            {
                                 this -> user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n] 
                                                                   - b.user_4d_array[i][j][m][n];
                            }
                        }
                    }
                }
            }
        }
    } // pragma omp parallel sections num_threads(4)
}
