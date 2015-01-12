//
//
//
/// @brief A private member function to allocate memory for arrays of any
/// rank order. Its behavior is driven by the array::data_length() member
/// function and thus by the current values of @c rank1, @c rank2, @c rank3
/// and @c rank4 data members. If the data length is null nothing is done.
/// The operation is carried out by the master thread only.
//
/// @return @c true if the memory was allocated properly, and @c false
/// otherwise.
//
inline bool init_data()
{
	#pragma omp master
	if(data_length() > 0)
	{
		data = new (std::nothrow) data_type[data_length()]();
	}
	return is_ready();
};
