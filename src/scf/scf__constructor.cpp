#include "scf.hpp"
//
//
//
algorithm::scf::scf() 
{
    global_log::file.write_debug_msg("algorithm::scf::scf(): Any input data was given!");
    config = &global_settings::config;
    scf_converged = false;
    iteration = 1;
}
//
//
//
algorithm::scf::scf(array &h_matrix, array &s_matrix, array &v_matrix)
{
    global_log::file.write_debug_msg("algorithm::scf::scf(): Invoking init()");
    config = &global_settings::config;
    scf_converged = false;
    iteration = 1;
    init(h_matrix, s_matrix, v_matrix);
}
