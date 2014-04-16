//
//
//
/// @brief Checks if the current basis set was properly initialized.
//
/// @return @c true if the current basis set was properly
///         initialized and @c false otherwise.
//
inline bool ready()
{
	return bool(coeff not_eq NULL and expon not_eq NULL);
};
