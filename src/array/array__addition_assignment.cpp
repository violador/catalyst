#include "array.hpp"
//
//
//
void array::operator +=(const array &b)
{
//
//  Given the arrays A (the this pointer) and B: A = A + B
//
	#pragma omp sections
	{
		#pragma omp section
		{
			switch(this -> is_1d_array                      // To check the A array type.
				   and b.is_1d_array                        // To check the B array type.
				   and (this -> sizeof_row == b.sizeof_row) // To check if the A row size fits the B row size.
				   and (not this -> is_const_array)         // To check if A has permision to be rewritten.
				   and (not this -> deleted_array))         // To check if A is not a deleted array.
			{
				case true:
				cblas_daxpy(this -> sizeof_row,
							1.0,
							b.user_1d_array,
							1,
							this -> user_1d_array,
							1);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_2d_array                            // To check the A array type.
				   and b.is_2d_array                              // To check the B array type.
				   and (this -> sizeof_row == b.sizeof_row)       // To check if the A row size fits the B row size.
				   and (this -> sizeof_column == b.sizeof_column) // To check if the A column size fits the B column size.
				   and (not this -> is_const_array)               // To check if A has permision to be rewritten.
				   and (not this -> deleted_array))               // To check if A is not a deleted array.
			{
				case true:
				cblas_daxpy((this -> sizeof_row)*(this -> sizeof_column),
							1.0,
							b.user_2d_array,
							1,
							this -> user_2d_array,
							1);
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_3d_array                                  // To check the A array type.
				   and b.is_3d_array                                    // To check the B array type.
				   and (this -> sizeof_row == b.sizeof_row)             // To check if A row size fits the B row size.
				   and (this -> sizeof_column == b.sizeof_column)       // To check if A column size fits the B column size.
				   and (this -> sizeof_1st_layer == b.sizeof_1st_layer) // To check if A first layer size fits the B first layer size.
				   and (not this -> is_const_array)                     // To check if A has permision to be rewritten.
				   and (not this -> deleted_array))                     // To check if A is not a deleted array.
			{
				case true:
				unsigned int i = 0, j = 0, m = 0;
				#pragma omp parallel for private(i) ordered schedule(dynamic)
				for(i = 0; i < this -> sizeof_row; ++i)
				{
					#pragma omp parallel for private(j) ordered schedule(dynamic)
					for(j = 0; j < this -> sizeof_column; ++j)
					{
						#pragma omp parallel for private(m) ordered schedule(dynamic)
						for(m = 0; m < this -> sizeof_1st_layer; ++m)
						{
							this -> user_3d_array[i][j][m] += b.user_3d_array[i][j][m];
						}
					}
				}
				break;
			}
		}
		#pragma omp section
		{
			switch(this -> is_4d_array                                  // To check the A array type.
				   and b.is_4d_array                                    // To check the B array type.
				   and (this -> sizeof_row == b.sizeof_row)             // To check if A row size fits the B row size.
				   and (this -> sizeof_column == b.sizeof_column)       // To check if A column size fits the B column size.
				   and (this -> sizeof_1st_layer == b.sizeof_1st_layer) // To check if A first layer size fits the B first layer size.
				   and (this -> sizeof_2nd_layer == b.sizeof_2nd_layer) // To check if A second layer size fits the B second layer size.
				   and (not this -> is_const_array)                     // To check if A has permision to be rewritten.
				   and (not this -> deleted_array))                     // To check if A is not a deleted array.
			{
				case true:
				unsigned int i = 0, j = 0, m = 0, n = 0;
				#pragma omp parallel for private(i) ordered schedule(dynamic)
				for(i = 0; i < this -> sizeof_row; ++i)
				{
					#pragma omp parallel for private(j) ordered schedule(dynamic)
					for(j = 0; j < this -> sizeof_column; ++j)
					{
						#pragma omp parallel for private(m) ordered schedule(dynamic)
						for(m = 0; m < this -> sizeof_1st_layer; ++m)
						{
							#pragma omp parallel for private(n) ordered schedule(dynamic)
							for(n = 0; n < this -> sizeof_2nd_layer; ++n)
							{
								this -> user_4d_array[i][j][m][n] += b.user_4d_array[i][j][m][n];
							}
						}
					}
				}
				break;
			}
		}
	} // pragma omp parallel sections num_threads(4)
}
