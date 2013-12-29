//
//
//
inline double binomial_coeff(const int &a, 
                             const int &b)
{
    return factorial(b)/(factorial(a)*factorial(b - a));
};
