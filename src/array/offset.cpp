//
//
//
/// @param [in] i The i-th element of the first rank.
//
/// @brief A help function used to calculate the real position, i.e. 
///        the offset, of a given element in a rank 1 array in the 
///        @c data member.
//
/// @return @f$ := i - 1 @f$
//
inline unsigned int offset(const unsigned int &i) const
{
	return (i - 1);
};
//
//
//
/// @param [in] i The i-th element of the first rank.
//
/// @param [in] j The j-th element of the second rank.
//
/// @brief A help function used to calculate the real position, i.e. 
///        the offset, of a given element in a rank 2 array in the 
///        @c data member.
//
/// @return @f$ := i - 1 @f$
//
inline unsigned int offset(const unsigned int &i, 
                           const unsigned int &j) const
{
	return ((i - 1)*rank1 + (j - 1));
};
