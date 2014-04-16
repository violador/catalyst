//
//
//
/// @param [in] a An integer number.
//
/// @param [in] b An integer number.
//
/// @brief Calculates the binomial coefficient, @f$ \frac{b!}{a!(b - a)!} @f$.
//
/// @return @f$ \frac{b!}{a!(b - a)!} @f$.
//
inline double binomial_coeff(const int &a,
							 const int &b)
{
	return factorial(b)/(factorial(a)*factorial(b - a));
};
