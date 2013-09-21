#include "scf.hpp"
//
//
//
unsigned int algorithm::scf::lowest_mo() 
{
    if(scf_converged)
    {
        return f_eigenvalues.get_min_index();
    }
    {
        return 0;
    }
}
