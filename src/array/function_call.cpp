//
//
//
/// @param [in] i The @c i element of the first rank in a rank one array.
//
/// @brief The operator @c ( ) gives access to set or to get the current
/// value in the given element. It does not check if the element lies in
/// the valid range and any attempt to write or to read out from it may
/// imply segmentation fault or any out of range standard C++ error.
//
/// @return The memory address of the given element.
//
/// @warning This member is not thread safe. The caller must ensure that
/// each thread invoking this function does not affect the others. Barriers,
/// critical and atomic operations can be used for safeness purpose.
//
#if CURRENT_RANK == 1
	constexpr data_type &operator ()(unsigned int i) const
	{
		return data[offset(i)];
	};
#endif
//
//
//
/// @param [in] i The @c i element in the first rank of a rank two array.
//
/// @param [in] j The @c j element in the second rank of a rank two array.
//
/// @brief The operator @c ( ) gives access to set or to get the current value
///        in the given element. It does not check if the element lies in the
///        valid range and any attempt to write or to read out from it may
///        imply segmentation fault or any out of range standard C++ error.
//
/// @return The memory address of the given element.
//
/// @warning This member is not thread safe. The caller must ensure that each
///          thread invoking this function does not affect the others. Barriers,
///          critical and atomic operations can be used for safeness purpose.
//
#if CURRENT_RANK == 2
	constexpr data_type &operator ()(unsigned int i, unsigned int j) const
	{
		return data[offset(i, j)];
	};
#endif
