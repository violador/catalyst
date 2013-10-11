#include "molecular_system.hpp"
//
//
//
double molecular_system::ab_initio_energy()
{
    if(ab_initio_ready)
    {
        return 0.0;
    }
    else
    {
        // Call lcao_wavefunction
        return 0.0;
    }
}
