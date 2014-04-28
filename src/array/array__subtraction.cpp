#include "array.hpp"
//
//
//
array array::operator -(const double &b)
{
//
//  Given the arrays A (the this pointer), C and the number B: C = A - B
//
    if(this -> is_1d())
    {
        array c(this -> rank1);
        gsl_vector_memcpy(&c.gsl_1d_view.vector, &this -> gsl_1d_view.vector);
//
        gsl_vector_add_constant(&c.gsl_1d_view.vector, -b);
//
        return c;
    }
    if(this -> is_2d())
    {
        array c(this -> rank1, this -> rank2);
        gsl_matrix_memcpy(&c.gsl_2d_view.matrix, &this -> gsl_2d_view.matrix);
//
        gsl_matrix_add_constant(&c.gsl_2d_view.matrix, -b);
//
        return c;
    }
    if(this -> is_3d())
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
                    c.data3[i][j][m] = this -> data3[i][j][m] - b;
                }
            }
        }
//
        return c;
    }
    if(this -> is_4d())
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
                        c.data4[i][j][m][n] = this -> data4[i][j][m][n] - b;
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
array array::operator -(const array &b)
{
//
//  Given the arrays A (the this pointer), B and C: C = A - B
//
    if(this -> is_1d()
       and b.is_1d()
       and (this -> rank1 == b.rank1))
    {
        array c(this -> rank1);
        gsl_vector_memcpy(&c.gsl_1d_view.vector, &this -> gsl_1d_view.vector);
//
        cblas_daxpy(this -> rank1,
                    -1.0,
                    b.data1,
                    1,
                    c.data1,
                    1);
//
        return c;
    }
    else if(this -> is_2d()
            and b.is_2d()
            and (this -> rank1 == b.rank1)
            and (this -> rank2 == b.rank2))
    {
        array c(this -> rank1, this -> rank2);
        gsl_matrix_memcpy(&c.gsl_2d_view.matrix, &this -> gsl_2d_view.matrix);
//
        cblas_daxpy((this -> rank1)*(this -> rank2),
                    -1.0,
                    b.data2,
                    1,
                    c.data2,
                    1);
//
        return c;
    }
    else if(this -> is_3d()
            and b.is_3d()
            and (this -> rank1 == b.rank1)
            and (this -> rank2 == b.rank2)
            and (this -> rank3 == b.rank3))
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
                    c.data3[i][j][m] = this -> data3[i][j][m] - b.data3[i][j][m];
                }
            }
        }
//
        return c;
    }
    else if(this -> is_4d()
            and b.is_4d()
            and (this -> rank1 == b.rank1)
            and (this -> rank2 == b.rank2)
            and (this -> rank3 == b.rank3)
            and (this -> rank4 == b.rank4))
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
                        c.data4[i][j][m][n] = this -> data4[i][j][m][n]
                                                    - b.data4[i][j][m][n];
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
