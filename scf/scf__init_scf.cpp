#include "scf.hpp"
//
//
//
void algorithm::scf::init(array &h_matrix, array &s_matrix, array &two_electrons_v, settings &runtime_setup)
{
    if(runtime_setup.settings::state_of(DEBUG_MODE))
    {
         global_log::file.write("@algorithm::scf::init()");
    }
    config = &runtime_setup;
    roothaan_equation_solver(h_matrix, s_matrix, two_electrons_v);
}
