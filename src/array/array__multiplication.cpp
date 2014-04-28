#include "array.hpp"
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return
//
/// @cite gsl
//
array array::operator *(const double &b)
{
//
// Given the arrays A (the this pointer), C and the number B: C = A*B
//
    if(this -> is_1d())
    {
        array c(this -> rank1);
        gsl_vector_memcpy(&c.gsl_1d_view.vector, &this -> gsl_1d_view.vector);
//
        cblas_dscal(this -> rank1,
                    b,
                    c.data1,
                    1);
//
        return c;
    }
    else if(this -> is_2d())
    {
        array c(this -> rank1, this -> rank2);
        gsl_matrix_memcpy(&c.gsl_2d_view.matrix, &this -> gsl_2d_view.matrix);
//
        cblas_dscal((this -> rank1)*(this -> rank2),
                    b,
                    c.data2,
                    1);
//
        return c;
    }
    else if(this -> is_3d())
    {
        array c(this -> rank1, this -> rank2, this -> rank3);
//
        unsigned int i = 0, j = 0, m = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < this -> rank1; i++)
        {
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < this -> rank2; j++)
            {
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < this -> rank3; m++)
                {
                    c.data3[i][j][m] = this -> data3[i][j][m]*b;
                }
            }
        }
//
        return c;
    }
    else if(this -> is_4d())
    {
        array c(this -> rank1,
                this -> rank2,
                this -> rank3,
                this -> rank4);
//
        unsigned int i = 0, j = 0, m = 0, n = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < this -> rank1; i++)
        {
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < this -> rank2; j++)
            {
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < this -> rank3; m++)
                {
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < this -> rank4; n++)
                    {
                        c.data4[i][j][m][n] = this -> data4[i][j][m][n]*b;
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
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return
//
/// @cite gsl
//
array array::operator *(const array &b)
{
    if(this -> is_2d()                          // To check the A array type.
       and b.is_1d()                            // To check the B array type.
       and (this -> rank2 == b.rank1)) // To check if the A column size fits the B row size.
    {
        array c(this -> rank1, 1);
//
        cblas_dgemv(CblasRowMajor,
                    CblasNoTrans,
                    this -> rank1,
                    this -> rank2,
                    1.0,
                    this -> data2,
                    1,
                    b.data1,
                    1,
                    1.0,
                    c.data2,
                    1);
//
        return c;
    }
    else if(this -> is_2d()                          // To check the A array type.
            and b.is_2d()                            // To check the B array type.
            and (this -> rank2 == b.rank1)) // To check if the A column size fits the B row size.
    {
        array c(this -> rank1, b.rank2);
//
        cblas_dgemm(CblasRowMajor,
                    CblasNoTrans,
                    CblasNoTrans,
                    this -> rank1,
                    b.rank2,
                    this -> rank2,
                    1.0,
                    this -> data2,
                    this -> rank2,
                    b.data2,
                    b.rank2,
                    1.0,
                    c.data2,
                    this -> rank2);
//
        return c;
    }
    else
    {
        return *this;
    }
}
