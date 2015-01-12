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
constexpr unsigned int offset(unsigned int i) const
{
	return (--i);
};
//
//
//
/// @param [in] i The i-th element of the first rank.
//
/// @param [in] j The j-th element of the second rank.
//
/// @brief A private function used to calculate the real position, of a given element
/// in a rank 2 array in the @c data member. Using matrix notation, a position is
/// calculated by setting a row, and running over all the columns until the maximum
/// number of columns.
//
/// @return A nonnegative integer number.
//
constexpr unsigned int offset(unsigned int i, unsigned int j) const
{
	return ((--i)*second_rank() + (--j));
};
//
//
//
constexpr unsigned int offset(unsigned int i, unsigned int j, unsigned int p) const
{
	--i; --j; --p;
	return ((i*second_rank() + j)*(first_rank() + p));
};
//
//
//
constexpr unsigned int offset(unsigned int i, unsigned int j, unsigned int p, unsigned int q) const
{
	--i; --j; --p; --q;
	return (((i*third_rank() + j)*(second_rank() + p))*(first_rank() + q));
};
