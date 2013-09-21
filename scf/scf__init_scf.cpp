#include "scf.hpp"
//
//
//
void algorithm::scf::init_scf(array &h_matrix, array &s_matrix, array &two_electrons_v, settings &runtime_setup)
{
    config = &runtime_setup;
    roothaan_equation_solver(h_matrix, s_matrix, two_electrons_v);
}
