#include "periodic_table.hpp"
//
//
//
periodic_table::periodic_table()
{
    element_symbol = "";
    element_name = "";
    element_config = "";
    element_core_electrons = 0;
    element_valence_electrons = 0;
    element_mass = 0.0;
    covalent_radius = 0.0;
}
//
//
//
periodic_table::periodic_table(unsigned int &wavefunction_type, unsigned int &element)
{
    #pragma omp parallel sections num_threads(3)
    {
        #pragma omp section
        {
            switch(wavefunction_type)
            {
                case 1: sto3g_exponent_database(element); break;
            }
        }
        #pragma omp section
        {
            switch(wavefunction_type)
            {
                case 1: /*sto3g_coefficient_database(element);*/ break;
            }
        }
        #pragma omp section
        {
            switch(wavefunction_type)
            {
                case 1: total_functions = sto3g_total_functions(element); break;
            }
        }
        #pragma omp section
        {
            database(element);
        }
    }
}
