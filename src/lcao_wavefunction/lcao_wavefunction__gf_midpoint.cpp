//
//
//
inline void gf_midpoint(double &i_distance,
                        double &j_distance,
                        const double &a, // The m gf exponent.
                        const double &b, // The n gf exponent.
                        const double &c) // The i-j atomic distance.
{
    i_distance = b*c/(a + b);
    j_distance = c - i_distance;
};
