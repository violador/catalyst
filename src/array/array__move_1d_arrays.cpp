//
//
//
int move_1d_arrays(array<data_type, 1> &output,
                   array<data_type, 1> &input)
{
	switch(input.rank1 == output.rank1)
	{
		case false:
		{
			output.delete_1d_array();
			switch(output.init_1d_array(input.rank1))
			{
				case EXIT_FAILURE:
				{
					return EXIT_FAILURE;
				}
				case EXIT_SUCCESS:
				{
					std::move(input.data, input.data + input.rank1, output.data);
					input.delete_1d_array();
					return EXIT_SUCCESS;
				}
			}
		}
		case true:
		{
			std::move(input.data, input.data + input.rank1, output.data);
			input.delete_1d_array();
			return EXIT_SUCCESS;
		}
	}
}
