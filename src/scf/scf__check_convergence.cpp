#include "scf.hpp"
//
//
//
bool algorithm::scf::check_convergence()
{ 
    tools get;
    switch(get.module(scf_energy[iteration], scf_energy[iteration - 1]) > config -> scf_convergence_criteria())
    {
        case false:
        {
            scf_converged = false;
            return scf_converged;
        }
        break;
        case true:
        {
            scf_converged = true;
            report_scf_iterations();
            return scf_converged;
        }
        break;
    }
}
