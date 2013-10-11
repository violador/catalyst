#include "scf.hpp"
//
//
//
void algorithm::scf::init(array &h_matrix, array &s_matrix, array &two_electrons_v, settings &runtime_setup)
{
    global_log::file.write_debug_msg("algorithm::scf::init()");
    config = &runtime_setup;
    roothaan_equation_solver(h_matrix, s_matrix, two_electrons_v);
}
