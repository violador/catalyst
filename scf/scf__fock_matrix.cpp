#include "scf.hpp"
//
//
//
double algorithm::scf::fock_matrix(const unsigned int &i, const unsigned int &j) 
{
    if((i > 0) && (i <= f_matrix.size_of_row()) && (j > 0) && (j <= f_matrix.size_of_column()))
    {
        return f_matrix.get(i, j);
    }
    else
    {
        return 0.0;
    }
}
