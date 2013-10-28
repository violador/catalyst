//
//
//
inline void gf_midpoint(double &i_distance,
                        double &j_distance,
                        const double &i_exp,
                        const double &j_exp,
                        const double &ij_distance)
{
    i_distance = j_exp*ij_distance/(i_exp + j_exp);
    j_distance = ij_distance - i_distance;
};
