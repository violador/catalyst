#include "scf.hpp"
//
//
//
double algorithm::scf::energy() 
{
    return scf_energy.get(iteration);
}
//
//
//
double algorithm::scf::energy(const unsigned int &scf_iteration)
{
    return scf_energy.get(scf_iteration);
} 
