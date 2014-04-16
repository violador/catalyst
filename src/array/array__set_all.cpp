//
//
//
/// @param [in] value A real number.
//
/// @brief Sets the given value into all the elements if the
///        current object is not a deleted or constant array.
//
/// @return None.
//
inline void set_all(const double &value)
{
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			set_all_1d_elements(value);
		}
		#pragma omp section
		{
			set_all_2d_elements(value);
		}
		#pragma omp section
		{
			set_all_3d_elements(value);
		}
		#pragma omp section
		{
			set_all_4d_elements(value);
		}
	}
};
