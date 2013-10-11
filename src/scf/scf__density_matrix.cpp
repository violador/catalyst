#include "scf.hpp"
//
//
//
double algorithm::scf::density_matrix(const unsigned int &i, const unsigned int &j) 
{
    if((i > 0) && (i <= p_matrix.size_of_row()) && (j > 0) && (j <= p_matrix.size_of_column()))
    {
        return p_matrix.get(i, j);
    }
    else
    {
        return 0.0;
    }
}
