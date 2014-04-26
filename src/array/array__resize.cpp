//
//
//
inline void resize(const unsigned int &given_row)
{
	switch(sizeof_row == given_row)
	{
		case true: return; break;
	}
	delete_array();
	init_1d_array(given_row);
	sizeof_row = given_row;
};
//
//
//
inline void resize(const unsigned int &given_row,
                   const unsigned int &given_column)
{
	switch(sizeof_row == given_row
	       && sizeof_column == given_column)
	{
		case true: return; break;
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
			sizeof_row = given_row;
			sizeof_column = given_column;
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
	switch(sizeof_row == given_row
	       && sizeof_column == given_column
	       && sizeof_1st_layer == given_1st_layer)
	{
		case true: return; break;
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
			sizeof_row = given_row;
			sizeof_column = given_column;
			sizeof_1st_layer = given_1st_layer;
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
	switch(sizeof_row == given_row
	       && sizeof_column == given_column
	       && sizeof_1st_layer == given_1st_layer
	       && sizeof_2nd_layer == given_2nd_layer)
	{
		case true: return; break;
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
			sizeof_row = given_row;
			sizeof_column = given_column;
			sizeof_1st_layer = given_1st_layer;
			sizeof_2nd_layer = given_2nd_layer;
		}
	}
};
