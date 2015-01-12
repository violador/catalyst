//
//
//
/// @brief A private member function used to check the internal
/// real length of the current array.
//
/// @return A non-negative integer.
//
#if CURRENT_RANK == 1
	constexpr unsigned int data_length() const
	{
		return rank1;
	};
#endif
//
//
//
/// @brief A private member function used to check the internal
/// real length of the current array.
//
/// @return A non-negative integer.
//
#if CURRENT_RANK == 2
	constexpr unsigned int data_length() const
	{
		return rank1*rank2;
	};
#endif
//
//
//
/// @brief A private member function used to check the internal
/// real length of the current array.
//
/// @return A non-negative integer.
//
#if CURRENT_RANK == 3
	constexpr unsigned int data_length() const
	{
		return rank1*rank2*rank3;
	};
#endif
//
//
//
/// @brief A private member function used to check the internal
/// real length of the current array.
//
/// @return A non-negative integer.
//
#if CURRENT_RANK == 4
	constexpr unsigned int data_length() const
	{
		return rank1*rank2*rank3*rank4;
	};
#endif
//
//
//
/// @brief Member specialization for bad initialized objects,
/// with negative or bigger than four number of dimensions.
//
/// @return Zero.
//
#if CURRENT_RANK <= 0 || CURRENT_RANK > 4
	constexpr unsigned int data_length() const
	{
		return 0;
	};
#endif
