#include "array.hpp"
//
//
//
void array::operator=(const array &b)
{
//
//  The assignment operation, a = b, for a array object must replace the array contents and some few 
//  properties related to its contents (from "b" to "a", where "a" is the "this" pointer). But not 
//  that data members who define the object identity itself such as its ID, name, filename etc. The 
//  operator must check the "a" and "b" requirements and if any of them is not found, nothing won't 
//  be done. 
//
//                                                                            Humberto Jr. (08/2013)
//
    if(this -> is_1d_array                      // To check the "a" array type. 
       and b.is_1d_array                        // To check the "b" array type.
       and (this -> sizeof_row == b.sizeof_row) // To check if the "a" array size fits the "b" array size.
       and (not this -> is_const_array)         // To check if "a" has permision to be rewritten.
       and (not this -> deleted_array)          // To check if "a" is not a deleted array.
       and this -> created_array)               // To check if "a" is an already initialized array.
    {
        #pragma omp parallel sections num_threads(5)
        {
            #pragma omp section
            {
                gsl_vector_memcpy(this -> user_1d_array, b.user_1d_array);
            }
            #pragma omp section
            {
                this -> is_const_array = b.is_const_array; 
            }
            #pragma omp section
            {
                this -> is_square_array = b.is_square_array;
            }
            #pragma omp section
            {
                this -> is_transposed = b.is_transposed;
            }
            #pragma omp section
            {
                this -> lowend_mode_on = b.lowend_mode_on; 
            }
        }
    }
    else if(this -> is_2d_array 
            and b.is_2d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column)
            and (not this -> is_const_array)
            and (not this -> deleted_array)
            and this -> created_array)
    {
        #pragma omp parallel sections num_threads(5)
        {
            #pragma omp section
            {
                gsl_matrix_memcpy(this -> user_2d_array, b.user_2d_array);
            }
            #pragma omp section
            {
                this -> is_const_array = b.is_const_array;
            }
            #pragma omp section
            {
                this -> is_square_array = b.is_square_array;
            }
            #pragma omp section
            {
                this -> is_transposed = b.is_transposed;
            }
            #pragma omp section
            {
                this -> lowend_mode_on = b.lowend_mode_on;
            }
        }
    }
    else if(this -> is_3d_array
            and b.is_3d_array
            and (this -> sizeof_row == b.sizeof_row)
            and (this -> sizeof_column == b.sizeof_column)
            and (this -> sizeof_1st_layer == sizeof_1st_layer)
            and (not this -> is_const_array)
            and (not this -> deleted_array)
            and this -> created_array)
    {
        #pragma omp parallel sections num_threads(5)
        {
            #pragma omp section
            {
                unsigned int i = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_row; i++)
                {
                    unsigned int j = 0;
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_column; j++)
                    {
                        unsigned int m = 0;
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < sizeof_1st_layer; m++)
                        {
                            this -> user_3d_array[i][j][m] = b.user_3d_array[i][j][m];
                        }
                    }
                }
            }
            #pragma omp section
            {
                this -> is_const_array = b.is_const_array;
            }
            #pragma omp section
            {
                this -> is_square_array = b.is_square_array;
            }
            #pragma omp section
            {
                this -> is_transposed = b.is_transposed;
            }
            #pragma omp section
            {
                this -> lowend_mode_on = b.lowend_mode_on;
            }
        }
    }
    else if(this -> is_4d_array
            and b.is_4d_array
            and (this -> sizeof_row == b.sizeof_row)
            and (this -> sizeof_column == b.sizeof_column)
            and (this -> sizeof_1st_layer == sizeof_1st_layer)
            and (this -> sizeof_2nd_layer == sizeof_2nd_layer)
            and (not this -> is_const_array)
            and (not this -> deleted_array)
            and this -> created_array)
    {
        #pragma omp parallel sections num_threads(5)
        {
            #pragma omp section
            {
                unsigned int i = 0;
                #pragma omp parallel for private(i) ordered schedule(dynamic)
                for(i = 0; i < sizeof_row; i++)
                {
                    unsigned int j = 0;
                    #pragma omp parallel for private(j) ordered schedule(dynamic)
                    for(j = 0; j < sizeof_column; j++)
                    {
                        unsigned int m = 0;
                        #pragma omp parallel for private(m) ordered schedule(dynamic)
                        for(m = 0; m < sizeof_1st_layer; m++)
                        {
                            unsigned int n = 0;
                            #pragma omp parallel for private(n) ordered schedule(dynamic)
                            for(n = 0; n < sizeof_2nd_layer; n++)
                            {
                                this -> user_4d_array[i][j][m][n] = b.user_4d_array[i][j][m][n];
                            }
                        }
                    }
                }
            }
            #pragma omp section
            {
                this -> is_const_array = b.is_const_array;
            }
            #pragma omp section
            {
                this -> is_square_array = b.is_square_array;
            }
            #pragma omp section
            {
                this -> is_transposed = b.is_transposed;
            }
            #pragma omp section
            {
                this -> lowend_mode_on = b.lowend_mode_on;
            }
        }
    }
}
//
//
//
void array::operator+=(const array &b)
{
    if(this -> is_1d_array 
       and b.is_1d_array 
       and (this -> sizeof_row == b.sizeof_row)
       and (not this -> is_const_array)
       and (not this -> deleted_array)
       and this -> created_array)
    {
        gsl_vector_add(this -> user_1d_array, b.user_1d_array);
    }
    else if(this -> is_2d_array 
            and b.is_2d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column)
            and (not this -> is_const_array)
            and (not this -> deleted_array)
            and this -> created_array)
    {        
        gsl_matrix_add(this -> user_2d_array, b.user_2d_array);
    }
    else if(this -> is_3d_array 
            and b.is_3d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column) 
            and (this -> sizeof_1st_layer == b.sizeof_1st_layer)
            and (not this -> is_const_array)
            and (not this -> deleted_array)
            and this -> created_array)
    {
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    this -> user_3d_array[i][j][m] = this -> user_3d_array[i][j][m] + b.user_3d_array[i][j][m];
                }
            }
        }
    }
    else if(this -> is_4d_array    
            and b.is_4d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column) 
            and (this -> sizeof_1st_layer == b.sizeof_1st_layer)
            and (this -> sizeof_2nd_layer == b.sizeof_2nd_layer)
            and (not this -> is_const_array)
            and (not this -> deleted_array)
            and this -> created_array)
    {
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < sizeof_2nd_layer; n++)
                    {
                        this -> user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n] + b.user_4d_array[i][j][m][n];
                    }
                }
            }
        }
    }
}
//
//
//
void array::operator-=(const array &b)
{
    if(this -> is_1d_array 
       and b.is_1d_array 
       and (this -> sizeof_row == b.sizeof_row)
       and (not this -> is_const_array)
       and (not this -> deleted_array)
       and this -> created_array)
    {
        gsl_vector_sub(this -> user_1d_array, b.user_1d_array);
    }
    else if(this -> is_2d_array 
            and b.is_2d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column)
            and (not this -> is_const_array)
            and (not this -> deleted_array)
            and this -> created_array)
    {        
        gsl_matrix_sub(this -> user_2d_array, b.user_2d_array);
    }
    else if(this -> is_3d_array 
            and b.is_3d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column) 
            and (this -> sizeof_1st_layer == b.sizeof_1st_layer)
            and (not this -> is_const_array)
            and (not this -> deleted_array)
            and this -> created_array)
    {
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    this -> user_3d_array[i][j][m] = this -> user_3d_array[i][j][m] - b.user_3d_array[i][j][m];
                }
            }
        }
    }
    else if(this -> is_4d_array    
            and b.is_4d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column) 
            and (this -> sizeof_1st_layer == b.sizeof_1st_layer)
            and (this -> sizeof_2nd_layer == b.sizeof_2nd_layer)
            and (not this -> is_const_array)
            and (not this -> deleted_array)
            and this -> created_array)
    {
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < sizeof_2nd_layer; n++)
                    {
                        this -> user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n] - b.user_4d_array[i][j][m][n];
                    }
                }
            }
        }
    }
}
//
//
//
void array::operator*=(const array &b)
{
    if(this -> is_2d_array 
       and b.is_2d_array 
       and (this -> sizeof_row == b.sizeof_row) 
       and (this -> sizeof_column == b.sizeof_column)
       and (not this -> is_const_array)
       and (not this -> deleted_array)
       and this -> created_array)
    {        
        gsl_matrix *temp_2d_array = gsl_matrix_calloc(this -> sizeof_row, this -> sizeof_column);
        gsl_matrix_swap(this -> user_2d_array, temp_2d_array);
//
        gsl_blas_dgemm((this -> is_transposed? CblasTrans : CblasNoTrans),
                       (b.is_transposed? CblasTrans : CblasNoTrans),
                       1.0,
                       temp_2d_array,
                       b.user_2d_array,
                       1.0,
                       this -> user_2d_array);
//
        gsl_matrix_free(temp_2d_array);
    }
}
//
//
//
array array::operator+(const double &b)
{
    if(this -> is_1d_array)
    {
        array c(this -> sizeof_row);
        c = *this;
        gsl_vector_add_constant(c.user_1d_array, b);
        return c;
    }
    if(this -> is_2d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column);
        c = *this;
        gsl_matrix_add_constant(c.user_2d_array, b);
        return c;
    }
    if(this -> is_3d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    c.user_3d_array[i][j][m] = this -> user_3d_array[i][j][m] + b;
                }
            }
        }
        return c;
    }
    if(this -> is_4d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer, this -> sizeof_2nd_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < sizeof_2nd_layer; n++)
                    {
                        c.user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n] + b;
                    }
                }
            }
        }
        return c;
    }
    else
    {
        return *this;
    }
}
//
//
//
array array::operator+(const array &b)
{
    if(this -> is_1d_array and b.is_1d_array and (this -> sizeof_row == b.sizeof_row))
    {
        array c(b.sizeof_row);
        c = *this;
        gsl_vector_add(c.user_1d_array, b.user_1d_array);
        return c;
    }
    else if(this -> is_2d_array 
            and b.is_2d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column))
    {
        array c(b.sizeof_row, b.sizeof_column);
        c = *this;
        gsl_matrix_add(c.user_2d_array, b.user_2d_array);
        return c;
    }
    else if(this -> is_3d_array
            and b.is_3d_array
            and (this -> sizeof_row == b.sizeof_row)
            and (this -> sizeof_column == b.sizeof_column)
            and (this -> sizeof_1st_layer == b.sizeof_1st_layer))
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    c.user_3d_array[i][j][m] = this -> user_3d_array[i][j][m] + b.user_3d_array[i][j][m];
                }
            }
        }
        return c;
    }
    else if(this -> is_4d_array
            and b.is_4d_array
            and (this -> sizeof_row == b.sizeof_row)
            and (this -> sizeof_column == b.sizeof_column)
            and (this -> sizeof_1st_layer == b.sizeof_1st_layer)
            and (this -> sizeof_2nd_layer == b.sizeof_2nd_layer))
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer, this -> sizeof_2nd_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < sizeof_2nd_layer; n++)
                    {
                        c.user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n] + b.user_4d_array[i][j][m][n];
                    }
                }
            }
        }
        return c;
    }
    else
    {
        return *this;
    }
}
//
//
//
array array::operator-(const double &b)
{
    if(this -> is_1d_array)
    {
        array c(this -> sizeof_row);
        c = *this;
        gsl_vector_add_constant(c.user_1d_array, -b);
        return c;
    }
    if(this -> is_2d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column);
        c = *this;
        gsl_matrix_add_constant(c.user_2d_array, -b);
        return c;
    }
    if(this -> is_3d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    c.user_3d_array[i][j][m] = this -> user_3d_array[i][j][m] - b;
                }
            }
        }
        return c;
    }
    if(this -> is_4d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer, this -> sizeof_2nd_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < sizeof_2nd_layer; n++)
                    {
                        c.user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n] - b;
                    }
                }
            }
        }
        return c;
    }
    else
    {
        return *this;
    }
}
//
//
//
array array::operator-(const array &b)
{
    if(this -> is_1d_array and b.is_1d_array and (this -> sizeof_row == b.sizeof_row))
    {
        array c(b.sizeof_row);
        c = *this;
        gsl_vector_sub(c.user_1d_array, b.user_1d_array);
        return c;
    }
    else if(this -> is_2d_array 
            and b.is_2d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column))
    {
        array c(b.sizeof_row, b.sizeof_column);
        c = *this;
        gsl_matrix_sub(c.user_2d_array, b.user_2d_array);
        return c;
    }
    else if(this -> is_3d_array
            and b.is_3d_array
            and (this -> sizeof_row == b.sizeof_row)
            and (this -> sizeof_column == b.sizeof_column)
            and (this -> sizeof_1st_layer == b.sizeof_1st_layer))
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    c.user_3d_array[i][j][m] = this -> user_3d_array[i][j][m] - b.user_3d_array[i][j][m];
                }
            }
        }
        return c;
    }
    else if(this -> is_4d_array
            and b.is_4d_array
            and (this -> sizeof_row == b.sizeof_row)
            and (this -> sizeof_column == b.sizeof_column)
            and (this -> sizeof_1st_layer == b.sizeof_1st_layer)
            and (this -> sizeof_2nd_layer == b.sizeof_2nd_layer))
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer, this -> sizeof_2nd_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < sizeof_2nd_layer; n++)
                    {
                        c.user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n] - b.user_4d_array[i][j][m][n];
                    }
                }
            }
        }
        return c;
    }
    else
    {
        return *this;
    }
}
//
//
//
array array::operator*(const double &b)
{
    if(this -> is_1d_array)
    {
        array c(this -> sizeof_row);
        c = *this;
        gsl_vector_scale(c.user_1d_array, b);
        return c;
    }
    if(this -> is_2d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column);
        c = *this;
        gsl_matrix_scale(c.user_2d_array, b);
        return c;
    }
    if(this -> is_3d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    c.user_3d_array[i][j][m] = this -> user_3d_array[i][j][m]*b;
                }
            }
        }
        return c;
    }
    if(this -> is_4d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer, this -> sizeof_2nd_layer);
        c = *this;
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; i++)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; j++)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; m++)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < sizeof_2nd_layer; n++)
                    {
                        c.user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n]*b;
                    }
                }
            }
        }
        return c;
    }
    else
    {
        return *this;
    }
}
//
//
//
array array::operator*(const array &b)
{
    if(this -> is_2d_array and b.is_1d_array and (this -> sizeof_column == b.sizeof_row))
    {
        array c(this -> sizeof_row);
//
        gsl_blas_dgemv((this -> is_transposed? CblasTrans : CblasNoTrans),
                       1.0,
                       this -> user_2d_array,
                       b.user_1d_array,
                       1.0,
                       c.user_1d_array);
//
        return c;
    }
    else if(this -> is_2d_array 
            and b.is_2d_array 
            and (this -> sizeof_row == b.sizeof_row) 
            and (this -> sizeof_column == b.sizeof_column))
    {
        array c(this -> sizeof_row, this -> sizeof_column);
//
        gsl_blas_dgemm((this -> is_transposed? CblasTrans : CblasNoTrans),
                       (b.is_transposed? CblasTrans : CblasNoTrans),
                       1.0,
                       this -> user_2d_array,
                       b.user_2d_array,
                       1.0,
                       c.user_2d_array);
//
        return c;
    }
    else
    {
        return *this;
    }
}
