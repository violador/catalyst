//
//
//
/// @param [in] row_size The desired size of row.
//
/// @brief Works on deleted arrays only and creates a 1D array of
///        @c row_size length initialized to zero by default.
//
/// @return None.
//
inline void create_array(const unsigned int &row_size)
{
	switch(deleted_array)
	{
		case true:
		deleted_array = false;
		sizeof_row = row_size;
		init_1d_array(row_size);
		break;
	}
};
//
//
//
/// @param [in] row_size The desired number of rows.
//
/// @param [in] column_size The desired number of columns.
//
/// @brief Works on deleted arrays only and creates a 2D array of
///        @c row_size \times @c column_size length initialized to
///        zero by default.
//
/// @return None.
//
inline void create_array(const unsigned int &row_size,
						 const unsigned int &column_size)
{
//
/// @note Notice that if @c row_size = @c column_size the private
///       is_square_array data member is turned @c true.
//
	switch(deleted_array)
	{
		case true:
		deleted_array = false;
		sizeof_row = row_size;
		sizeof_column = column_size;
		init_2d_array(row_size, column_size);
		row_size == column_size? is_square_array = true : is_square_array = false;
		break;
	}
};
//
//
//
/// @param [in] row_size The desired number of rows.
//
/// @param [in] column_size The desired number of columns.
//
/// @param [in] layer_size The desired number of layers.
//
/// @brief Works on deleted arrays only and creates a 3D array of
///        @c row_size \times @c column_size \times @c layer_size
///        length initialized to zero by default.
//
/// @return None.
//
inline void create_array(const unsigned int &row_size,
						 const unsigned int &column_size,
						 const unsigned int &layer_size)
{
	switch(deleted_array)
	{
		case true:
		deleted_array = false;
		sizeof_row = row_size;
		sizeof_column = column_size;
		sizeof_1st_layer = layer_size;
		init_3d_array(row_size, column_size, layer_size);
		break;
	}
};
//
//
//
/// @param [in] row_size The desired number of rows.
//
/// @param [in] column_size The desired number of columns.
//
/// @param [in] layer1_size The desired number of first layers.
//
/// @param [in] layer2_size The desired number of second layers.
//
/// @brief Works on deleted arrays only and creates a 4D array of
///        @c row_size \times @c column_size \times @c layer1_size
///        \times layer2_size length initialized to zero by default.
//
/// @return None.
//
inline void create_array(const unsigned int &row_size,
						 const unsigned int &column_size,
						 const unsigned int &layer1_size,
						 const unsigned int &layer2_size)
{
	switch(deleted_array)
	{
		case true:
		deleted_array = false;
		sizeof_row = row_size;
		sizeof_column = column_size;
		sizeof_1st_layer = layer1_size;
		sizeof_2nd_layer = layer2_size;
		init_4d_array(row_size, column_size, layer1_size, layer2_size);
		break;
	}
};
