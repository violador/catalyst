//
//
//
/// @param [in] element The number of the desired chemical element.
//
/// @brief Changes the current element and update the internal data.
//
/// @return None.
//
inline void init(const unsigned int &element)
{
	current_element = element;
	update_data();
};
//
//
//
/// @param [in] element The symbol of the desired chemical element.
//
/// @brief Changes the current element and update the internal data.
//
/// @return None.
//
inline void init(const std::string &element)
{
	current_element = 0;
	do
	{
		++current_element;
		update_data();
	}
	while(element.std::string::compare(current_symbol) not_eq 0);
};
