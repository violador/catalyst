//
//
//
/// @brief If the current array was previously initialized, either by
/// construction or the array::create() member function, array::sort()
/// sorts the current values in some order.
//
/// @return None.
//
inline void sort()
{
	#pragma omp master
	std::sort(data, data_end());
};
