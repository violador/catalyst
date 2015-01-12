//
//
//
/// @brief A private member function to reset all the data members
/// back for the default values. Its usage is highly recommended
/// after any attempt of delete or move operations.
//
/// @return None.
//
/// @warning This member function shall not be invoked before delete
/// operations in those cases of previously successful memory allocation.
/// Otherwise the memory address pointing the begin of the allocated
/// resources will be lost without no way to be deallocated again.
//
#if CURRENT_RANK == 1
	inline void reset_data_members()
	{
		data = NULL; rank1 = 0;
	};
#endif
//
//
//
/// @brief A private member function to reset all the data members
/// back for the default values. Its usage is highly recommended
/// after any attempt of delete or move operations.
//
/// @return None.
//
/// @warning This member function shall not be invoked before delete
/// operations in those cases of previously successful memory allocation.
/// Otherwise the memory address pointing the begin of the allocated
/// resources will be lost without no way to be deallocated again.
//
#if CURRENT_RANK == 2
	inline void reset_data_members()
	{
		data = NULL; rank1 = rank2 = 0;
	};
#endif
//
//
//
/// @brief A private member function to reset all the data members
/// back for the default values. Its usage is highly recommended
/// after any attempt of delete or move operations.
//
/// @return None.
//
/// @warning This member function shall not be invoked before delete
/// operations in those cases of previously successful memory allocation.
/// Otherwise the memory address pointing the begin of the allocated
/// resources will be lost without no way to be deallocated again.
//
#if CURRENT_RANK == 3
	inline void reset_data_members()
	{
		data = NULL; rank1 = rank2 = rank3 = 0;
	};
#endif
//
//
//
/// @brief A private member function to reset all the data members
/// back for the default values. Its usage is highly recommended
/// after any attempt of delete or move operations.
//
/// @return None.
//
/// @warning This member function shall not be invoked before delete
/// operations in those cases of previously successful memory allocation.
/// Otherwise the memory address pointing the begin of the allocated
/// resources will be lost without no way to be deallocated again.
//
#if CURRENT_RANK == 4
	inline void reset_data_members()
	{
		data = NULL; rank1 = rank2 = rank3 = rank4 = 0;
	};
#endif
//
//
//
/// @brief Member specialization for bad initialized objects, with
/// negative or bigger than four number of dimensions. Do nothing.
//
/// @return None.
//
#if CURRENT_RANK <= 0 || CURRENT_RANK > 4
	inline void reset_data_members()
	{
		return;
	};
#endif
