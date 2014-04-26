//
//
//
/// @brief Defines a new iterator value if given in the valid range
///        between 1 and the current set size. To check the current
///        set size see the basis_set::size() member function.
//
/// @return None.
//
inline void operator ()(const unsigned int &new_iter)
{
	switch(new_iter <= current_set_size)
	{
		case true: iter = new_iter;
	}
};
