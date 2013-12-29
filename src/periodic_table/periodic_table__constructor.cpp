#include "periodic_table.hpp"
//
//
//
periodic_table::periodic_table()
{
    init_data();
}
//
//
//
periodic_table::periodic_table(const unsigned int &element)
{
    init_data();
    database(element);
}
//
//
//
periodic_table::periodic_table(const unsigned int &level, 
                               const unsigned int &element)
{
//
/*
    global_log::file.write_debug_msg("periodic_table::periodic_table(): Level of theory = ",
                                     level,
                                     ", requested element = ",
                                     element);
*/
//
    switch((element >= 1) and (element <= total_elements))
    {
        case true:
        init_data();
        #pragma omp parallel sections num_threads(5)
        {
            #pragma omp section
            {
                switch(level)
                {
                    case STO3G: sto3g_exponent_database(element); break;
                }
            }
            #pragma omp section
            {
                switch(level)
                {
                    case STO3G: sto3g_coefficient_database(element); break;
                }
            }
            #pragma omp section
            {
                switch(level)
                {
                    case STO3G: total_functions = sto3g_set_size(element); break;
                }
            }
            #pragma omp section
            {
                database(element);
            }
            #pragma omp section
            {
                basis_database_ready = true;
                current_level = level;
            }
        }
        break;
    }
}
