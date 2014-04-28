#include "array.hpp"
//
//
//
array::array():
	rank1(0),
	rank2(0),
	rank3(0),
	rank4(0),
	data1(NULL),
	data2(NULL),
	data3(NULL),
	data4(NULL),
	constant(false),
	work_space(NULL),
	name("unnamed array"),
	config(&global_settings::config),
	data_id(tools::random_number<unsigned int>())
{
// Empty constructor.
}
//
//
//
array::array(const unsigned int &row_size):
	rank1(row_size),
	rank2(0),
	rank3(0),
	rank4(0),
	data1(NULL),
	data2(NULL),
	data3(NULL),
	data4(NULL),
	constant(false),
	work_space(NULL),
	name("unnamed array"),
	config(&global_settings::config),
	data_id(tools::random_number<unsigned int>())
{
	init_1d_array(row_size);
}
//
//
//
array::array(const unsigned int &row_size,
             const unsigned int &column_size):
	rank1(row_size),
	rank2(column_size),
	rank3(0),
	rank4(0),
	data1(NULL),
	data2(NULL),
	data3(NULL),
	data4(NULL),
	constant(false),
	work_space(NULL),
	name("unnamed array"),
	config(&global_settings::config),
	data_id(tools::random_number<unsigned int>())
{
	init_2d_array(row_size, column_size);
}
//
//
//
array::array(const unsigned int &row_size,
             const unsigned int &column_size,
             const unsigned int &layer_size):
	rank1(row_size),
	rank2(column_size),
	rank3(layer_size),
	rank4(0),
	data1(NULL),
	data2(NULL),
	data3(NULL),
	data4(NULL),
	constant(false),
	work_space(NULL),
	name("unnamed array"),
	config(&global_settings::config),
	data_id(tools::random_number<unsigned int>())
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
	rank1(row_size),
	rank2(column_size),
	rank3(layer1_size),
	rank4(layer2_size),
	data1(NULL),
	data2(NULL),
	data3(NULL),
	data4(NULL),
	constant(false),
	work_space(NULL),
	name("unnamed array"),
	config(&global_settings::config),
	data_id(tools::random_number<unsigned int>())
{
	init_4d_array(row_size, column_size, layer1_size, layer2_size);
}
//
//
//
array::array(const array &input):
	rank1(input.rank1),
	rank2(input.rank2),
	rank3(input.rank3),
	rank4(input.rank4),
	data1(NULL),
	data2(NULL),
	data3(NULL),
	data4(NULL),
	constant(input.constant),
	work_space(NULL),
	name(input.name),
	config(&global_settings::config),
	data_id(tools::random_number<unsigned int>())
{
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			switch(input.is_1d())
			{
				case true:
				init_1d_array(input.rank1);
				copy_1d_arrays(input);
				break;
			}
		}
		#pragma omp section
		{
			switch(input.is_2d())
			{
				case true:
				init_2d_array(input.rank1,
				              input.rank2);
				copy_2d_arrays(input);
				break;
			}
		}
		#pragma omp section
		{
			switch(input.is_3d())
			{
				case true:
				init_3d_array(input.rank1,
				              input.rank2,
				              input.rank3);
				copy_3d_arrays(input);
				break;
			}
		}
		#pragma omp section
		{
			switch(input.is_4d())
			{
				case true:
				init_4d_array(input.rank1,
				              input.rank2,
				              input.rank3,
				              input.rank4);
				copy_4d_arrays(input);
				break;
			}
		}
	}
}
