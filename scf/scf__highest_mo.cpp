#include "scf.hpp"
//
//
//
unsigned int algorithm::scf::highest_mo() 
{
    if(scf_converged)
    {
        return f_eigenvalues.get_max_index();
    }
    {
        return 0;
    }
}
