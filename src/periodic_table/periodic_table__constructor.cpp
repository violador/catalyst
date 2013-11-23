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
periodic_table::periodic_table(const unsigned int &given_element)
{
    init_data();
    database(given_element);
}
//
//
//
periodic_table::periodic_table(const unsigned int &given_level, const unsigned int &given_element)
{
//
/*
    global_log::file.write_debug_msg("periodic_table::periodic_table(): Level of theory = ",
                                     given_level,
                                     ", requested element = ",
                                     given_element);
*/
//
    switch((given_element >= 1) and (given_element <= total_elements))
    {
        case true:
        init_data();
        #pragma omp parallel sections num_threads(5)
        {
            #pragma omp section
            {
                switch(given_level)
                {
                    case STO3G: sto3g_exponent_database(given_element); break;
                }
            }
            #pragma omp section
            {
                switch(given_level)
                {
                    case STO3G: sto3g_coefficient_database(given_element); break;
                }
            }
            #pragma omp section
            {
                switch(given_level)
                {
                    case STO3G: total_functions = sto3g_set_size(given_element); break;
                }
            }
            #pragma omp section
            {
                database(given_element);
            }
            #pragma omp section
            {
                basis_database_ready = true;
                current_level = given_level;
            }
        }
        break;
    }
}
