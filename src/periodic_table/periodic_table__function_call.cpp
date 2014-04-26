//
//
//
/// @param [in] element The number of the desired chemical element.
//
/// @brief Changes the current element and updates the internal data.
//
/// @return None.
//
inline void operator ()(const unsigned int &element)
{
	switch(element <= table_length)
	{
		case true:
		current_element = element;
		update_data();
		return;
	}
};
