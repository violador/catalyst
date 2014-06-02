//
//
//
inline void copy_1d_arrays(array<data_type, 1> &output,
                           const array<data_type, 1> &input)
{
	switch(output.rank1 >= input.rank1)
	{
		case false:
		{
			output.delete_1d_array();
			switch(output.init_1d_array(input.rank1))
			{
				case EXIT_SUCCESS:
				std::copy(input.data, input.data + input.rank1, output.data);
			}
			return;
		}
		case true:
		{
			std::copy(input.data, input.data + input.rank1, output.data);
			return;
		}
	}
};
