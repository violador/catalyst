//
//
//
/// @brief Defines a new iterator value if given in the
///        valid range between 1 and the current set size.
//
/// @return None.
//
inline void set_iterator(const unsigned int &new_iter)
{
	switch(new_iter <= current_set_size)
	{
		case true: iter = new_iter; break;
	}
};
