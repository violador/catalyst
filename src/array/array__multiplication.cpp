#include "array.hpp"
//
//
//
array array::operator *(const double &b)
{
//
// Given the arrays A (the this pointer), C and the number B: C = A*B
//
    if(this -> is_1d_array)
    {
        array c(this -> sizeof_row);
        gsl_vector_memcpy(&c.gsl_1d_view.vector, &this -> gsl_1d_view.vector);
//
        cblas_dscal(this -> sizeof_row, 
                    b, 
                    c.user_1d_array, 
                    1);
//
        return c;
    }
    else if(this -> is_2d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column);
        gsl_matrix_memcpy(&c.gsl_2d_view.matrix, &this -> gsl_2d_view.matrix);
//
        cblas_dscal((this -> sizeof_row)*(this -> sizeof_column),
                    b,
                    c.user_2d_array,
                    1);
//
        return c;
    }
    else if(this -> is_3d_array)
    {
        array c(this -> sizeof_row, this -> sizeof_column, this -> sizeof_1st_layer);
//
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
                    c.user_3d_array[i][j][m] = this -> user_3d_array[i][j][m]*b;
                }
            }
        }
//
        return c;
    }
    else if(this -> is_4d_array)
    {
        array c(this -> sizeof_row, 
                this -> sizeof_column, 
                this -> sizeof_1st_layer, 
                this -> sizeof_2nd_layer);
//
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
                        c.user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n]*b;
                    }
                }
            }
        }
//
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
array array::operator *(const array &b)
{
    if(this -> is_2d_array                          // To check the A array type.
       and b.is_1d_array                            // To check the B array type.
       and (this -> sizeof_column == b.sizeof_row)) // To check if the
    {
        array c(this -> sizeof_row, 1);
//
        cblas_dgemv(CblasRowMajor,
                    CblasNoTrans,
                    this -> sizeof_row,
                    this -> sizeof_column,
                    1.0,
                    this -> user_2d_array,
                    1,
                    b.user_1d_array,
                    1,
                    1.0,
                    c.user_2d_array,
                    1);
//
        return c;
    }
    else if(this -> is_2d_array                          // To check the A array type.
            and b.is_2d_array                            // To check the B array type.
            and (this -> sizeof_column == b.sizeof_row)) // To check if the A column size fits the B row size.
    {
        array c(this -> sizeof_row, b.sizeof_column);
//
        cblas_dgemm(CblasRowMajor,
                    CblasNoTrans,
                    CblasNoTrans,
                    this -> sizeof_row,
                    b.sizeof_column,
                    this -> sizeof_column,
                    1.0,
                    this -> user_2d_array,
                    this -> sizeof_column,
                    b.user_2d_array,
                    b.sizeof_column,
                    1.0,
                    c.user_2d_array,
                    this -> sizeof_column);
//
        return c;
    }
    else
    {
        return *this;
    }
}
