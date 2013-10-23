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
periodic_table::periodic_table(const unsigned int &given_theory_level, const unsigned int &given_element)
{
    switch((given_element >= 1) and (given_element <= total_elements))
    {
        case true:
        init_data();
        basis_database_ready = true;
        #pragma omp parallel sections num_threads(4)
        {
            #pragma omp section
            {
                switch(given_theory_level)
                {
                    case 1: sto3g_exponent_database(given_element); break;
                  //case 2: sto2g_exponent_database(given_element); break;
                  //case 3: sto1g_exponent_database(given_element); break;
                }
            }
            #pragma omp section
            {
                switch(given_theory_level)
                {
                    case 1: sto3g_coefficient_database(given_element); break;
                  //case 2: sto2g_coefficient_database(given_element); break;
                  //case 3: sto1g_coefficient_database(given_element); break;
                }
            }
            #pragma omp section
            {
                switch(given_theory_level)
                {
                    case 1: total_functions = sto3g_set_size(given_element); break;
                }
            }
            #pragma omp section
            {
                database(given_element);
            }
        }
        break;
    }
}
