//
//
//
/// @param [in] i The array element.
//
/// @param [in] input The element new value.
//
/// @brief Sets the given @c input in the @f$ A_{i} @f$ element, checking if it is
/// inside the array length. To avoid the bounds check-in, the operator @c () can
/// be uesd instead.
//
/// @return None.
//
#if CURRENT_RANK == 1
	void set(unsigned int i, data_type input)
	{
		#pragma omp master
		if(offset(i) < data_length())
		{
			data[offset(i)] = input;
		}
	};
#endif
