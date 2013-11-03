//
//
//
inline double gf_product(const double &a, // The m-th gf exponent.
                         const double &b, // The n-th gf exponent.
                         const double &c, // The i-th atomic position onto one axis.
                         const double &d) // The j-th atomic position onto one axis.
{
    return (a*c + b*d)/(a + b);
};
