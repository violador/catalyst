//
//
//
/// @brief Build its identity form, if the current rank two array is square and
/// was previously initialized either by construction or the array::create()
/// member function. Otherwise nothing is done. Notice that the previous content,
/// if any, will be lost.
//
/// @return None.
//
void build_identity_form()
{
	if(is_square())
	{
		OMP_STATIC_LOOP_POLICY
		for(INIT_ITER(i, 1); i < first_rank(); ++i)
		{
			data[offset(i, i)] = data_type(1.0);
			for(unsigned int j(i + 1); j <= second_rank(); ++j)
			{
				data[offset(i, j)] = data[offset(j, i)] = data_type(0.0);
			}
		}
		data[data_length() - 1] = data_type(1.0);
	}
};
