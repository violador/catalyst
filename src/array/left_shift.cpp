//
//
//
/// @param [in] input A previously declared array with the same rank order.
//
/// @brief The operator @c << applied between two array objects is used to
/// move the content from the one at right-hand to the one at left-hand.
/// The operation is independent of any previous initialization and
/// therefore can be used to initialize the array at left and to clear the
/// one at right. The operation is carried out by the master thread only.
//
/// @return None.
//
/// @note Please notice that if given an uninitialized array at right-hand,
/// the content at left-hand, if any, will be lost and its object will
/// assume an uninitialized state.
//
void operator <<(array_type &input)
{
	#pragma omp master
	{
		delete[] data;
		copy_data_members(input);
		input.reset_data_members();
	}
};
