#include "scf.hpp"
//
//
//
algorithm::scf::scf() 
{
    scf_converged = false;
    iteration = 0;
}
//
//
//
algorithm::scf::scf(array &h_matrix, array &s_matrix, array &two_electrons_interaction, settings &runtime_setup)
{
    if(runtime_setup.settings::state_of(DEBUG_MODE))
    {
         global_log::file.write("@algorithm::scf::scf()");
         global_log::file.write("@algorithm::scf::scf(): Invoking init()");
    }
    scf_converged = false;
    iteration = 0;
    init(h_matrix, s_matrix, two_electrons_interaction, runtime_setup);
}
