//
//
//
/// @param [in] input A previously initialized array with the same rank order.
//
/// @brief The operator @c - applied between two arrays of same rank, subtracts
/// each element and returns the resulting array by move assignment or move
/// construction. Only if both arrays were previously initialized either by
/// construction or the array::create() member function. Otherwise nothing is
/// done.
//
/// @return An array with the same rank order.
//
#if CURRENT_RANK == 1
	double operator *(const array_type &input)
	{
		if(is_ready() && first_rank() == input.first_rank())
		{
			return cblas_dsdot(first_rank(), data, 1, input.data, 1);
		}
		else
		{
			return double(0.0);
		}
	};
#endif
//
//
//
#if CURRENT_RANK == 2
	array_type operator *(const array_type &input)
	{
		array_type output;
		if(is_ready() && second_rank() == input.first_rank())
		{
			output.create(first_rank(), input.second_rank());
			cblas_dgemm(CblasRowMajor,
			            CblasNoTrans,
			            CblasNoTrans,
			            first_rank(),
			            input.second_rank(),
			            second_rank(),
			            1.0,
			            data,
			            second_rank(),
			            input.data,
			            input.second_rank(),
			            1.0,
			            output.data,
			            output.second_rank());
		}
		return output;
	};
#endif
//
//
//
/// @param [in] input A previously initialized array with the same rank order.
//
/// @brief The operator @c -= applied between two arrays of same rank, subtracts
/// each element. Only if both arrays were previously initialized either by
/// construction or the array::create() member function. Otherwise nothing is done.
//
/// @return None.
//
#if CURRENT_RANK == 2
	void operator *=(const array_type &input)
	{
		if(is_ready() && second_rank() == input.first_rank())
		{
			array_type buffer = std::move(*this);
			create(buffer.first_rank(), input.second_rank());
			cblas_dgemm(CblasRowMajor,
			            CblasNoTrans,
			            CblasNoTrans,
			            buffer.first_rank(),
			            input.second_rank(),
			            buffer.second_rank(),
			            1.0,
			            buffer.data,
			            buffer.second_rank(),
			            input.data,
			            input.second_rank(),
			            1.0,
			            data,
			            second_rank());
		}
	};
#endif
//
//
//
/// @param [in] input A numerical data of the same type of the array.
//
/// @brief The operator @c - applied between an array and a number (of the
/// same data type), subtracts the number from each element and returns the resulting
/// array by move assignment or move construction. Only if the array was previously
/// initialized either by construction or the array::create() member function.
/// Otherwise nothing is done.
//
/// @return An array with the same rank order.
//
array_type operator *(data_type input)
{
	array_type output;
	output.init_as(this);
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < output.data_length(); ++i)
	{
		output.data[i] = data[i]*input;
	}
	return output;
};
//
//
//
/// @param [in] input A numerical data of the same type of the array.
//
/// @brief The operator @c -= applied between an array and a number (of the
/// same data type), subtracts the number from each element. Only if the array was
/// previously initialized either by construction or the array::create() member
/// function. Otherwise nothing is done.
//
/// @return None.
//
inline void operator *=(data_type input)
{
	OMP_STATIC_LOOP_POLICY
	for(INIT_ITER(i, 0); i < data_length(); ++i)
	{
		data[i] *= input;
	}
};
