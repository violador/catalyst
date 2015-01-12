//
//
//
/// @param [in] input An array of the same rank order.
//
/// @brief A private member function to copy all the data members
/// from the given array to the current one.
//
/// @return None.
//
/// @warning Delete operations over the @c data member shall not
/// be done just after invoke this member function since both @c
/// data pointers are pointing for the same memory address. Thus
/// both objects will lost the content. The same warn concerning
/// the destructor should be taken in account. If the delete was
/// done in one object, any attempt to do the same in the second
/// one will generate the standard C++ error of double deletion
/// of resources.
//
#if CURRENT_RANK == 1
	inline void copy_data_members(const array<data_type, 1> &input)
	{
		data  = input.data;
		rank1 = input.rank1;
	};
#endif
//
//
//
/// @param [in] input An array of the same rank order.
//
/// @brief A private member function to copy all the data members
/// from the given array to the current one.
//
/// @return None.
//
/// @warning Delete operations over the @c data member shall not
/// be done just after invoke this member function since both @c
/// data pointers are pointing for the same memory address. Thus
/// both objects will lost the content. The same warn concerning
/// the destructor should be taken in account. If the delete was
/// done in one object, any attempt to do the same in the second
/// one will generate the standard C++ error of double deletion
/// of resources.
//
#if CURRENT_RANK == 2
	inline void copy_data_members(const array_type &input)
	{
		data  = input.data;
		rank1 = input.rank1;
		rank2 = input.rank2;
	};
#endif
//
//
//
/// @param [in] input An array of the same rank order.
//
/// @brief A private member function to copy all the data members
/// from the given array to the current one.
//
/// @return None.
//
/// @warning Delete operations over the @c data member shall not
/// be done just after invoke this member function since both @c
/// data pointers are pointing for the same memory address. Thus
/// both objects will lost the content. The same warn concerning
/// the destructor should be taken in account. If the delete was
/// done in one object, any attempt to do the same in the second
/// one will generate the standard C++ error of double deletion
/// of resources.
//
#if CURRENT_RANK == 3
	inline void copy_data_members(const array_type &input)
	{
		data  = input.data;
		rank1 = input.rank1;
		rank2 = input.rank2;
		rank3 = input.rank3;
	};
#endif
//
//
//
/// @param [in] input An array of the same rank order.
//
/// @brief A private member function to copy all the data members
/// from the given array to the current one.
//
/// @return None.
//
/// @warning Delete operations over the @c data member shall not
/// be done just after invoke this member function since both @c
/// data pointers are pointing for the same memory address. Thus
/// both objects will lost the content. The same warn concerning
/// the destructor should be taken in account. If the delete was
/// done in one object, any attempt to do the same in the second
/// one will generate the standard C++ error of double deletion
/// of resources.
//
#if CURRENT_RANK == 4
	inline void copy_data_members(const array_type &input)
	{
		data  = input.data;
		rank1 = input.rank1;
		rank2 = input.rank2;
		rank3 = input.rank3;
		rank4 = input.rank4;
	};
#endif
//
//
//
/// @param [in] input An array of the same rank order.
//
/// @brief Member specialization for bad initialized objects, with
/// negative or bigger than four number of dimensions. Do nothing.
//
/// @return None.
//
#if CURRENT_RANK <= 0 || CURRENT_RANK > 4
	inline void copy_data_members(const array_type &input)
	{
		return;
	};
#endif
