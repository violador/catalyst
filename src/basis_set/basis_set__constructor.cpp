#include "basis_set.hpp"
//
//
//
basis_set::basis_set(const unsigned int &element, 
                     const unsigned int &level): current_element(element),
                                                 current_level(level),
                                                 current_set_size(init_set_size()),
                                                 coeff(NULL),
                                                 expon(NULL)
{
    switch(current_level)
    {
        case basis::STO_3G:
        {
            #pragma omp parallel sections num_threads(2)
            {
                #pragma omp section
                {
                    init_sto3g_coeff();
                }
                #pragma omp section
                {
                    init_sto3g_expon();
                }
            }
        }
        break;
    }
}
