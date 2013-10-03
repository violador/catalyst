#include "scf.hpp"
//
//
//
bool algorithm::scf::check_convergence()
{ 
    tools get;
    if(get.module(scf_energy.array::get(iteration), scf_energy.array::get(iteration - 1)) > (config -> scf_convergence_criteria()))
    {
        scf_converged = false;
        return scf_converged;
    }
    else
    {
        scf_converged = true;
        report_scf_iterations();
        return scf_converged;
    }
}
