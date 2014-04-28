#include "array.hpp"
//
//
//
/// @brief A help function used to reset the internal properties.
//
/// @return None.
//
void array::reset_properties()
{
	rank1 = 0;
	rank2 = 0;
	rank3 = 0;
	rank4 = 0;
	constant = false;
	name = "";
	config = &global_settings::config;
}
//
//
//
/// @brief A help function used to reset the internal properties.
//
/// @return None.
//
void array::reset_properties(const unsigned int &row_size)
{
	rank1 = row_size;
	rank2 = 0;
	rank3 = 0;
	rank4 = 0;
	constant = false;
	name = "";
	config = &global_settings::config;
}
//
//
//
/// @brief A help function used to reset the internal properties.
//
/// @return None.
//
void array::reset_properties(const unsigned int &row_size,
                             const unsigned int &column_size)
{
	rank1 = row_size;
	rank2 = column_size;
	rank3 = 0;
	rank4 = 0;
	constant = false;
	name = "";
	config = &global_settings::config;
}
//
//
//
/// @brief A help function used to reset the internal properties.
//
/// @return None.
//
void array::reset_properties(const unsigned int &row_size,
                             const unsigned int &column_size,
                             const unsigned int &layer_size)
{
	rank1 = row_size;
	rank2 = column_size;
	rank3 = layer_size;
	rank4 = 0;
	constant = false;
	name = "";
	config = &global_settings::config;
}
//
//
//
/// @brief A help function used to reset the internal properties.
//
/// @return None.
//
void array::reset_properties(const unsigned int &row_size,
                             const unsigned int &column_size,
                             const unsigned int &layer1_size,
                             const unsigned int &layer2_size)
{
	rank1 = row_size;
	rank2 = column_size;
	rank3 = layer1_size;
	rank4 = layer2_size;
	constant = false;
	name = "";
	config = &global_settings::config;
}
