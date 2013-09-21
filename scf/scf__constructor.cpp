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
algorithm::scf::scf(settings &runtime_setup)
{
    config = &runtime_setup;
    scf_converged = false;
    iteration = 0;
}
//
//
//
algorithm::scf::scf(array &h_matrix, array &s_matrix, array &two_electrons_interaction, settings &runtime_setup)
{
    config = &runtime_setup;
    scf_converged = false;
    iteration = 0;
    roothaan_equation_solver(h_matrix, s_matrix, two_electrons_interaction);
}
