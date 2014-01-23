// ../src/array/array__addition.cpp --------------------------------------------------------- //
//
//  This file is part of Catalyst lib.
//
//  Catalyst lib is free software: you can redistribute it and/or modify it under the terms 
//  of the GNU General Public License as published by the Free Software Foundation, either 
//  version 3 of the License, or (at your option) any later version.
//
//  Catalyst lib is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with Catalyst lib. 
//  If not, see <http://www.gnu.org/licenses/>.
//
// ------------------------------------------------------------------------------------------ //
#include "array.hpp"
//
//
//
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return @f$ A + b @f$, where @f$ A @f$ is an array and @f$ b @f$ is 
///         a @c double type number. 
//
/// @cite gsl
//
array array::operator +(const double &b)
{
//
/// @note Notice that this operator needs to create a temporary object 
///       and also needs to return it by copy (the array @c C itself). 
///       It is a good practice to use the @c += operator instead.
//
    if(this -> is_1d_array)
    {
        array c(this -> sizeof_row);
        gsl_vector_memcpy(&c.gsl_1d_view.vector, 
			  &this -> gsl_1d_view.vector);
        gsl_vector_add_constant(&c.gsl_1d_view.vector, b);
        return c;
    }
    else if(this -> is_2d_array)
    {
        array c(this -> sizeof_row, 
		this -> sizeof_column);
        gsl_matrix_memcpy(&c.gsl_2d_view.matrix, 
			  &this -> gsl_2d_view.matrix);
        gsl_matrix_add_constant(&c.gsl_2d_view.matrix, b);
        return c;
    }
    else if(this -> is_3d_array)
    {
        array c(this -> sizeof_row, 
		this -> sizeof_column, 
		this -> sizeof_1st_layer);
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; ++i)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; ++j)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; ++m)
                {
                    c.user_3d_array[i][j][m] = this -> user_3d_array[i][j][m] 
			                     + b;
                }
            }
        }
        return c;
    }
    else if(this -> is_4d_array)
    {
        array c(this -> sizeof_row, 
		this -> sizeof_column, 
		this -> sizeof_1st_layer, 
		this -> sizeof_2nd_layer);
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; ++i)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; ++j)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; ++m)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < sizeof_2nd_layer; ++n)
                    {
                        c.user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n] 
				                    + b;
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
/// @author Humberto Jr.
//
/// @date 07/2013
//
/// @return @f$ A + B @f$, where @f$ A @f$ and @f$ B @f$ are arrays. 
///         The operation is valid only if the size of all dimensions 
///         fits each other.
//
/// @cite gsl
//
array array::operator +(const array &b)
{
//
/// @note Notice that this operator needs to create a temporary object 
///       and also needs to return it by copy (the array @c C itself). 
///       It is a good practice to use the @c += operator instead.
//
    if(this -> is_1d_array
       and b.is_1d_array
       and (this -> sizeof_row == b.sizeof_row))
    {
        array c(b.sizeof_row);
        gsl_vector_memcpy(&c.gsl_1d_view.vector, 
			  &this -> gsl_1d_view.vector);
        cblas_daxpy(this -> sizeof_row,
                    1.0,
                    b.user_1d_array,
                    1,
                    c.user_1d_array,
                    1);
        return c;
    }
    else if(this -> is_2d_array
            and b.is_2d_array
            and (this -> sizeof_row == b.sizeof_row)
            and (this -> sizeof_column == b.sizeof_column))
    {
        array c(b.sizeof_row, 
		b.sizeof_column);
        gsl_matrix_memcpy(&c.gsl_2d_view.matrix, 
			  &this -> gsl_2d_view.matrix);
        cblas_daxpy((b.sizeof_row)*(b.sizeof_column),
                    1.0,
                    b.user_2d_array,
                    1,
                    c.user_2d_array,
                    1);
        return c;
    }
    else if(this -> is_3d_array
            and b.is_3d_array
            and (this -> sizeof_row == b.sizeof_row)
            and (this -> sizeof_column == b.sizeof_column)
            and (this -> sizeof_1st_layer == b.sizeof_1st_layer))
    {
        array c(this -> sizeof_row, 
		this -> sizeof_column, 
		this -> sizeof_1st_layer);
        unsigned int i = 0
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < sizeof_row; ++i)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < sizeof_column; ++j)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < sizeof_1st_layer; ++m)
                {
                    c.user_3d_array[i][j][m] = this -> user_3d_array[i][j][m] 
                                             + b.user_3d_array[i][j][m];
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
        array c(this -> sizeof_row, 
                this -> sizeof_column, 
                this -> sizeof_1st_layer, 
                this -> sizeof_2nd_layer);
        unsigned int i = 0;
        #pragma omp parallel for private(i) ordered schedule(dynamic)
        for(i = 0; i < this -> sizeof_row; ++i)
        {
            unsigned int j = 0;
            #pragma omp parallel for private(j) ordered schedule(dynamic)
            for(j = 0; j < this -> sizeof_column; ++j)
            {
                unsigned int m = 0;
                #pragma omp parallel for private(m) ordered schedule(dynamic)
                for(m = 0; m < this -> sizeof_1st_layer; ++m)
                {
                    unsigned int n = 0;
                    #pragma omp parallel for private(n) ordered schedule(dynamic)
                    for(n = 0; n < this -> sizeof_2nd_layer; ++n)
                    {
                        c.user_4d_array[i][j][m][n] = this -> user_4d_array[i][j][m][n] 
                                                    + b.user_4d_array[i][j][m][n];
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
