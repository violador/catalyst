//
//
//
inline double binomial_coeff(const int &a, const int &b)
{
    return factorial_of(b)/(factorial_of(a)*factorial_of(b - a));
};
