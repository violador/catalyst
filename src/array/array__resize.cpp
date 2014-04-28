//
//
//
inline void resize(const unsigned int &given_row)
{
	switch(rank1 == given_row)
	{
		case true: return;
	}
	delete_array();
	init_1d_array(given_row);
	rank1 = given_row;
};
//
//
//
inline void resize(const unsigned int &given_row,
                   const unsigned int &given_column)
{
	switch(rank1 == given_row
	       && rank2 == given_column)
	{
		case true: return;
	}
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			delete_array();
			init_2d_array(given_row,
			              given_column);
		}
		#pragma omp section
		{
			rank1 = given_row;
			rank2 = given_column;
		}
	}
};
//
//
//
inline void resize(const unsigned int &given_row,
                   const unsigned int &given_column,
                   const unsigned int &given_1st_layer)
{
	switch(rank1 == given_row
	       && rank2 == given_column
	       && rank3 == given_1st_layer)
	{
		case true: return;
	}
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			delete_array();
			init_3d_array(given_row,
			              given_column,
			              given_1st_layer);
		}
		#pragma omp section
		{
			rank1 = given_row;
			rank2 = given_column;
			rank3 = given_1st_layer;
		}
	}
};
//
//
//
inline void resize(const unsigned int &given_row,
                   const unsigned int &given_column,
                   const unsigned int &given_1st_layer,
                   const unsigned int &given_2nd_layer)
{
	switch(rank1 == given_row
	       && rank2 == given_column
	       && rank3 == given_1st_layer
	       && rank4 == given_2nd_layer)
	{
		case true: return;
	}
	#pragma omp sections nowait
	{
		#pragma omp section
		{
			delete_array();
			init_4d_array(given_row,
			              given_column,
			              given_1st_layer,
			              given_2nd_layer);
		}
		#pragma omp section
		{
			rank1 = given_row;
			rank2 = given_column;
			rank3 = given_1st_layer;
			rank4 = given_2nd_layer;
		}
	}
};
