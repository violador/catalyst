//
//
//
/// @brief A private member function to deallocate the current memory
/// and to clean the data members. The operation is carried out by the
/// master thread only.
//
/// @return None.
//
inline void delete_data()
{
	#pragma omp master
	{
		delete[] data;
		reset_data_members();
	}
};
