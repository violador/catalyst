//
//
//
/// @param [in] row The desired size of row.
//
/// @brief Works on deleted arrays only and creates a 1D array of
///        @c row length initialized to zero by default.
//
/// @return None.
//
inline void create_array(const unsigned int &row)
{
	switch(is_deleted())
	{
		case true:
		//is_deleted() = false;
		sizeof_row = row;
		init_1d_array(row);
		return;
	}
};
//
//
//
/// @param [in] row The desired number of rows.
//
/// @param [in] column The desired number of columns.
//
/// @brief Works on deleted arrays only and creates a 2D array of
///        @c row \times @c column length initialized to zero by
///        default.
//
/// @return None.
//
inline void create_array(const unsigned int &row,
                         const unsigned int &column)
{
	switch(is_deleted())
	{
		case true:
		//is_deleted() = false;
		sizeof_row = row;
		sizeof_column = column;
		init_2d_array(row, column);
		//row == column? is_square_array = true : is_square_array = false;
		return;
	}
};
//
//
//
/// @param [in] row The desired number of rows.
//
/// @param [in] column The desired number of columns.
//
/// @param [in] layer The desired number of layers.
//
/// @brief Works on deleted arrays only and creates a 3D array of
///        @c row \times @c column \times @c layer length initialized
///        to zero by default.
//
/// @return None.
//
inline void create_array(const unsigned int &row,
                         const unsigned int &column,
                         const unsigned int &layer)
{
	switch(is_deleted())
	{
		case true:
		//is_deleted() = false;
		sizeof_row = row;
		sizeof_column = column;
		sizeof_1st_layer = layer;
		init_3d_array(row, column, layer);
		return;
	}
};
//
//
//
/// @param [in] row The desired number of rows.
//
/// @param [in] column The desired number of columns.
//
/// @param [in] layer1 The desired number of first layers.
//
/// @param [in] layer2 The desired number of second layers.
//
/// @brief Works on deleted arrays only and creates a 4D array of
///        @c row \times @c column \times @c layer1 \times layer2
///        length initialized to zero by default.
//
/// @return None.
//
inline void create_array(const unsigned int &row,
                         const unsigned int &column,
                         const unsigned int &layer1,
                         const unsigned int &layer2)
{
	switch(is_deleted())
	{
		case true:
		//is_deleted() = false;
		sizeof_row = row;
		sizeof_column = column;
		sizeof_1st_layer = layer1;
		sizeof_2nd_layer = layer2;
		init_4d_array(row, column, layer1, layer2);
		return;
	}
};
