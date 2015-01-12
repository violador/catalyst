//
//
//
/// @param [in] input A numerical data of the same type of the array.
//
/// @brief If the current rank two array is square and was previously
/// initialized either by construction or the array::create() member
/// function, array::set_diagonal() is used to fill up the diagonal
/// elements. Notice that the previous content in the diagonal
/// elements, if any, will be lost.
//
/// @return None.
//
void set_diagonal(data_type input)
{
	if(is_square())
	{
		OMP_STATIC_LOOP_POLICY
		for(INIT_ITER(i, 1); i <= first_rank(); ++i)
		{
			data[offset(i, i)] = input;
		}
	}
};
