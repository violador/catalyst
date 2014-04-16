#include "array.hpp"
//
//
//
array::array():
sizeof_row(0),
sizeof_column(0),
sizeof_1st_layer(0),
sizeof_2nd_layer(0),
array_id(tools::random_number<unsigned int>()),
is_1d_array(false),
is_2d_array(false),
is_3d_array(false),
is_4d_array(false),
is_const_array(false),
is_square_array(false),
is_transposed(false),
deleted_array(true),
user_1d_array(NULL),
user_2d_array(NULL),
user_3d_array(NULL),
user_4d_array(NULL),
array_name(DEFAULT_ARRAY_NAME),
config(&global_settings::config)
{
// Empty constructor.
}
//
//
//
array::array(const unsigned int &row_size):
sizeof_row(row_size),
sizeof_column(0),
sizeof_1st_layer(0),
sizeof_2nd_layer(0),
array_id(tools::random_number<unsigned int>()),
is_1d_array(true),
is_2d_array(false),
is_3d_array(false),
is_4d_array(false),
is_const_array(false),
is_square_array(false),
is_transposed(false),
deleted_array(false),
user_1d_array(NULL),
user_2d_array(NULL),
user_3d_array(NULL),
user_4d_array(NULL),
array_name(DEFAULT_ARRAY_NAME),
config(&global_settings::config)
{
	init_1d_array(row_size);
}
//
//
//
array::array(const unsigned int &row_size,
             const unsigned int &column_size):
sizeof_row(row_size),
sizeof_column(column_size),
sizeof_1st_layer(0),
sizeof_2nd_layer(0),
array_id(tools::random_number<unsigned int>()),
is_1d_array(false),
is_2d_array(true),
is_3d_array(false),
is_4d_array(false),
is_const_array(false),
is_square_array(row_size == column_size? true : false),
is_transposed(false),
deleted_array(false),
user_1d_array(NULL),
user_2d_array(NULL),
user_3d_array(NULL),
user_4d_array(NULL),
array_name(DEFAULT_ARRAY_NAME),
config(&global_settings::config)
{
	init_2d_array(row_size, column_size);
}
//
//
//
array::array(const unsigned int &row_size,
             const unsigned int &column_size,
             const unsigned int &layer_size):
sizeof_row(row_size),
sizeof_column(column_size),
sizeof_1st_layer(layer_size),
sizeof_2nd_layer(0),
array_id(tools::random_number<unsigned int>()),
is_1d_array(false),
is_2d_array(false),
is_3d_array(true),
is_4d_array(false),
is_const_array(false),
is_square_array(false),
is_transposed(false),
deleted_array(false),
user_1d_array(NULL),
user_2d_array(NULL),
user_3d_array(NULL),
user_4d_array(NULL),
array_name(DEFAULT_ARRAY_NAME),
config(&global_settings::config)
{
	init_3d_array(row_size, column_size, layer_size);
}
//
//
//
array::array(const unsigned int &row_size,
             const unsigned int &column_size,
             const unsigned int &layer1_size,
             const unsigned int &layer2_size):
sizeof_row(row_size),
sizeof_column(column_size),
sizeof_1st_layer(layer1_size),
sizeof_2nd_layer(layer2_size),
array_id(tools::random_number<unsigned int>()),
is_1d_array(false),
is_2d_array(false),
is_3d_array(false),
is_4d_array(true),
is_const_array(false),
is_square_array(false),
is_transposed(false),
deleted_array(false),
user_1d_array(NULL),
user_2d_array(NULL),
user_3d_array(NULL),
user_4d_array(NULL),
array_name(DEFAULT_ARRAY_NAME),
config(&global_settings::config)
{
	init_4d_array(row_size, column_size, layer1_size, layer2_size);
}
//
//
//
array::array(const array &given):
sizeof_row(given.sizeof_row),
sizeof_column(given.sizeof_column),
sizeof_1st_layer(given.sizeof_1st_layer),
sizeof_2nd_layer(given.sizeof_2nd_layer),
array_id(tools::random_number<unsigned int>()),
is_1d_array(given.is_1d_array),
is_2d_array(given.is_2d_array),
is_3d_array(given.is_3d_array),
is_4d_array(given.is_4d_array),
is_const_array(given.is_const_array),
is_square_array(given.is_square_array),
is_transposed(given.is_transposed),
deleted_array(given.deleted_array),
user_1d_array(NULL),
user_2d_array(NULL),
user_3d_array(NULL),
user_4d_array(NULL),
array_name(given.array_name),
config(&global_settings::config)
{
	#pragma omp parallel sections num_threads(4)
	{
		#pragma omp section
		{
			switch(given.is_1d_array)
			{
				case true:
				init_1d_array(given.sizeof_row);
				gsl_vector_memcpy(&this -> gsl_1d_view.vector,
								  &given.gsl_1d_view.vector);
				break;
			}
		}
		#pragma omp section
		{
			switch(given.is_2d_array)
			{
				case true:
				init_2d_array(given.sizeof_row, given.sizeof_column);
				gsl_matrix_memcpy(&this -> gsl_2d_view.matrix,
								  &given.gsl_2d_view.matrix);
				break;
			}
		}
		#pragma omp section
		{
			switch(given.is_3d_array)
			{
				case true:
				init_3d_array(given.sizeof_row,
							  given.sizeof_column,
							  given.sizeof_1st_layer);
				unsigned int i = 0, j = 0, m = 0;
				#pragma omp parallel for private(i) ordered schedule(dynamic)
				for(i = 0; i < given.sizeof_row; ++i)
				{
					#pragma omp parallel for private(j) ordered schedule(dynamic)
					for(j = 0; j < given.sizeof_column; ++j)
					{
						#pragma omp parallel for private(m) ordered schedule(dynamic)
						for(m = 0; m < given.sizeof_1st_layer; ++m)
						{
							this -> user_3d_array[i][j][m] = given.user_3d_array[i][j][m];
						}
					}
				}
				break;
			}
		}
		#pragma omp section
		{
			switch(given.is_4d_array)
			{
				case true:
				init_4d_array(given.sizeof_row,
							  given.sizeof_column,
							  given.sizeof_1st_layer,
							  given.sizeof_2nd_layer);
				unsigned int i = 0, j = 0, m = 0, n = 0;
				#pragma omp parallel for private(i) ordered schedule(dynamic)
				for(i = 0; i < given.sizeof_row; ++i)
				{
					#pragma omp parallel for private(j) ordered schedule(dynamic)
					for(j = 0; j < given.sizeof_column; ++j)
					{
						#pragma omp parallel for private(m) ordered schedule(dynamic)
						for(m = 0; m < given.sizeof_1st_layer; ++m)
						{
							#pragma omp parallel for private(n) ordered schedule(dynamic)
							for(n = 0; n < given.sizeof_2nd_layer; ++n)
							{
								this -> user_4d_array[i][j][m][n] = given.user_4d_array[i][j][m][n];
							}
						}
					}
				}
				break;
			}
		}
	} // #pragma omp parallel sections num_threads(4)
}
